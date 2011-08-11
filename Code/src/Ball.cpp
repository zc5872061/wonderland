/*
 * Ball.cpp
 *
 *  Created on: 2010-12-08
 *      Author: artur.m
 */

#include "Ball.h"

#include "Game.h"

#include "Board.h"

shared_ptr<Ball> Ball::spawn(const Vector& position, Color color)
{
    return Actor::initialize(new Ball(position, color));
}

const std::string Ball::TYPE("Ball");
const std::string Ball::STATE_FALLING_NAME("StateFalling");
const std::string Ball::STATE_WAITING_NAME("StateWaiting");
const std::string Ball::STATE_DISAPPERING_NAME("StateDisappearing");
const std::string Ball::MESH_NAME("Sphere01Mesh");

Ball* Ball::selectedBall(null);

Board* Ball::s_board(null);

void Ball::selectionChanged()
{
	if(s_board == null)
	{
		GameController::ActorsContainer board;
		Game::getInstance().getGameController()->getActors("Board", board);
		assert(board.size() == 1);
		s_board = static_cast<Board*>(board[0].get()); // this sucks unfortunately, because there is no possibility to retrieve the correct shared_ptr now
	}
	s_board->selectionChanged();
}

void Ball::deselectBall()
{
	if(selectedBall)
	{
		selectedBall->setSelected(false);
	}
}

Ball::Ball(const Vector& position, Color color) :
	Actor(position),
	m_selected(false),
	m_ballColor(BALL_ENUM_SIZE),
	m_elapsedTime(0),
	m_ambientColor(0.1f, 0.1f, 0.1f),
	m_stateFalling(this),
	m_stateWaiting(this),
	m_stateDisappearing(this)
{
	registerState(&m_stateFalling, STATE_FALLING_NAME);
	registerState(&m_stateWaiting, STATE_WAITING_NAME);
	registerState(&m_stateDisappearing, STATE_DISAPPERING_NAME);
	setScale(0.15f);
	getModel().addElement("ballMesh", MESH_NAME);
    setBallColor(color);
    MaterialInstance* ownMaterial = getModel().getElement()->getMaterialInstance();
    ownMaterial->setMaterialName("basic");
    ownMaterial->setValue("u_diffuseColor", m_color);
    ownMaterial->setValue("u_ambientColor", m_ambientColor);
    ownMaterial->setValue("u_fresnelAmount", 0.3f);
}

Ball::~Ball()
{

}

void Ball::update(int milis)
{
	if(!m_selected)
	{
		return;
	}
	m_animationMove.z = 1.5f * sinf(static_cast<float>(m_elapsedTime)/150);
	if(m_animationMove.z < 0)
	{
		m_animationMove.z *= -1;
	}
	m_elapsedTime += milis;
}

Vector Ball::getPosition() const
{
	return m_position + m_animationMove;
}

void Ball::released(const Actor* target, const Vector& touchPoint)
{
	if(target != this)
	{
		if(target->getType() == Ball::TYPE)
		{
			setSelected(false);
		}
		return;
	}
	setSelected(!isSelected());
}

void Ball::setSelected(bool value)
{
	m_selected = value;
	if(value == true)
	{
		if(selectedBall)
		{
			selectedBall->setSelected(false);
		}
		selectedBall = this;
		selectionChanged();
	}
	else
	{
		if(selectedBall == this)
		{
			selectedBall = null;
			selectionChanged();
		}
	}
    getModel().getElement()->getMaterialInstance()->setValue("u_fresnelAmount", m_selected ? 1.0f : 0.3f);
}

bool Ball::isSelected() const
{
	return m_selected;
}

void Ball::setBallColor(Color color)
{
	static const Vector colors[] = {
			Vector(0.3f,  0.3f,  0.9f),
			Vector(0.9f,  0,     0),
			Vector(0.2f,  0.8f,  0.2f),
			Vector(0.95f, 0.95f,  0),
			Vector(0.95f, 0,     0.7f),
			Vector(0.15f, 0.75f, 0.6f),
			Vector(0.8f,  0.8f,  0.8f),
			Vector(0.2f,  0.2f,  0.2f),
			Vector(0.6f,  0.9f,  0.04f),
			};
	m_ballColor = color;
	setColor(colors[m_ballColor]);
}

Ball::Color Ball::getBallColor() const
{
	return m_ballColor;
}

std::string Ball::getType() const
{
	return TYPE;
}

void Ball::setColor(const Vector& color)
{
    m_color = color;
    getModel().getElement()->getMaterialInstance()->setValue("u_diffuseColor", color);
}

// ----- States' code

const float FallingState::ACCELERATION(20.81f);
const float FallingState::START_HEIGHT(11);

FallingState::FallingState(Ball* ball) :
		m_ball(ball),
		m_speed(0),
		m_height(START_HEIGHT)
{

}

void FallingState::update(int milis)
{
	m_speed -= static_cast<float>(milis) * 0.001f * ACCELERATION;
	m_height += m_speed * milis * 0.001f;
	if(m_height <= 0)
	{
		Vector newPos = m_ball->getPosition();
		newPos.z = m_startBallPos.z;
		m_ball->setPosition(newPos);
		m_ball->goToState(Ball::STATE_WAITING_NAME);
	}
	Vector newBallPos(m_ball->getPosition());
	newBallPos.z = m_startBallPos.z + m_height;
	m_ball->setPosition(newBallPos);
}

void FallingState::stateEntered()
{
	m_ball->ignoreTrace(true);
	m_startBallPos = m_ball->getPosition();
	update(0);
}

void FallingState::stateEnded()
{
	m_ball->ignoreTrace(false);
}

WaitingState::WaitingState(Ball* ball) :
		m_ball(ball)
{

}

void WaitingState::stateEntered()
{
	m_ball->ignoreTrace(true);
}

void WaitingState::stateEnded()
{
	m_ball->ignoreTrace(false);
}

const GLfloat DisappearingState::MIN_SIZE(0.01f);
const GLfloat DisappearingState::EXP(0.2f);

DisappearingState::DisappearingState(Ball* ball) :
	m_ball(ball)
{

}

void DisappearingState::stateEntered()
{
	m_ball->ignoreTrace(true);
}

void DisappearingState::stateEnded()
{
}

void DisappearingState::update(int milis)
{
	GLfloat scale = m_ball->getScale();
	scale *= expf(-static_cast<GLfloat>(milis) * 0.001f / EXP);
	if(scale < MIN_SIZE)
	{
        Actor::destroy(m_ball);
        return;
	}
	m_ball->setScale(scale);
}

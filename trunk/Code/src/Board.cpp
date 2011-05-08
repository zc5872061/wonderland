/*
 * Board.cpp
 *
 *  Created on: 2010-12-08
 *      Author: artur.m
 */


#include "Board.h"
#include "Game.h"
#include "GameBitmap.h"


const GLfloat Board::SIDE_SIZE(10);
const GLfloat Board::HEIGHT_ABOVE(0.5f);
const std::string Board::TYPE("Board");

shared_ptr<Board> Board::spawn(const Vector& position)
{
    return Actor::initialize(new Board(position));
}

Board::Board(const Vector& position) :
		Actor(position),
		m_controller(this),
		m_boardModel(this)
{
	for(int i = 0; i < BoardModel::STARTING_COUNT; ++i)
	{
		m_controller.addRandomBall(m_controller.createRandomColorBall());
	}
	m_controller.prepareRandomBalls(Board::CREATING_COUNT);
	getModel().addElement("mesh", "planeMesh");
	getModel().getElement()->getMaterialInstance()->setMaterialName("textured");
    getModel().getElement()->getMaterialInstance()->setValue("u_textureSampler", "brick_512x512.png");
}

Board::~Board()
{

}

std::string Board::getType() const
{
	return TYPE;
}

void Board::update(int milis)
{

}

void Board::released(const Actor* target, const Vector& touchPoint)
{
	if(target != this)
	{
		return;
	}
	Log("Board was touched");

	GridInfo touched = getTouchedGrid(touchPoint.x, touchPoint.y);
	if(touched.x != -1 && touched.y != -1)
	{
		m_controller.pressedGrid(touched.x, touched.y);
	}
}

GridInfo Board::getTouchedGrid(GLfloat x, GLfloat y) const
{
	Vector tempTouchPoint(x, y, 0);
	tempTouchPoint -= getPosition();
	tempTouchPoint += Vector(SIDE_SIZE/2, SIDE_SIZE/2, 0);
	if(tempTouchPoint.x < 0 || tempTouchPoint.x > SIDE_SIZE)
	{
		return GridInfo(-1, -1);
	}
	if(tempTouchPoint.y < 0 || tempTouchPoint.y > SIDE_SIZE)
	{
		return GridInfo(-1, -1);
	}

	return GridInfo( (tempTouchPoint.x * BoardModel::COUNT) / SIDE_SIZE,
			(tempTouchPoint.y * BoardModel::COUNT) / SIDE_SIZE );
}

Vector Board::getPanelCenter(int x, int y) const
{
	Vector position = getPosition();
	Vector topLeftCenter(position.x - SIDE_SIZE * 0.5, position.y - SIDE_SIZE * 0.5, position.z);
	GLfloat panelSize = SIDE_SIZE / BoardModel::COUNT;
	topLeftCenter += Vector(0.5 * panelSize, 0.5 * panelSize, 0);

	Vector result(topLeftCenter.x + x*panelSize, topLeftCenter.y + y*panelSize, position.z);
	return result;
}

BoardController& Board::getController()
{
	return m_controller;
}

BoardModel& Board::getBoardModel()
{
	return m_boardModel;
}

void Board::selectionChanged()
{
	m_controller.selectionChanged();
}

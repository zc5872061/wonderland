/*
 * BallsGameController.cpp
 *
 *  Created on: 2010-12-16
 *      Author: artur.m
 */

#include "BallsGameController.h"

#include "pi.h"

#include "Game.h"
#include "Board.h"
#include "Ball.h"
#include "BallsHUD.h"
#include "Vector.h"
#include "BallsInformations.h"
#include "BlockButton.h"

BallsGameController::BallsGameController() :
	m_difficulty(GD_ENUM_SIZE),
	m_comboActive(false),
	m_points(0)
{

}

BallsGameController::~BallsGameController()
{

}

std::string BallsGameController::getClass() const
{
	return "BallsGameController";
}

void BallsGameController::setDifficulty(GameDifficulty difficulty)
{
	m_difficulty = difficulty;
}

BallsGameController::GameDifficulty BallsGameController::getDifficulty() const
{
	return m_difficulty;
}

int BallsGameController::getCurrentColorsCount() const
{
	switch(m_difficulty)
	{
		case GD_EASY:
		{
			return EASY_COLORS;
			break;
		}
		case GD_MEDIUM:
		{
			return MEDIUM_COLORS;
			break;
		}
		case GD_HARD:
		{
			return HARD_COLORS;
			break;
		}
		default:
		{
			Log("Unknown difficulty - %d in BallsGameController::getCurrentColorsCount", m_difficulty);
			assert(0);
		}
	}
	return GD_EASY; // just  to remove the warning
}

void BallsGameController::initialize()
{
	Game::getInstance().getMeshManager().getMesh(Ball::MESH_NAME); // load ball's mesh at startup

//    m_blockButton = BlockButton::spawn(Vector(0, 4, 0));
}

void BallsGameController::startGame()
{
	m_ballsInformations = BallsInformations::spawn(Vector(1, 0, 0), 4, Vector(2, 6, -2));

	m_board = Board::spawn(Vector(0, 0, -2));
}

unsigned int BallsGameController::getPoints() const
{
	return m_points;
}

void BallsGameController::addPoints(unsigned int disappearedBalls)
{
	unsigned int newPoints = 0;

	newPoints += 5;
	disappearedBalls -= 5;
	newPoints += 2*disappearedBalls;

	if(m_comboActive)
	{
		newPoints *= 2;
	}

	m_points += newPoints;
	static_cast<BallsHUD&>(Game::getInstance().getHUD()).updatePoints(m_points);
}

void BallsGameController::enableCombo(bool value)
{
	m_comboActive = true;
}

void BallsGameController::gameEnded()
{
	static_cast<BallsHUD&>(Game::getInstance().getHUD()).setState(BallsHUD::STATE_MAIN_NAME);
	ActorsContainer actors;
    
    Ball::deselectBall();
    
    m_ballsInformations.reset();
    m_board.reset();

	Game::getInstance().getGameController()->getActors(BallsInformations::TYPE, actors);
	Game::getInstance().getGameController()->getActors(Board::TYPE, actors);
	for(ActorsIter it = actors.begin(); it != actors.end(); ++it)
	{
        Actor::destroy(*it);
	}
	actors.clear();
}

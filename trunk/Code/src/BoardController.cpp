/*
 * BoardController.cpp
 *
 *  Created on: 2010-12-15
 *      Author: artur.m
 */

#include "BoardController.h"

#include <cstdlib>
#include <algorithm>

#include "Board.h"
#include "BoardModel.h"
#include "Game.h"
#include "BallsGameController.h"
#include "MathHelper.h"
#include "BallsHUD.h"
#include "BallsInformations.h"
#include "shared_ptr.h"

BoardController::BoardController(Board* board) :
	m_board(board),
	m_blocked(false),
	m_ballsInformations(null),
	m_animationCounter(this)
{
	m_ballsHUD = dynamic_cast<BallsHUD*>( &(Game::getInstance().getHUD()) );
	assert(m_ballsHUD);

	GameController::ActorsContainer informationsContainer;
	Game::getInstance().getGameController()->getActors(BallsInformations::TYPE, informationsContainer);
	assert(informationsContainer.size() != 0);
	m_ballsInformations = static_cast<BallsInformations*>(informationsContainer[0].get());
}

BoardController::~BoardController()
{
	removeLine();
    for(std::vector<shared_ptr<Ball> >::iterator it = m_preparedBalls.begin(); it != m_preparedBalls.end(); ++it)
    {
        Actor::destroy(*it);
    }
}

shared_ptr<Ball> BoardController::createRandomColorBall() const
{
//	Log("BoardController::createRandomColorBall");
	int colorsCount = static_cast<BallsGameController*>(Game::getInstance().getGameController())->getCurrentColorsCount();
	Ball::Color color = static_cast<Ball::Color>(rand() % colorsCount);
    return Ball::spawn(Vector(), color);
}

void BoardController::addRandomBall(shared_ptr<Ball> ball)
{
//	Log("BoardController::addRandomBall");
	BoardModel::GridInfoContainer tempGrids(m_board->getBoardModel().getFreeGrids());
	while(tempGrids.size() != 0)
	{
		GridInfo tempGrid = tempGrids[rand() % tempGrids.size()];
		if(m_board->getBoardModel().isValidToAdd(tempGrid.x, tempGrid.y, ball->getBallColor()))
		{
			m_board->getBoardModel().addBall(tempGrid.x, tempGrid.y, ball);
			Vector gridCenter = m_board->getPanelCenter(tempGrid.x, tempGrid.y);
			gridCenter.z += Board::HEIGHT_ABOVE;

			ball->setPosition(gridCenter);

			return;
		}
	}

	gameEnded();
}

void BoardController::pressedGrid(int x, int y)
{
	if(m_blocked)
	{
		return;
	}
	if(Ball::selectedBall == null)
	{
		return;
	}
	if(m_board->getBoardModel().getBallAt(x, y) != null)
	{
		m_board->getBoardModel().getBallAt(x, y)->setSelected(true);
		return; // it will be better just to return
//		// might happen in rare cases when user misses the ball with his touch
//		Ball* ballAbove = m_board->getBoardModel().getBallAt(x, y);
//		assert(ballAbove != null);
//		ballAbove->setSelected(!ballAbove->isSelected());
	}
	std::vector<Vector> path;
	GridInfo startGrid = m_board->getBoardModel().findGrid(Ball::selectedBall);

	blockInput();
	m_board->getBoardModel().getPath(startGrid.x, startGrid.y, x, y);
}

void BoardController::pathFound(const std::vector<Vector>& path)
{
	unblockInput();
	if(path.size()==0)
	{
		return;
	}

	removeLine();
	m_lineActor = LineActor::spawn(Vector(), path);
	m_lineActor->setColor(Ball::selectedBall->getColor());

	m_path = path;

	m_ballsHUD->enableAccept();
}

void BoardController::animationFinished(Actor* target)
{
	Log("Animation finished");
	std::vector<shared_ptr<Ball> > disappearing;
	if(target->getType() != Ball::TYPE)
	{
		Log("Not a ball but a %s", target->getType().c_str());
		return;
	}
	Ball* ball = static_cast<Ball*>(target);
	Log("Board controller, line 133");
	GridInfo grid = m_board->getBoardModel().findGrid(ball);

	m_board->getBoardModel().checkDisappearing(grid.x, grid.y, disappearing);

	if(disappearing.size() != 0)
	{
		for(std::vector<shared_ptr<Ball> >::iterator it = disappearing.begin(); it != disappearing.end(); ++it)
		{
			GridInfo ballGrid = m_board->getBoardModel().findGrid(it->get());
			m_board->getBoardModel().removeBall(ballGrid.x, ballGrid.y);
			(*it)->goToState(Ball::STATE_DISAPPERING_NAME);
		}
		BallsGameController* gameController = static_cast<BallsGameController*>(Game::getInstance().getGameController());
		gameController->addPoints(disappearing.size());
		gameController->enableCombo(true);
	}
	else
	{
		if(!movePreparedBalls())
		{
			gameEnded();
			return;
		}
		prepareRandomBalls(Board::CREATING_COUNT);
		static_cast<BallsGameController*>(Game::getInstance().getGameController())->enableCombo(false);
	}

	unblockInput();
}

void BoardController::blockInput()
{
	m_blocked = true;
}

void BoardController::unblockInput()
{
	m_blocked = false;
}

void BoardController::acceptMove()
{
	assert(m_path.size() != 0);

	GridInfo startGrid = m_board->getTouchedGrid(m_path[0].x, m_path[0].y);
	GridInfo endGrid = m_board->getTouchedGrid(m_path[m_path.size()-1].x, m_path[m_path.size()-1].y);

	blockInput();
	int animationTime = Board::BALL_SINGLE_BRICK_TIME * (m_path.size() - 1); // -1 because there is the start point in the container
	Game::getInstance().getPhysicsEngine().bindAnimation(Game::getInstance().getGameController()->getActorPtr(Ball::selectedBall), std::auto_ptr<AnimCurve>(new AnimCurve(m_path, 0, animationTime)), this);
	m_board->getBoardModel().moveBall(startGrid, endGrid);

	Ball::selectedBall->setSelected(false);

	m_path.clear();
	m_ballsHUD->disableAccept();
	removeLine();
	m_lineActor.reset();
}

void BoardController::prepareRandomBalls(int count)
{
	BallsInformations::LocationsContainer locations = m_ballsInformations->getLocations();
	for(int i = 0; i < count; ++i)
	{
		shared_ptr<Ball> newBall = createRandomColorBall();
		newBall->setPosition(locations[i]);
		newBall->goToState(Ball::STATE_FALLING_NAME);
		m_preparedBalls.push_back(newBall);
	}
}

bool BoardController::movePreparedBalls()
{
	m_animationCounter.reset(m_preparedBalls.size());
	for(std::vector<shared_ptr<Ball> >::iterator it = m_preparedBalls.begin(); it != m_preparedBalls.end(); ++it)
	{
		m_animationCounter.addWatched(it->get());

		shared_ptr<Ball> ball = *it;

		BoardModel::GridInfoContainer tempGrids(m_board->getBoardModel().getFreeGrids());
		while(tempGrids.size() != 0)
		{
			GridInfo tempGrid = tempGrids[rand() % tempGrids.size()];
			if(m_board->getBoardModel().isValidToAdd(tempGrid.x, tempGrid.y, ball->getBallColor()))
			{
				m_board->getBoardModel().addBall(tempGrid.x, tempGrid.y, ball);
				Vector gridCenter = m_board->getPanelCenter(tempGrid.x, tempGrid.y);
				gridCenter.z += Board::HEIGHT_ABOVE;

				std::vector<Vector> path;
				path.push_back(ball->getPosition());
				path.push_back(gridCenter);
				Game::getInstance().getPhysicsEngine().bindAnimation(ball, std::auto_ptr<AnimCurve>(new AnimCurve(path, 0, 200)), &m_animationCounter);

				break;
			}
		}
	}
	// Check if the game should not finish
	BoardModel::GridInfoContainer tempGrids(m_board->getBoardModel().getFreeGrids());
	if(tempGrids.size() == 0)
	{
		return false;
	}

	m_preparedBalls.clear();

	return true;
}

void BoardController::gameEnded()
{
	Log("Game ended");
	static_cast<BallsGameController*>(Game::getInstance().getGameController())->gameEnded();
}

void BoardController::selectionChanged()
{
	m_path.clear();
	removeLine();
	Log("Selection changed");
	if(Ball::selectedBall == null)
	{
		Log("Blocking input");
		m_ballsHUD->disableAccept();
	}
}

BoardController::AnimationCounter::AnimationCounter(BoardController* controller) :
		m_count(0),
		m_boardController(controller)
{

}

void BoardController::AnimationCounter::animationFinished(Actor* target)
{
	std::vector<Actor*>::iterator foundIter = std::find(m_watchedActors.begin(), m_watchedActors.end(), target);
	if(foundIter == m_watchedActors.end())
	{
		return;
	}

	target->goToState(Actor::DEFAULT_STATE);

	assert(m_count != 0);
	m_count--;
	if(m_count == 0)
	{
		m_boardController->unblockInput();
	}
	m_watchedActors.erase(foundIter);
}

void BoardController::AnimationCounter::addWatched(Actor* actor)
{
	assert(std::find(m_watchedActors.begin(), m_watchedActors.end(), actor) == m_watchedActors.end());
	m_watchedActors.push_back(actor);
}

void BoardController::AnimationCounter::removeWatched(Actor* actor)
{
	std::vector<Actor*>::iterator foundIter = std::find(m_watchedActors.begin(), m_watchedActors.end(), actor);
	assert(foundIter != m_watchedActors.end());
	m_watchedActors.erase(foundIter);
}

void BoardController::AnimationCounter::reset(int count)
{
	m_watchedActors.clear();
	m_count = count;
	m_boardController->blockInput();
}

void BoardController::removeLine()
{
	if(m_lineActor)
	{
        LineActor::destroy(m_lineActor);
		m_lineActor.reset();
	}
}

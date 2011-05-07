/*
 * BoardModel.cpp
 *
 *  Created on: 2010-12-15
 *      Author: artur.m
 */

#include "BoardModel.h"

#include <algorithm>
#include <queue>
#include <memory>

#include "Game.h"
#include "MathHelper.h"
#include "Board.h"
#include "BoardController.h"

BoardModel::BoardModel(Board* board) :
	m_board(board)
{
	memset(m_grids, 0, sizeof(Grid) * COUNT * COUNT);
	for(int j = 0; j < COUNT; ++j)
	{
		for(int i = 0; i < COUNT; ++i)
		{
			m_grids[i][j].x = i;
			m_grids[i][j].y = j;
			if(i-1 >= 0) 	m_grids[i][j].neighbours[0] = &(m_grids[i-1][j]);
			if(i+1 < COUNT) m_grids[i][j].neighbours[1] = &(m_grids[i+1][j]);
			if(j-1 >= 0)	m_grids[i][j].neighbours[2] = &(m_grids[i][j-1]);
			if(j+1 < COUNT) m_grids[i][j].neighbours[3] = &(m_grids[i][j+1]);
		}
	}
}

BoardModel::~BoardModel()
{
    // tell the game that references to balls should be dropped
    for(int j = 0; j < COUNT; ++j)
    for(int i = 0; i < COUNT; ++i)
    {
        if(m_grids[i][j].ball)
        {
            Actor::destroy(m_grids[i][j].ball);
        }
    }
}

const BoardModel::GridInfoContainer& BoardModel::getFreeGrids() const
{
	static GridInfoContainer empty;
	empty.clear();
	for(int j = 0; j < COUNT; ++j)
	{
		for(int i = 0; i < COUNT; ++i)
		{
			if(m_grids[i][j].ball == null)
			{
				empty.push_back(GridInfo(i, j));
			}
		}
	}
	return empty;
}

const BoardModel::GridInfoContainer& BoardModel::getOccupiedGrids() const
{
	static GridInfoContainer occupied;
	occupied.clear();
	for(int j = 0; j < COUNT; ++j)
	{
		for(int i = 0; i < COUNT; ++i)
		{
			if(m_grids[i][j].ball != null)
			{
				occupied.push_back(GridInfo(i, j));
			}
		}
	}
	return occupied;
}

void BoardModel::checkDisappearing(int x, int y, std::vector<shared_ptr<Ball> >& result) const
{
	assert(m_grids[x][y].ball != null);
	Ball::Color ballColor = m_grids[x][y].ball->getBallColor();

	bool found = false;
	std::vector<shared_ptr<Ball> > tempList;

	GridInfo grid(x, y);
	//horizontal
	GetSameNeighboursByDirection(grid, ballColor, tempList, -1, 0 );
	GetSameNeighboursByDirection(grid, ballColor, tempList, 1, 0 );
	if(tempList.size() >= 4)
	{
		found = true;
		result.insert(result.end(), tempList.begin(), tempList.end());
	}
	//vertical
	tempList.clear();
	GetSameNeighboursByDirection(grid, ballColor, tempList, 0, -1);
	GetSameNeighboursByDirection(grid, ballColor, tempList, 0, 1);
	if(tempList.size() >= 4)
	{
		found = true;
		result.insert(result.end(), tempList.begin(), tempList.end());
	}
	//diagonal left to right
	tempList.clear();
	GetSameNeighboursByDirection(grid, ballColor, tempList, 1, 1);
	GetSameNeighboursByDirection(grid, ballColor, tempList, -1, -1);
	if(tempList.size() >= 4)
	{
		found = true;
		result.insert(result.end(), tempList.begin(), tempList.end());
	}
	//diagonal right to left
	tempList.clear();
	GetSameNeighboursByDirection(grid, ballColor, tempList, 1, -1);
	GetSameNeighboursByDirection(grid, ballColor, tempList, -1, 1);
	if(tempList.size() >= 4)
	{
		found = true;
		result.insert(result.end(), tempList.begin(), tempList.end());
	}

	if(found)
	{
		result.push_back(m_grids[x][y].ball);
	}
}

void BoardModel::GetSameNeighboursByDirection(GridInfo grid, Ball::Color ballColor,
		std::vector<shared_ptr<Ball> >& result, int horizontalDiff, int verticalDiff) const
{
	int x = grid.x;
	int y = grid.y;

	x += horizontalDiff;
	y += verticalDiff;
	if(x < 0 || x >= COUNT)
	{
		return;
	}
	if(y < 0 || y >= COUNT)
	{
		return;
	}

	shared_ptr<Ball> temp = m_grids[x][y].ball;
	while(temp != null)
	{
		if( temp == null )
		{
			break;
		}
		if(ballColor != temp->getBallColor())
		{
			break;
		}
		result.push_back(temp);
		x += horizontalDiff;
		y += verticalDiff;
		if(x < 0 || x >= COUNT)
		{
			break;
		}
		if(y < 0 || y >= COUNT)
		{
			break;
		}
		temp = m_grids[x][y].ball;
	}
}

bool BoardModel::isValidToAdd(int x, int y, Ball::Color ballColor) const
{
	if(m_grids[x][y].ball != null)
	{
		return false;
	}

	std::vector<shared_ptr<Ball> > tempList;

	GridInfo grid(x, y);
	//horizontal
	GetSameNeighboursByDirection(grid, ballColor, tempList, -1, 0 );
	GetSameNeighboursByDirection(grid, ballColor, tempList, 1, 0 );
	if(tempList.size() >= 4)
	{
		return false;
	}
	//vertical
	tempList.clear();
	GetSameNeighboursByDirection(grid, ballColor, tempList, 0, -1);
	GetSameNeighboursByDirection(grid, ballColor, tempList, 0, 1);
	if(tempList.size() >= 4)
	{
		return false;
	}
	//diagonal left to right
	tempList.clear();
	GetSameNeighboursByDirection(grid, ballColor, tempList, 1, 1);
	GetSameNeighboursByDirection(grid, ballColor, tempList, -1, -1);
	if(tempList.size() >= 4)
	{
		return false;
	}
	//diagonal right to left
	tempList.clear();
	GetSameNeighboursByDirection(grid, ballColor, tempList, 1, -1);
	GetSameNeighboursByDirection(grid, ballColor, tempList, -1, 1);
	if(tempList.size() >= 4)
	{
		return false;
	}

	return true;
}

void BoardModel::addBall(int x, int y, shared_ptr<Ball> ball)
{
	Log("Adding ball at (%d, %d)", x, y);
	assert(m_grids[x][y].ball == null);
	m_grids[x][y].ball = ball;
}

void BoardModel::removeBall(int x, int y)
{
	assert(m_grids[x][y].ball != null);
	m_grids[x][y].ball.reset(); 
}

shared_ptr<Ball> BoardModel::getBallAt(int x, int y)
{
	return m_grids[x][y].ball;
}

void BoardModel::getPath(int startX, int startY, int endX, int endY)
{
//	Log("Threaded pathfinding - from (%d, %d) to (%d, %d)", startX, startY, endX, endY);
	m_startGrid = GridInfo(startX, startY);
	m_endGrid = GridInfo(endX, endY);
	m_thread = GameThread::createThread(this);
	m_thread->start();
}

void BoardModel::run()
{
	assert(&(m_grids[m_startGrid.x][m_startGrid.y]) != &(m_grids[m_endGrid.x][m_endGrid.y]));

	std::vector<Grid*> blocked;
	blocked.reserve(512);

	std::queue<Grid*> working;

	m_grids[m_startGrid.x][m_startGrid.y].parent = null;

	working.push(&(m_grids[m_startGrid.x][m_startGrid.y]));

	Grid* targetNode = null;
	Grid* tempNode = null;

	const Grid* const target = &(m_grids[m_endGrid.x][m_endGrid.y]);

	while(working.size() != 0)
	{
		tempNode = working.front();
		working.pop();
		if(tempNode == target)
		{
			targetNode = tempNode;
			break;
		}

		for(int i = 0; i < 4; ++i)
		{
			Grid* workingGridToBe = tempNode->neighbours[i];
			if(workingGridToBe == null || workingGridToBe->ball != null)
			{
				continue;
			}
			if(std::find(blocked.begin(), blocked.end(), workingGridToBe) == blocked.end())
			{
				workingGridToBe->parent = tempNode;
				working.push(workingGridToBe);
			}
		}
		if(std::find(blocked.begin(), blocked.end(), tempNode) == blocked.end())
		{
			blocked.push_back(tempNode);
		}
	}

	std::vector<Vector> result;
	// Recreating path and saving it to the result
	while(targetNode)
	{
		Vector step = m_board->getPanelCenter(targetNode->x, targetNode->y);
		step.z = m_board->getPosition().z + Board::HEIGHT_ABOVE;
		result.insert(result.begin(), step);
		targetNode = targetNode->parent;
	}

	m_board->getController().pathFound(result);
}

void BoardModel::moveBall(const GridInfo& from, const GridInfo& to)
{
	Log("Moving ball from (%d, %d), to (%d, %d)", from.x, from.y, to.x, to.y);

	assert(m_grids[from.x][from.y].ball != null);
	assert(m_grids[to.x][to.y].ball == null);

//	m_grids[to.x][to.y].ball = m_grids[from.x][from.y].ball;
//	m_grids[from.x][from.y].ball = null;
    
    m_grids[to.x][to.y].ball.swap(m_grids[from.x][from.y].ball);

	Log("Finished moving");
}

GridInfo BoardModel::findGrid(const Ball* ball) const
{
	for(int j = 0; j < COUNT; ++j)
	{
		for(int i = 0; i < COUNT; ++i)
		{
			if(m_grids[i][j].ball.get() == ball)
			{
				return GridInfo(i, j);
			}
		}
	}
	Log("Wrong pointer supplied - %p", ball);
	Log("Ball's color - %d", ball->getBallColor());
	assert(!"Wrong pointer supplied!");
	return GridInfo(-1, -1);
}

GridInfo::GridInfo(int x, int y) :
	x(x),
	y(y)
{

}

GridInfo::GridInfo(const GridInfo& other) :
	x(other.x),
	y(other.y)
{

}

bool GridInfo::operator==(const GridInfo& other) const
{
	return (x == other.x) && (y == other.y);
}

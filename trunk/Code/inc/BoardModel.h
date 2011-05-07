/*
 * BoardModel.h
 *
 *  Created on: 2010-12-15
 *      Author: artur.m
 */

#ifndef BOARDMODEL_H_
#define BOARDMODEL_H_

#include "Ball.h"
#include "GameThread.h"

#include <vector>

class Board;

class GridInfo
{
public:
	GridInfo(int x = -1, int y = -1);
	GridInfo(const GridInfo& other);
	int x;
	int y;

	bool operator==(const GridInfo& other) const;
};

class BoardModel : public GameRunnable
{
public:
	typedef std::vector<GridInfo> GridInfoContainer;
	typedef GridInfoContainer::iterator GridInfosIter;
	static const int COUNT = 9;
	static const unsigned int DISAPPEAR_COUNT = 5;
	static const int STARTING_COUNT = 5;


	BoardModel(Board* board);
	virtual ~BoardModel();

	const GridInfoContainer& getFreeGrids() const;
	const GridInfoContainer& getOccupiedGrids() const;

	bool isValidToAdd(int x, int y, Ball::Color ballColor) const;

	void addBall(int x, int y, shared_ptr<Ball> ball);
	void removeBall(int x, int y);
	void moveBall(const GridInfo& from, const GridInfo& to);

	shared_ptr<Ball> getBallAt(int x, int y);
	GridInfo findGrid(const Ball* ball) const;


	void checkDisappearing(int x, int y, std::vector<shared_ptr<Ball> >& result) const;
	void GetSameNeighboursByDirection(GridInfo grid, Ball::Color ballColor,
			std::vector<shared_ptr<Ball> >& result, int horizontalDiff, int verticalDiff) const;

	void getPath(int startX, int startY, int endX, int endY);

	virtual void run();

private:
	struct Grid
	{
		shared_ptr<Ball> ball;
		Grid* neighbours[4];
		int x;
		int y;
		Grid* parent;
	};

	Grid m_grids[COUNT][COUNT];
	Board* m_board;

	// for path finding purposes
	GridInfo m_startGrid;
	GridInfo m_endGrid;
	std::auto_ptr<GameThread> m_thread;
};

#endif /* BOARDMODEL_H_ */

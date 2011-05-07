/*
 * BoardController.h
 *
 *  Created on: 2010-12-15
 *      Author: artur.m
 */

#ifndef BOARDCONTROLLER_H_
#define BOARDCONTROLLER_H_

#include <vector>

#include "Ball.h"
#include "PhysicsEngine.h"
#include "LineActor.h"
#include "shared_ptr.h"

class Board;
class BallsHUD;
class BallsInformations;

class BoardController : public AnimationListener
{
public:
	BoardController(Board* board);
	virtual ~BoardController();

	void addRandomBall(shared_ptr<Ball> ball);
	shared_ptr<Ball> createRandomColorBall() const;

	void pressedGrid(int x, int y);
	void pathFound(const std::vector<Vector>& path);
	void removeLine();

	void animationFinished(Actor* target);

	void acceptMove();

	void prepareRandomBalls(int count);

	void selectionChanged();

private:
	void blockInput();
	void unblockInput();

	// Returns if it was possible to move the prepared balls
	bool movePreparedBalls();
	void gameEnded();

	// An utility class which is supposed to listen to
	// animation finished callbacks for those balls which
	// Are moved from the prepared balls to their target places
	// on the board.
	// Also changes states of the balls from "waiting" to "default"
	class AnimationCounter : public AnimationListener
	{
	public:
		AnimationCounter(BoardController* controller);
		void animationFinished(Actor* target);
		void addWatched(Actor* actor);
		void removeWatched(Actor* actor);
		void reset(int count);
	private:
		int m_count;
		BoardController* m_boardController;
		std::vector<Actor*> m_watchedActors;
	};

	Board* m_board;
	bool m_blocked;
    shared_ptr<LineActor> m_lineActor;
	BallsHUD* m_ballsHUD;
	BallsInformations* m_ballsInformations;

	std::vector<Vector> m_path;
	std::vector<shared_ptr<Ball> > m_preparedBalls;

	AnimationCounter m_animationCounter;
};

#endif /* BOARDCONTROLLER_H_ */

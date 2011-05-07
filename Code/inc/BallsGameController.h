/*
 * BallsGameController.h
 *
 *  Created on: 2010-12-16
 *      Author: artur.m
 */

#ifndef BALLSGAMECONTROLLER_H_
#define BALLSGAMECONTROLLER_H_

#include "GameController.h"
#include "shared_ptr.h"

#include <string>
#include <memory>

class BlockButton;
class BallsInformations;
class Board;

class BallsGameController : public GameController
{
public:
	enum GameDifficulty
	{
		GD_EASY,
		GD_MEDIUM,
		GD_HARD,
		GD_ENUM_SIZE
	};

	static const int EASY_COLORS = 5;
	static const int MEDIUM_COLORS = 7;
	static const int HARD_COLORS = 9;

	BallsGameController();
	virtual ~BallsGameController();

	virtual std::string getClass() const;

	void setDifficulty(GameDifficulty difficulty);
	GameDifficulty getDifficulty() const;
	int getCurrentColorsCount() const;

	void initialize();

	void startGame();
	void gameEnded();

	unsigned int getPoints() const;
	void addPoints(unsigned int disappearedBalls);
	void enableCombo(bool value);

private:
	GameDifficulty m_difficulty;
	bool m_comboActive;
	unsigned int m_points;
    shared_ptr<BlockButton> m_blockButton;
    shared_ptr<BallsInformations> m_ballsInformations;
    shared_ptr<Board> m_board;
};

#endif /* BALLSGAMECONTROLLER_H_ */

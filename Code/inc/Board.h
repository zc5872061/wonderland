/*
 * Board.h
 *
 *  Created on: 2010-12-08
 *      Author: artur.m
 */

#ifndef BOARD_H_
#define BOARD_H_

#include "pi.h"

#include <string>

#include "Actor.h"
#include "Ball.h"
#include "Program.h"
#include "BoardModel.h"
#include "BoardController.h"
#include "shared_ptr.h"

class Board : public Actor
{
public:
	static const GLfloat SIDE_SIZE;
	static const GLfloat HEIGHT_ABOVE;
	static const std::string TYPE;
	static const int CREATING_COUNT = 3;
	static const int BALL_SINGLE_BRICK_TIME = 100;

	typedef void* ConstructionParams;

	virtual std::string getType() const;

    static shared_ptr<Board> spawn(const Vector& position);
	virtual ~Board();

	virtual void update(int milis);
//	virtual void updateProgram(Program& program) const;

	BoardController& getController();
	BoardModel& getBoardModel();
	GridInfo getTouchedGrid(GLfloat x, GLfloat y) const;

	virtual void released(const Actor* target, const Vector& touchPoint);

	Vector getPanelCenter(int x, int y) const;

	void selectionChanged();

private:
    Board(const Vector& position);
    
private:
	BoardController m_controller;
	BoardModel m_boardModel;
};

#endif /* BOARD_H_ */

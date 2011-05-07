/*
 * Ball.h
 *
 *  Created on: 2010-12-08
 *      Author: artur.m
 */

#ifndef BALL_H_
#define BALL_H_

#include "Actor.h"
#include "shared_ptr.h"
#include <string>

class Ball;

class FallingState : public BasicState
{
public:
	static const float ACCELERATION;
	static const float START_HEIGHT;

	FallingState(Ball* ball);
	virtual void update(int milis);
	virtual void stateEntered();
	virtual void stateEnded();

private:
	Ball* m_ball;
	Vector m_startBallPos;
	float m_speed;
	float m_height;
};

// This state as of now simply ignores everything
class WaitingState : public BasicState
{
public:
	WaitingState(Ball* ball);
	virtual void stateEntered();
	virtual void stateEnded();

private:
	Ball* m_ball;
};

class DisappearingState : public BasicState
{
public:
	DisappearingState(Ball* ball);
	virtual void stateEntered();
	virtual void stateEnded();
	virtual void update(int milis);

private:
	static const GLfloat MIN_SIZE;
	static const GLfloat EXP;

	Ball* m_ball;
};

class Board;

class Ball : public Actor
{
public:
    friend class Game;
    
	static const std::string STATE_FALLING_NAME;
	static const std::string STATE_WAITING_NAME;
	static const std::string STATE_DISAPPERING_NAME;
	static const std::string MESH_NAME;

	enum Color
	{
		BALL_BLUE,
		BALL_RED,
		BALL_GREEN,
		BALL_ORANGE,
		BALL_VIOLET,
		BALL_CYAN,
		BALL_GREY,
		BALL_BLACK,
		BALL_GRASS,
		BALL_ENUM_SIZE
	};

	typedef Color CreationParams;

	static const std::string TYPE;
	static Ball* selectedBall;
	static void deselectBall();
	static void selectionChanged();
	static Board* s_board;

    static shared_ptr<Ball> spawn(const Vector& position, Color color);
    virtual ~Ball();

	virtual std::string getType() const;

	virtual void update(int milis);

	virtual Vector getPosition() const;

	virtual void released(const Actor* target, const Vector& touchPoint);

	void setSelected(bool value);
	bool isSelected() const;

	void setBallColor(Color color);
	Color getBallColor() const;
    
    void setColor(const Vector& color);
    Vector getColor() const { return m_color; }
    
protected:
    Ball(const Vector& position, Color color);

private:
	bool m_selected;
	Vector m_animationMove;
	Color m_ballColor;
	long long m_elapsedTime;
    Vector m_color;
    Vector m_ambientColor;

	FallingState m_stateFalling;
	WaitingState m_stateWaiting;
	DisappearingState m_stateDisappearing;
    
};

#endif /* BALL_H_ */

/*
 * BasicState.h
 *
 *  Created on: 2010-12-21
 *      Author: artur.m
 */

#ifndef BASICSTATE_H_
#define BASICSTATE_H_

#include "Vector.h"

class Actor;

class BasicState
{
public:
	virtual void update(int milis) {}
	virtual void touched(const Actor* target, const Vector& touchPoint) {};
	virtual void released(const Actor* target, const Vector& touchPoint) {};
	virtual void stateEntered() {}
	virtual void stateEnded() {}
};

#endif /* BASICSTATE_H_ */

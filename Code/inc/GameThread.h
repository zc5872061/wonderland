/*
 * GameThread.h
 *
 *  Created on: 2010-12-21
 *      Author: artur.m
 */

#ifndef GAMETHREAD_H_
#define GAMETHREAD_H_

#include <memory>

class GameRunnable
{
public:
	virtual void run() = 0;
};

class GameThread
{
public:
	static std::auto_ptr<GameThread> createThread(GameRunnable* runnable);

	GameThread();
	virtual ~GameThread();

	virtual void start() = 0;
};

#endif /* GAMETHREAD_H_ */

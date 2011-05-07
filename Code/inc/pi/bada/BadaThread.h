/*
 * BadaThread.h
 *
 *  Created on: 2010-12-21
 *      Author: artur.m
 */

#ifndef BADATHREAD_H_
#define BADATHREAD_H_

#include "GameThread.h"

#include <FBase.h>

class BadaRunnable : public Osp::Base::Runtime::IRunnable
{
public:
	BadaRunnable(GameRunnable* runnable) :
		m_runnable(runnable)
	{
	}

	~BadaRunnable()
	{
	}

	virtual Osp::Base::Object* Run()
	{
		m_runnable->run();
		return null;
	}

private:
	GameRunnable* m_runnable;
};

class BadaThread : public GameThread
{
public:
	BadaThread(GameRunnable* runnable);
	virtual ~BadaThread();

	virtual void start();

private:
	Osp::Base::Runtime::Thread* m_thread;
	BadaRunnable* m_runnable;
};

#endif /* BADATHREAD_H_ */

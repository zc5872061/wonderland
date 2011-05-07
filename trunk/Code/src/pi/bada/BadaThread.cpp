/*
 * BadaThread.cpp
 *
 *  Created on: 2010-12-21
 *      Author: artur.m
 */

#include "pi/bada/BadaThread.h"


BadaThread::BadaThread(GameRunnable* runnable) :
	m_thread(null),
	m_runnable(new BadaRunnable(runnable))
{
	m_thread = new Osp::Base::Runtime::Thread();
	m_thread->Construct(*m_runnable);
}

BadaThread::~BadaThread()
{
	delete m_thread;
	delete m_runnable;
}

void BadaThread::start()
{
	m_thread->Start();
}

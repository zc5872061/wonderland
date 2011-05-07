/*
 * GameThread.cpp
 *
 *  Created on: 2010-12-21
 *      Author: artur.m
 */

#include "GameThread.h"

#if defined (SHP)
	#include "pi/bada/BadaThread.h"
	#include <FGraphics.h>
#elif defined (IOS)
    #include "iOSThread.h"
#else
	#error
#endif

std::auto_ptr<GameThread> GameThread::createThread(GameRunnable* runnable)
{
#if defined (SHP)
	return std::auto_ptr<GameThread>(new BadaThread(runnable));
#elif defined (IOS)
    return std::auto_ptr<GameThread>(new iOSThread(runnable));
#else
	#error
#endif
}

GameThread::GameThread()
{

}

GameThread::~GameThread()
{

}

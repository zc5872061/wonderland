/*
 * iOSThread.h
 *
 *  Created on: 2011-03-20
 *      Author: Artur Mazurek
 */

//#include "iOSThread.h"
#include "iOSThread.h"

@implementation ThreadAdapter

-(void)threadFunction
{
    m_runnable->run();
}

@end

iOSThread::iOSThread(GameRunnable* runnable)
{
    m_adapter = [[ThreadAdapter alloc] init];
    m_adapter->m_runnable = runnable;
}

//iOSThread::~iOSThread()
//{
//    
//}

void iOSThread::start()
{
    m_thread = [[NSThread alloc] initWithTarget:m_adapter selector:@selector(threadFunction) object:nil];
    [m_thread start];
}
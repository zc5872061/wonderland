/*
 * iOSThread.h
 *
 *  Created on: 2011-03-20
 *      Author: Artur Mazurek
 */
#ifndef _IOS_THREAD_H_
#define _IOS_THREAD_H_

#include "GameThread.h"

@interface ThreadAdapter : NSObject{
@public
    GameRunnable* m_runnable;
}
-(void)threadFunction;
@end

class iOSThread : public GameThread
{
public:
    iOSThread(GameRunnable* runnable);
    ~iOSThread() {};
    
    void start();
    
private:
    ThreadAdapter* m_adapter;
    NSThread* m_thread;
};

#endif // _IOS_THREAD_H_
/*
 * pi.h
 *
 *  Created on: 2011-03-17
 *      Author: Artur Mazurek
 */
#ifndef _PI_IOS_H_
#define _PI_IOS_H_

#import <OpenGLES/EAGL.h>

#import <OpenGLES/ES1/gl.h>
#import <OpenGLES/ES1/glext.h>
#import <OpenGLES/ES2/gl.h>
#import <OpenGLES/ES2/glext.h>

#include <cassert>
#include <cstdlib>
#include <string>

#define Log(...) {printf(__VA_ARGS__);printf("\n");}

#define null 0

namespace Constants
{
    static const float SCREEN_WIDE = 960;
    static const float SCREEN_NARROW = 640;
};

#endif // _PI_IOS_H_
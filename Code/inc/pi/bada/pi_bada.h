/*
 * pi_bada.h
 *
 *  Created on: 2010-12-02
 *      Author: artur.m
 */

#ifndef PI_BADA_H_
#define PI_BADA_H_

#include <FBase.h>
#include <FSystem.h>
#include <FGraphicsOpengl2.h>

using namespace Osp::Graphics::Opengl;

#define Log(...) AppLog(__VA_ARGS__)

#define getTicks Osp::System::SystemTime::GetTicks

#ifndef assert
	#define assert(...)	AppAssert(__VA_ARGS__)
#endif

namespace Constants
{
	static const int SCREEN_NARROW = 480;
	static const int SCREEN_WIDE = 800;
};

#endif /* PI_BADA_H_ */

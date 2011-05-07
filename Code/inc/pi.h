/*
 * pi.h
 *
 *  Created on: 2010-12-02
 *      Author: artur.m
 */

#ifndef PI_H_
#define PI_H_

#if defined(SHP)
	#include "pi/bada/pi_bada.h"
#elif defined(IOS)
    #include "pi/iOS/pi_iOS.h"
#else
	#error // Unknown platform
#endif

#include <string>

// Namespace for some constants retrieval such as Root path to the
// resources directory. Note that Constants actually means run-time
// constants, theymay change between installations etc.
namespace Constants
{
    // Path to the root directory of resources (nothing else should be important actually).
    // As of now bitmaps and models should be there
    std::string getRootPath();
    // Get path to the Materials directory relative to the root path
    std::string getMaterialsDir();
    // Get path to the Fonts directory relative to the root path
    std::string getFontsDir();
    // Get path to the UI data files relative to the root path
    std::string getUiDataPath();
    // Return the dpi resolution of the device. The silent assumption is
    // that the pixels are square so it doesn't matter if we are talking
    // about horizontal or vertical
    int getDpi();
}

/*
 Above files contain platform specific stuff such as paths to resources,
 screen dimensions (although try to use only the relative sizes in code),
 etc.
 
 The following things must be defined for application to compile and run properly:
 Log(...) - function which logs data to some output. The function itself must accept printf-like calls
 
 And some constants which must sit in Constants namespace 
 ROOT_PATH - std::string with the path to the root folder where the resources are contained
 MATERIALS_PATH - std::string with the relative path from ROOT_PATH to the path with .mat files
 SCREEN_WIDE - float with the size of the wider side of the screen in pixels
 SCREEN_NARROW - float with the size of the narrow side of the screen in pixels
 
 Sometimes there are some things which also should be defined there somehow, e.g. if the platform
 doesn't have 'null' or 'assert' but has other stuff with similar functionality.
*/


#endif /* PI_H_ */

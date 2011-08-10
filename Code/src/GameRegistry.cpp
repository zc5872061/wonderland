/*
 * GameRegistry.cpp
 *
 *  Created on: 2011-08-10
 *      Author: Artur
 */
#include "GameRegistry.h"

#if defined (SHP)
	#include "pi/bada/BadaRegistry.h"
#elif defined (IOS)
    #include "pi/iOS/iOSRegistry.h"
#else
	#error
#endif

shared_ptr<GameRegistry> GameRegistry::createRegistry()
{
#if defined (SHP)
	return shared_ptr<GameRegistry>(new BadaRegistry());
#elif defined (IOS)
    return shared_ptr<GameRegistry>(new iOSRegistry());
#else
	#error
#endif
}

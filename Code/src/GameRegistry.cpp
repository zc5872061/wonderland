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

int GameRegistry::getIntDef(const std::string& key, int def)
{
	if(!hasKey(key))
	{
		return def;
	}

	int result = 0;
	if(!getInt(key, result))
	{
		return def;
	}

	return result;
}

double GameRegistry::getDoubleDef(const std::string& key, double def)
{
	if(!hasKey(key))
	{
		return def;
	}

	double result = 0;
	if(!getDouble(key, result))
	{
		return def;
	}

	return result;
}

std::string GameRegistry::getStringDef(const std::string& key, const std::string& def)
{
	if(!hasKey(key))
	{
		return def;
	}

	std::string result = 0;
	if(!getString(key, result))
	{
		return def;
	}

	return result;
}

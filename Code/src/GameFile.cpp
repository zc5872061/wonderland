/*
 * GameFile.cpp
 *
 *  Created on: 2010-12-10
 *      Author: artur.m
 */

#include "GameFile.h"

#if defined (SHP)
	#include "pi/bada/BadaFile.h"
#elif defined (IOS)
    #include "pi/iOS/iOSFile.h"
#else
	#error
#endif

shared_ptr<GameFile> GameFile::openFile(const std::string& fileName, const std::string& mode)
{
#if defined (SHP)
	return shared_ptr<GameFile>(new BadaFile(fileName, mode));
#elif defined(IOS)
    return shared_ptr<GameFile>(new iOSFile(fileName, mode));
#else
    #error
#endif
}

GameFile::GameFile()
{

}

GameFile::~GameFile()
{

}

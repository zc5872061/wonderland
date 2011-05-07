/*
 * GameFile.h
 *
 *  Created on: 2010-12-10
 *      Author: artur.m
 */

#ifndef GAMEFILE_H_
#define GAMEFILE_H_

#include <string>
#include <memory>

#include "shared_ptr.h"

class GameFile
{
public:
	static shared_ptr<GameFile> openFile(const std::string& fileName, const std::string& mode);

	virtual ~GameFile();

	virtual std::string readLine() = 0;
	virtual std::string read() = 0; //reads whole file
	virtual bool eof() = 0;

protected:
	GameFile();
};

#endif /* GAMEFILE_H_ */

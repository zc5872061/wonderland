/*
 * BadaFile.h
 *
 *  Created on: 2010-12-10
 *      Author: artur.m
 */

#ifndef BADAFILE_H_
#define BADAFILE_H_

#include <GameFile.h>

#include <FIo.h>

#include <string>

class BadaFile : public GameFile
{
public:
	BadaFile(const std::string& filePath, const std::string& fileMode);
	virtual ~BadaFile();

	virtual std::string readLine();
	virtual std::string read(); //reads whole file
	virtual bool eof();

	unsigned char* buffer;
	unsigned int size;

private:
	Osp::Io::File m_file;
};

#endif /* BADAFILE_H_ */

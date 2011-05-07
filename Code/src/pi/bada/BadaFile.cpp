/*
 * BadaFile.cpp
 *
 *  Created on: 2010-12-10
 *      Author: artur.m
 */

#include "pi/bada/BadaFile.h"

#include <FBase.h>
#include <FText.h>
#include <FIo.h>

#include <memory>

std::string badaStringToStdString(const Osp::Base::String& text)
{
	Osp::Text::AsciiEncoding ascii;

	std::auto_ptr<Osp::Base::ByteBuffer> pBuffer(ascii.GetBytesN(text));
	int byteCount = pBuffer->GetCapacity();

	char* chPtrBuf = new char[byteCount + 1];
	pBuffer->GetArray((byte*)chPtrBuf, 0, byteCount);

	std::string cString(chPtrBuf);
	delete [] chPtrBuf;

	return cString;
}

BadaFile::BadaFile(const std::string& filePath, const std::string& fileMode) :
		buffer(null),
		size(0)
{
	result r = m_file.Construct(Osp::Base::String(filePath.c_str()), Osp::Base::String(fileMode.c_str()));
	if(r != E_SUCCESS)
	{
		AppLog("Could not open file - %s", filePath.c_str());
	}

	Osp::Io::FileAttributes attr;
	Osp::Io::File::GetAttributes(Osp::Base::String(filePath.c_str()), attr);
	unsigned long long size = attr.GetFileSize();
	this->size = size;
	buffer = new unsigned char[size];
	m_file.Read(buffer, size);

	m_file.Seek(Osp::Io::FILESEEKPOSITION_BEGIN, 0); // return to begin after reading everything

	AppAssert(r == E_SUCCESS);
}

BadaFile::~BadaFile()
{
}

std::string BadaFile::readLine()
{
	Osp::Base::String buffer;
	m_file.Read(buffer);
	std::string result = badaStringToStdString(buffer);
	return result.substr(0, result.find('\n'));
}

std::string BadaFile::read()
{
	std::string fullText;
	while(!eof())
	{
		std::string line = readLine() + '\n'; // because in full file string we want newlines
		fullText += line;
	}
	return fullText;
}

bool BadaFile::eof()
{
	int currentPosition = m_file.Tell();
	m_file.Seek(Osp::Io::FILESEEKPOSITION_END, 0);
	int end = m_file.Tell();
	if(currentPosition == end)
	{
		return true;
	}
	m_file.Seek(Osp::Io::FILESEEKPOSITION_BEGIN, currentPosition);
	return false;
}



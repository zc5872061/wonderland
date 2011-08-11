/*
 * BadaUtil.cpp
 *
 *  Created on: 2011-08-11
 *      Author: Artur
 */
#include "pi/bada/BadaUtil.h"

#include <cstring>
#include <memory>

#include <FText.h>

static std::string toString(const Osp::Base::ByteBuffer& buffer)
{
	int byteCount = buffer.GetLimit();

	char* chPtrBuf = new char[byteCount + 1];
	memset(chPtrBuf, 0, byteCount + 1);
	// documentation states that GetArray copies bytes, so this actually is a const
	// method, but is not named as such in class. No surprise here :/
	const_cast<Osp::Base::ByteBuffer&>(buffer).GetArray((byte*)chPtrBuf, 0, byteCount);

	std::string cString(chPtrBuf);
	delete [] chPtrBuf;

	return cString;
}

std::string toString(const Osp::Base::String& str)
{
	Osp::Text::AsciiEncoding ascii;

	std::auto_ptr<Osp::Base::ByteBuffer> pBuffer(ascii.GetBytesN(str));

	return toString(*pBuffer);
}

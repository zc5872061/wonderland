/*
 * BadaBitmap.cpp
 *
 *  Created on: 2010-12-10
 *      Author: artur.m
 */

#include "pi/bada/BadaBitmap.h"

#include <FBase.h>
#include <FGraphics.h>

#include <algorithm>

Osp::Media::Image* BadaBitmap::s_image(null);

BadaBitmap::BadaBitmap(const std::string& fileName) :
		m_pixels(null),
		m_width(0),
		m_height(0)
{
	if(s_image == null)
	{
		s_image = new Osp::Media::Image();
		if(s_image->Construct() != E_SUCCESS)
		{
			AppAssertf(0, "BadaBitmap::BadaBitmap - could not construct image object.");
		}
	}
	Osp::Base::String badaFile(fileName.c_str());
	std::auto_ptr<Osp::Graphics::Bitmap> bitmap(s_image->DecodeN(badaFile, Osp::Graphics::BITMAP_PIXEL_FORMAT_ARGB8888));

	AppAssertf(bitmap.get() != null, "BadaBitmap::BadaBitmap - could not load image %s", fileName.c_str());

	m_width = bitmap->GetWidth();
	m_height = bitmap->GetHeight();

	copyBitmap(bitmap.get());

	fixColors();
}

BadaBitmap::BadaBitmap(int width, int height) :
	m_pixels(0),
	m_width(width),
	m_height(height)
{
	m_pixels = new unsigned char[m_width * m_height * getByteColorDepth()];
}

BadaBitmap::~BadaBitmap()
{
	delete[] m_pixels;
}

unsigned char* BadaBitmap::getBitmap()
{
	return m_pixels;
}

int BadaBitmap::getWidth() const
{
	return m_width;
}

int BadaBitmap::getHeight() const
{
	return m_height;
}

int BadaBitmap::getByteColorDepth() const
{
	return 4; // TODO: add other byte depths
}

void BadaBitmap::copyBitmap(Osp::Graphics::Bitmap* bitmap)
{
	Osp::Graphics::BufferInfo bi;
	result r = bitmap->Lock(bi);
	AppAssertf(r == E_SUCCESS, "Locking failed in BadaBitmap::unlockImage with error %d", r);

	int pixelSize = 0; // size of pixel in bytes
	switch(bi.pixelFormat)
	{
		case Osp::Graphics::PIXEL_FORMAT_R8G8B8A8:
		{
			pixelSize = 4;
			break;
		}
		case Osp::Graphics::PIXEL_FORMAT_ARGB8888:
		{
			pixelSize = 4;
			break;
		}
		default:
		{
			AppAssertf(0, "Unsupported bitmap format in BadaBitmap::copyBitmap");
		}
	}

	int pixelCount = pixelSize * m_width * m_height;
	AppAssert(pixelCount != 0);
	AppAssert(m_pixels == null);
	m_pixels = new unsigned char[pixelCount];
	memcpy(m_pixels, bi.pPixels, pixelCount);

	bitmap->Unlock();
}

void BadaBitmap::fixColors()
{
	size_t size = m_width * m_height * getByteColorDepth();
	const int step = getByteColorDepth();

	for(size_t i = 0; i < size; i+=step)
	{
		std::swap(m_pixels[i], m_pixels[i+2]);
	}
}

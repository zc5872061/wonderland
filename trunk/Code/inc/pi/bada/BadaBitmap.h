/*
 * BadaBitmap.h
 *
 *  Created on: 2010-12-10
 *      Author: artur.m
 */

#ifndef BADABITMAP_H_
#define BADABITMAP_H_

#include "GameBitmap.h"

#include <FMedia.h>
#include <FGraphics.h>

#include <memory>

class BadaBitmap : public GameBitmap
{
public:
	BadaBitmap(const std::string& fileName);
	BadaBitmap(int width, int height);
	virtual ~BadaBitmap();

	virtual unsigned char* getBitmap();
	virtual int getWidth() const;
	virtual int getHeight() const;
	virtual int getByteColorDepth() const;

private:
	static Osp::Media::Image* s_image;

	unsigned char* m_pixels;
	int m_width;
	int m_height;

	void copyBitmap(Osp::Graphics::Bitmap* bitmap);
};

#endif /* BADABITMAP_H_ */

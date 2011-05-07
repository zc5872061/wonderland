/*
 * iOSBitmap.h
 *
 *  Created on: 2011-03-20
 *      Author: Artur Mazurek
 */
#ifndef _IOS_BITMAP_H_
#define _IOS_BITMAP_H_

#include "GameBitmap.h"

#include <string>

class iOSBitmap : public GameBitmap
{
public:
    iOSBitmap(const std::string filename);
    iOSBitmap(int width, int height);
	virtual ~iOSBitmap();
    
	unsigned char* getBitmap();
    int getWidth() const;
	int getHeight() const;
    int getByteColorDepth() const { return BYTE_DEPTH; }
    Common::Pixel* getPixel(int x, int y);
    
private:
    static const int BYTE_DEPTH = 4;
    unsigned char* m_data; // iOSBitmap needs to deallocate it later
    int m_width;
    int m_height;
};

#endif // _IOS_BITMAP_H_
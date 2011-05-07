/*
 * GameBitmap.h
 *
 *  Created on: 2010-12-10
 *      Author: artur.m
 */

#ifndef GAMEBITMAP_H_
#define GAMEBITMAP_H_

#include <string>
#include <memory>

#include "shared_ptr.h"
#include "GameCommon.h"

class GameBitmap
{
public:
	static shared_ptr<GameBitmap> createBitmap(const std::string& fileName);
    static shared_ptr<GameBitmap> createBitmap(int width, int height);
    static shared_ptr<GameBitmap> clone(const shared_ptr<GameBitmap> bitmap);
    
    // Valid operations on bitmaps
    enum BitmapOperation
    {
        BO_COPY_OVERWRITE, // source will be copied onto target not checking anything
        BO_COPY_BLEND, // source and target will be blended together
        BO_MULTIPLY, // source will be multiplied by target
        BO_OVERLAY, // source will be copied onto target, but taking into account target's alpha
        BO_ENUM_SIZE
    };
    // Does something on the target bitmap taking into account the source bitmap.
    // These are p2p (pixel to pixel) operations and if the sizes of bitmaps are different (or are positioned differently
    // The effect will be seen only on the overlapping square.
    // The (startX, startY) pair is the position of top-left corner of source in respect to top-left
    // corner of target.
    static void transform(GameBitmap* target, const GameBitmap* source, BitmapOperation operation,
                          int startX = 0, int startY = 0);
    static void transform(GameBitmap* target, Common::Color color, BitmapOperation operation);
    static void transformAligned(GameBitmap* target, const GameBitmap* source, BitmapOperation operation,
                                 Common::HorizontalAlignment hAlign, Common::VerticalAlignment vAlign);

	virtual ~GameBitmap() {};

	virtual unsigned char* getBitmap() = 0;
	virtual int getWidth() const = 0;
	virtual int getHeight() const = 0;
    virtual int getByteColorDepth() const = 0;
    Common::Pixel* getPixel(int x, int y);

protected:
	GameBitmap() {};

};

#endif /* GAMEBITMAP_H_ */

/*
 * GameBitmap.cpp
 *
 *  Created on: 2010-12-10
 *      Author: artur.m
 */

#include "GameBitmap.h"

#include "pi.h"

#include <cstdlib>

#if defined (SHP)
	#include "pi/bada/BadaBitmap.h"
	#include <FGraphics.h>
#elif defined (IOS)
    #include "pi/iOS/iOSBitmap.h"
#else
	#error
#endif

shared_ptr<GameBitmap> GameBitmap::createBitmap(const std::string& fileName)
{
#if defined (SHP)
	return shared_ptr<GameBitmap>(new BadaBitmap(fileName));
#elif defined (IOS)
    return shared_ptr<GameBitmap>(new iOSBitmap(fileName));
#else
	#error
#endif
}

shared_ptr<GameBitmap> GameBitmap::createBitmap(int width, int height)
{
#if defined (SHP)
    return shared_ptr<GameBitmap>(new BadaBitmap(width, height));
#elif defined (IOS)
    return shared_ptr<GameBitmap>(new iOSBitmap(width, height));
#else
    #error
#endif
}

Common::Pixel* GameBitmap::getPixel(int x, int y)
{
    assert(x >= 0 && x <= getWidth());
    assert(y >= 0 && y <= getHeight());
    assert(getByteColorDepth() == 4); // For now works only with 32 bit bitmaps
    
    int index = y*getWidth() + x;
    index *= getByteColorDepth();
    return reinterpret_cast<Common::Pixel*>(getBitmap()+index); // TODO: remove getBitmap 
    // getBitmap adds an unneeded penalty of virtual call
}

typedef void (*OperationFunction)(Common::Pixel*, const Common::Pixel*); 
static void _genericTransform(GameBitmap* target, const GameBitmap* source, OperationFunction fnc, int startX, int startY)
{
    // Cast to enable 'getPixel' - nothing will be changed in source anyway
    GameBitmap* src = const_cast<GameBitmap*>(source);
    // So, now the point to which target bitmap should be copied is known, but it should be done in such
    // a way so it will be cropped instead of writing int out-of-bounds target memory
    for(int j = 0; j < source->getHeight(); ++j)
    {
        if(j+startY >= target->getHeight()) break;
        if(j+startY < 0) continue;
        for(int i = 0; i < source->getWidth(); ++i)
        {
            if(i+startX >= target->getWidth()) break;
            if(i+startX < 0) continue;
            
            (*fnc)(target->getPixel(i+startX, j+startY), src->getPixel(i, j));
        }
    }
}

static void _genericColorTransform(GameBitmap* target, Common::Color color, OperationFunction fnc, int startX, int startY)
{
    Common::Pixel p = { color.r, color.g, color.b, color.a };
    // So, now the point to which target bitmap should be copied is known, but it should be done in such
    // a way so it will be cropped instead of writing int out-of-bounds target memory
    for(int j = startY; j < target->getHeight(); ++j)
    {
        for(int i = startX; i < target->getWidth(); ++i)
        {
            (*fnc)(target->getPixel(i+startX, j+startY), &p);
        }
    }
}

static void _copyOverwrite(Common::Pixel* target, const Common::Pixel* source)
{
    memcpy(target, source, sizeof(Common::Pixel));
}

static void _copyBlend(Common::Pixel* target, const Common::Pixel* source)
{
    target->r = ((255 - source->a) * target->r + source->a * source->r) >> 8;
    target->g = ((255 - source->a) * target->g + source->a * source->g) >> 8;
    target->b = ((255 - source->a) * target->b + source->a * source->b) >> 8;
    target->a = ((255 - source->a) * target->a + source->a * source->a) >> 8;
}

static void _multiply(Common::Pixel* target, const Common::Pixel* source)
{
    target->r = (target->r * (source->a * source->r) >> 8) >> 8;
    target->g = (target->g * (source->a * source->g) >> 8) >> 8;
    target->b = (target->b * (source->a * source->b) >> 8) >> 8;
}

// Overwrites target color, but takes into account the alpha of
// target when doing it.
// TODO: check if 'if' speeds things here or not
static void _overlay(Common::Pixel* target, const Common::Pixel* source)
{
    target->r = (source->r * source->a * target->a) >> 16;
    target->g = (source->g * source->a * target->a) >> 16;
    target->b = (source->b * source->a * target->a) >> 16;
}

void GameBitmap::transformAligned(GameBitmap* target, const GameBitmap* source, BitmapOperation operation,
                             Common::HorizontalAlignment hAlign, Common::VerticalAlignment vAlign)
{
    int targetX = 0;
    int targetY = 0;
    switch(hAlign)
    {
        case Common::HA_LEFT:
            break;
        case Common::HA_RIGHT:
            targetX = target->getWidth() - source->getWidth();
            break;
        case Common::HA_CENTER:
            targetX = (target->getWidth() - source->getWidth()) / 2;
            break;
        default:
            assert(!"Improper enum value");
    };
    switch(vAlign)
    {
        case Common::VA_TOP:
            break;
        case Common::VA_BOTTOM:
            targetY = target->getHeight() - source->getHeight();
            break;
        case Common::VA_CENTER:
            targetY = (target->getHeight() - source->getHeight()) / 2;
            break;
        default:
            assert(!"Improper enum value");
    };
    transform(target, source, operation, targetX, targetY);
}

void GameBitmap::transform(GameBitmap* target, const GameBitmap* source, BitmapOperation operation, int startX, int startY)
{
    switch(operation)
    {
        case BO_COPY_OVERWRITE:
            _genericTransform(target, source, _copyOverwrite, startX, startY);
            break;
        case BO_COPY_BLEND:
            _genericTransform(target, source, _copyBlend, startX, startY);
            break;
        case BO_MULTIPLY:
            _genericTransform(target, source, _multiply, startX, startY);
            break;
        case BO_OVERLAY:
            _genericTransform(target, source, _overlay, startX, startY);
            break;
        default:
            assert(!"Wrong operation value");
    }
}

void GameBitmap::transform(GameBitmap* target, Common::Color color, BitmapOperation operation)
{
    switch(operation)
    {
        case BO_COPY_OVERWRITE:
            _genericColorTransform(target, color, _copyOverwrite, 0, 0);
            break;
        case BO_COPY_BLEND:
            _genericColorTransform(target, color, _copyBlend, 0, 0);
            break;
        case BO_MULTIPLY:
            _genericColorTransform(target, color, _multiply, 0, 0);
            break;
        case BO_OVERLAY:
            _genericColorTransform(target, color, _overlay, 0, 0);
            break;
        default:
            assert(!"Wrong operation value");
    }
}

shared_ptr<GameBitmap> GameBitmap::clone(const shared_ptr<GameBitmap> bitmap)
{
    shared_ptr<GameBitmap> result = createBitmap(bitmap->getWidth(), bitmap->getHeight());
    transform(result.get(), bitmap.get(), BO_COPY_OVERWRITE);
    return result;
}

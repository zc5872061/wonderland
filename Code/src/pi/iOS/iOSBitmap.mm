/*
 * iOSBitmap.mm
 *
 *  Created on: 2011-03-20
 *      Author: Artur Mazurek
 */

#include "iOSBitmap.h"

#include "pi_iOS.h"



iOSBitmap::iOSBitmap(const std::string filename) :
    m_data(null),
    m_width(0),
    m_height(0)
{
    std::string name = filename;
    if(filename.find_last_of("/") != std::string::npos)
    {
        name = filename.substr(filename.find_last_of("/") + 1);
    }
    CGImageRef textureImage = [UIImage imageNamed:[NSString stringWithCString:name.c_str() encoding:[NSString defaultCStringEncoding]]].CGImage;
    
    m_width = CGImageGetWidth(textureImage);
    m_height = CGImageGetHeight(textureImage);
    
    m_data = new unsigned char[m_width * m_height * BYTE_DEPTH];
    
    CGContextRef textureContext = CGBitmapContextCreate(m_data, m_width, m_height, 8, m_width * BYTE_DEPTH, CGImageGetColorSpace(textureImage), kCGImageAlphaPremultipliedLast);
    
    CGContextDrawImage(textureContext, CGRectMake(0, 0, m_width, m_height), textureImage);
    CGContextRelease(textureContext);
    
}

iOSBitmap::iOSBitmap(int width, int height) :
    m_width(width),
    m_height(height)
{
    m_data = new unsigned char[m_width * m_height * BYTE_DEPTH];
    // For testing it is useful to have a non-black and transparent bitmap
//    memset(m_data, 244, m_width * m_height * BYTE_DEPTH);
    // But in general that above looks very ugly
    memset(m_data, 0, m_width * m_height * BYTE_DEPTH);
}

iOSBitmap::~iOSBitmap()
{  
    printf("Deleting iOSBitmp @ %p", this);
    delete [] m_data;
}

unsigned char* iOSBitmap::getBitmap()
{
    return m_data;
}

int iOSBitmap::getWidth() const
{
    return m_width;
}

int iOSBitmap::getHeight() const
{
    return m_height;
}
/*
 * GameCommon.h
 *
 *  Created on: 2011-04-12
 *      Author: artur.m
 *
 *  This file holds declarations of commonly used objects, enumerations etc.
 *  Simple things really. If something is more complicated than a couple fields
 *  and 1-2 methods, or is not generic but specific, consider moving it to a
 *  separate source file.
 *
 *  All should reside in 'Common' namespace
 */
#ifndef _GAME_COMMON_H_
#define _GAME_COMMON_H_

namespace Common
{
    struct Color
    {
        unsigned char r;
        unsigned char g;
        unsigned char b;
        unsigned char a;
        
        Color(unsigned char r = 0, unsigned char g = 0, unsigned char b = 0, unsigned char a = 0) :
            r(r), g(g), b(b), a(a) {
            
        }
        
        Color(const Color& rs) : 
            r(rs.r), g(rs.g), b(rs.b), a(rs.a) {
            
        }
        
        Color& operator=(const Color& rs) {
            r = rs.r;
            g = rs.g;
            b = rs.b;
            a = rs.a;
            return *this;
        }
        
        bool operator==(const Color& rs) {
            return rs.r == r && rs.g == g && rs.b == b && rs.a == a;
        }
        
        bool operator!=(const Color& rs) {
            return !operator==(rs);
        }
    };
    
    // As of now identical to Color, but in the future
    // will be expanded to hold not-only 24bit pixels,
    // so held as separate structure.
    // However I am not sure this is wise since everything we are interested in when
    // talking about a pixel is its color.
    // TODO: rethink it.
    struct Pixel
    {
        unsigned char r;
        unsigned char g;
        unsigned char b;
        unsigned char a;
    };
    
    // Enumeration for drawing precedence of orthogonally drawn objects.
    // And by "orthogonally drawn" it is meant that these are objects rendered
    // by OpenGL using the orthogonal projection matrix.
    // They can be:
    enum DrawLayer
    {
        DL_WRONG_OBJECT, // not valid for precedence because not orthogonally drawn
        DL_BACKGROUND, // drawn behind everything
        DL_FOREGROUND, // drawn before everything, e.g. when it is a hud button
        DL_ENUM_SIZE
    };
    
    enum HorizontalAlignment
    {
        HA_LEFT, // left corner of source will land on the left side of target
        HA_RIGHT, // right corner of source will on the right side of target
        HA_CENTER, // "horizontal source's center" i.e. (left+right)/2 will be on the center line of target
        HA_ENUM_SIZE
    };
    // Basically everything as above but vertically not horizontally
    enum VerticalAlignment
    {
        VA_TOP,
        VA_BOTTOM,
        VA_CENTER,
        VA_ENUM_SIZE
    };
}

#endif // _GAME_COMMON_H_
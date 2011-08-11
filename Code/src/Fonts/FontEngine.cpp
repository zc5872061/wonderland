/*
 * FontEngine.mm
 *
 *  Created on: 2011-04-05
 *      Author: Artur
 */
#include "Fonts/FontEngine.h"

#include "pi.h"
#include "GameFile.h"

#include <stdio.h>
#include <sstream>

static std::string _createKey(const std::string& text, int size)
{
    std::stringstream ss;
    ss << size << text;
    return ss.str();
}
#define CREATE_KEY(text) _createKey(text, m_size)

FontEngine::FontEngine() : 
    m_library(0),
    m_face(0),
    m_size(12),
    m_currentBaseLine(0)
{
    m_fontFaces["BIOS.ttf"] = shared_ptr<GameBitmap>();
}

FontEngine::~FontEngine()
{
    
}

void FontEngine::initialize()
{
    int error = FT_Init_FreeType(&m_library);
    assert(!error && "Everything dies if the fonts cannot be created...");
    
    for(FontFacesContainer::iterator it = m_fontFaces.begin(); it != m_fontFaces.end(); ++it)
    {
        loadFace(it->first);
    }
}

void FontEngine::loadFace(const std::string& fileName)
{
    std::string fullPath = Constants::getRootPath() + Constants::getFontsDir() + fileName;
    
    Log("Opening font at %s", fullPath.c_str());
    
    FT_Face face;
    
    int error = FT_New_Face(m_library, fullPath.c_str(), 0, &face);
    if(error == FT_Err_Unknown_File_Format)
    {
        assert(!"Font file found but with wrong format. Oops.");
    }
    else if(error)
    {
        assert(!"Could not load font file. Bailing out.");
    }
    
    FT_Set_Char_Size(face, 0, m_size*64, Constants::getDpi(), 0);
    //FT_Set_Pixel_Sizes(m_face, 64, 0); // it would be better if this was working...
    
    m_face = face;
}

void FontEngine::setFontSize(int size)
{
    if(size == m_size)
        return;
    
    m_size = size;
    FT_Set_Char_Size(m_face, 0, m_size*64, Constants::getDpi(), 0);
}

shared_ptr<GameBitmap> FontEngine::getFontBitmap(const std::string& text)
{
    if(m_fontFaces.find(CREATE_KEY(text)) == m_fontFaces.end())
    {
        prepareGlyphs(text);
        shared_ptr<GameBitmap> result = createValidBitmap();
        renderGlyphs(result);
        m_fontFaces[CREATE_KEY(text)] = result;
        destroyGlyphs();
    }
    return m_fontFaces[CREATE_KEY(text)];
}

shared_ptr<GameBitmap> FontEngine::getFontBitmapPositioned(const std::string& text,
                                                           int width, int height,
                                                           Common::HorizontalAlignment hAlign,
                                                           Common::VerticalAlignment vAlign)
{
    Common::Color color;
    color.r = 255;
    color.g = 255;
    color.b = 255;
    color.a = 255;
    
    return getFontBitmapPositioned(text, width, height, hAlign, vAlign, color);
}

shared_ptr<GameBitmap> FontEngine::getFontBitmapPositioned(const std::string& text,
                                                           int width, int height,
                                                           Common::HorizontalAlignment hAlign,
                                                           Common::VerticalAlignment vAlign,
                                                           const Common::Color& color)
{
    shared_ptr<GameBitmap> pure = getFontBitmap(text);
    shared_ptr<GameBitmap> result = GameBitmap::createBitmap(width, height);
    
    GameBitmap::transformAligned(result.get(), pure.get(), GameBitmap::BO_COPY_OVERWRITE, hAlign, vAlign);
    if(!(color.r == 255 && color.g == 255 && color.b == 255))
    {
        GameBitmap::transform(result.get(), color, GameBitmap::BO_MULTIPLY);
    }
    
    return result;
}

void FontEngine::copyBitmap(const FT_Bitmap* source, shared_ptr<GameBitmap> target, int x, int y)
{
    const int width = source->width;
    const int height = source->rows;
    
    assert(width + x <= target->getWidth());
    assert(height + y <= target->getHeight());
    
    Common::Pixel* p = null;
    
	for (int j = 0; j < height; j++)
	{
		for (int i = 0; i < width; i++)
		{
            p = target->getPixel(i + x, j + y);
            memset(p, source->buffer[j*width + i], sizeof(Common::Pixel));
		}
	}
}

void FontEngine::prepareGlyphs(const std::string& source)
{
    for(size_t i = 0; i < source.size(); ++i)
    {
        FT_UInt glyphIndex = FT_Get_Char_Index(m_face, source[i]);
        int error = FT_Load_Glyph(m_face, glyphIndex, FT_LOAD_DEFAULT);
        assert(!error);
        
        FT_Glyph glyph;
        error = FT_Get_Glyph(m_face->glyph, &glyph);
        assert(!error);
        
        GlyphData gd = {glyph, {0, 0, 0, 0}};
        m_glyphs.push_back(gd);
    }
}

shared_ptr<GameBitmap> FontEngine::createValidBitmap()
{
    assert(m_glyphs.size() != 0);
    int width = 0;
    int height = 0;
    int lastWidth = 0;
    m_currentBaseLine = 0;
    FT_BBox bounds;
    
    int yMax = 0; // the max bounds.yMax in the set
    int yMin = 0; // the min bounds.yMin in the 
    
    // What happens here is that for every bitmap it's width is calculated
    // and added to the total width, to get the proper horizontal size of the bitmap
    // needed.
    // Also the extremal values of bounds.yMax and .yMin are found to get the proper
    // height of the bitmap.
    // Later on, after the loop they will be calculated.
    GlyphsContainer::iterator end = m_glyphs.end();
    for(GlyphsContainer::iterator it = m_glyphs.begin(); it != end; ++it)
    {
        // Glyph has to converted to bitmap first, to have proper metrics while
        // taking the bounds.
        int error = FT_Glyph_To_Bitmap(&((*it).glyph), FT_RENDER_MODE_NORMAL, null, 1);
        assert(!error);
        
        FT_Glyph_Get_CBox((*it).glyph, FT_GLYPH_BBOX_TRUNCATE, &bounds);
        (*it).bounds = bounds; // save for later, to be used while copying fonts' bitmaps
                                // to the target bitmap
        
        int currentWidth = bounds.xMax - bounds.xMin;
        
        if(currentWidth == 0)
        {
            width += lastWidth >> 2;
        }
        else
        {
            lastWidth = currentWidth;
        }
        
        width += currentWidth;
        if(bounds.xMin <= 0) width += 1; // to make it counted from 0;
        
        Log("Current bounds are: %ld, %ld", bounds.yMax, bounds.yMin);
        yMax = yMax > bounds.yMax ? yMax : bounds.yMax;
        yMin = yMin < bounds.yMin ? yMin : bounds.yMin;
    }
    // And the current baseline that should be counted from top
    m_currentBaseLine = yMax;
    
    width += m_glyphs.size() - 1; // To have 1 pixel distance between numbers
    height = yMax - yMin;

    return GameBitmap::createBitmap(width, height);
}

void FontEngine::renderGlyphs(shared_ptr<GameBitmap> target)
{
    int advance = 0;
    int lastWidth = 0;
    
    GlyphsContainer::iterator end = m_glyphs.end();
    for(GlyphsContainer::iterator it = m_glyphs.begin(); it != end; ++it)
    {
        FT_BitmapGlyph bitmapGlyph = reinterpret_cast<FT_BitmapGlyph>((*it).glyph);
        if(bitmapGlyph->bitmap.width != 0)
        {
            copyBitmap(&(bitmapGlyph->bitmap), target, advance, m_currentBaseLine - (*it).bounds.yMax);
            
            advance += bitmapGlyph->bitmap.width;
            lastWidth = bitmapGlyph->bitmap.width;
        }
        else
        {
            // If the bitmap is empty (i.e. space character) we want it to be
            // the width of previous character / 4.
            advance += lastWidth >> 2;
        }
    }
}

void FontEngine::destroyGlyphs()
{
    for(GlyphsContainer::iterator it = m_glyphs.begin(); it != m_glyphs.end(); ++it)
    {
        FT_Done_Glyph((*it).glyph);
    }
    m_glyphs.clear();
}

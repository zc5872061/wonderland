/*
 * FontEngine.h
 *
 *  Created on: 2011-04-05
 *      Author: Artur
 */
#ifndef _FONT_ENGINE_H_
#define _FONT_ENGINE_H_

extern "C"
{
    #include <ft2build.h>
    #include FT_FREETYPE_H
    #include FT_GLYPH_H
}

#include <map>
#include <string>
#include <vector>

#include "GameBitmap.h"
#include "shared_ptr.h"

class FontEngine
{
public:
    friend class Game;
    
    void initialize();
    
    // Gets a bitmap which size is exactly the size of rendered text
    // So returns a 'pure' rendered text
    shared_ptr<GameBitmap> getFontBitmap(const std::string& text);
    // Gets a bitmap with rendered text which is already placed to proper place
    // and positioned accordingly to the given enums.
    // If the text would extend beyond borders of (width, height) it will be automatically
    // cropped.
    shared_ptr<GameBitmap> getFontBitmapPositioned(const std::string& text,
                                                   int width, int height,
                                                   Common::HorizontalAlignment hAlign,
                                                   Common::VerticalAlignment vAlign);
    shared_ptr<GameBitmap> getFontBitmapPositioned(const std::string& text,
                                                   int width, int height,
                                                   Common::HorizontalAlignment hAlign,
                                                   Common::VerticalAlignment vAlign,
                                                   const Common::Color& color);
    
    // Sets the size of font to some arbitrary-counted value...
    // TODO - make it to be real pixels
    void setFontSize(int size);
    int getFontSize() const { return m_size; }
    
private:
    FT_Library m_library;
    FT_Face m_face;
    
    typedef std::map<std::string, shared_ptr<GameBitmap> > FontFacesContainer;
    FontFacesContainer m_fontFaces;
    
    struct GlyphData
    {
        FT_Glyph glyph;
        FT_BBox bounds;
    };
    
    typedef std::vector<GlyphData> GlyphsContainer;
    GlyphsContainer m_glyphs;
    
    int m_size;
    // The distance in pixels from the current bitmap's top border
    // to the font baseline, i.e. the line to which all the separate
    // glyph bitmaps should be aligned.
    int m_currentBaseLine;
    
private:
    void loadFace(const std::string& fileName);
    // Copies data from source bitmap onto target bitmap, overriding everything that was
    // there previously. Puts top left corner of source to point x,y in target,
    // doesn't check if there is enough space
    void copyBitmap(const FT_Bitmap* source, shared_ptr<GameBitmap> target, int x, int y);
    // Gets glyphs for all the characters from the string and puts them to m_glyphs;
    void prepareGlyphs(const std::string& source);
    // Creates a bitmap which size is enough to hold all the rendered glyphs that are
    // held in m_glyphs
    shared_ptr<GameBitmap> createValidBitmap();
    // Renders all the glyphs from m_glyphs to the supplied texture. Tries to do it properly...
    void renderGlyphs(shared_ptr<GameBitmap> target);
    // Destroys all the glyphs that are held in m_glyphs
    void destroyGlyphs();
    
    FontEngine();
    ~FontEngine();
    FontEngine(const FontEngine&);
    FontEngine& operator=(const FontEngine&);
};

#endif // _FONT_ENGINE_H_
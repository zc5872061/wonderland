/*
 * GameLabel.cpp
 *
 *  Created on: 2011-01-10
 *      Author: artur.m
 */

#include "HUD/GameLabel.h"
#include "HUD/HUD.h"
#include "Game.h"
#include "HUD/GamePanel.h"
#include "Fonts/FontEngine.h"
#include "GameBitmap.h"

#include <sstream>
#include <cstring>

int GameLabel::s_instances(0);

shared_ptr<GameLabel> GameLabel::spawn(const Rectangle& rect)
{
    return Actor::initialize(new GameLabel(rect));
}

GameLabel::GameLabel(const Rectangle& bounds) :
	GameControl(bounds.x, bounds.y, bounds.width, bounds.height),
    m_hAlign(Common::HA_LEFT),
    m_vAlign(Common::VA_TOP),
    m_fontSize(12)
{
    ++s_instances;
    
    memset(&m_color, 255, sizeof(Common::Color));
    
    std::stringstream ss;
    ss << "GameLabel";
    ss << s_instances;
    m_bitmapId = ss.str();
    
    setHidden(true);
}

GameLabel::~GameLabel()
{
    cleanOldText();
}

void GameLabel::setText(const std::string& text)
{
	cleanOldText();
	m_text = text;
    if(m_text == "") 
    {
        setHidden(true);
        return;
    }
    setHidden(false);
    
    createBitmap();
    getModel().getElement()->getMaterialInstance()->setValue("u_textureSampler", m_bitmapId);
}

void GameLabel::cleanOldText()
{
    if(m_text == "")
        return;
    
    Game::getInstance().getResourceManager().unregisterBitmap(m_bitmapId);
    m_text = "";
}

const std::string& GameLabel::getText() const
{
	return m_text;
}


void GameLabel::setTextVerticalAlignment(Common::VerticalAlignment align)
{
    setTextAlignment(getTextHorizontalAlignment(), align);
}

void GameLabel::setTextHorizontalAlignment(Common::HorizontalAlignment align)
{
    setTextAlignment(align, getTextVerticalAlignment());
}

void GameLabel::setTextAlignment(Common::HorizontalAlignment hAlign, Common::VerticalAlignment vAlign)
{
    m_hAlign = hAlign;
    m_vAlign = vAlign;
    
    if(m_text == "")
        return;
    
    createBitmap();
}

void GameLabel::createBitmap()
{
    Game::getInstance().getFontEngine().setFontSize(m_fontSize);
    
    shared_ptr<GameBitmap> rendered = Game::getInstance().\
        getFontEngine().getFontBitmapPositioned(m_text, getBounds().width, getBounds().height,m_hAlign, m_vAlign);
    
    Game::getInstance().getResourceManager().registerBitmap(rendered, m_bitmapId);
    
    if(m_color != Common::Color(255, 255, 255, 255))
        updateColor();
}

void GameLabel::setTextColor(unsigned char r, unsigned char g, unsigned char b)
{
    m_color.r = r;
    m_color.g = g;
    m_color.b = b;
    m_color.a = 255;
    
    updateColor();
}

void GameLabel::updateColor()
{
    if(m_text == "")
        return;
    
    // To colorize the bitmap the following idea is used (because OpenGL has these bitmaps
    // somwhere on his own):
    // Bitmap shared_ptr is taken from ResourceManager, it is multiplied to wanted color
    // and the same bitmap is registered again, under the same name in resource manager.
    // That effectively deletes old OpenGL's bitmap and puts the painted version of the
    // old one into the cache
    
    ResourceManager& mgr = Game::getInstance().getResourceManager();
    shared_ptr<GameBitmap> myBitmap = mgr.getBitmap(m_bitmapId);
    
    GameBitmap::transform(myBitmap.get(), m_color, GameBitmap::BO_OVERLAY);
    mgr.registerBitmap(myBitmap, m_bitmapId);
}

void GameLabel::setFontSize(int size)
{
    if(size == m_fontSize)
    {
        return;
    }
    createBitmap();
}

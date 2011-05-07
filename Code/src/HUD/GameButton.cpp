/*
 * GameButton.cpp
 *
 *  Created on: 2011-01-03
 *      Author: artur.m
 */

#include "HUD/GameButton.h"

#include "ResourceManager.h"
#include "Game.h"
#include "GameCommon.h"

#include <algorithm>
#include <cstring>
#include <sstream>

const std::string GameButton::DEFAULT_NORMAL_BITMAP("button.png");
const std::string GameButton::TYPE("GameButton");
const std::string GameButton::ELEMENT_NAME("GameButtonElement");
int GameButton::s_instances = 0;

// Helper macro to set material to have proper texture sampler depending on whether
// the button is pressed or not.
#define SET_BITMAP() \
    { getModel().getElement()->getMaterialInstance()->setValue("u_textureSampler", m_pressed ? m_pressedBitmap : m_normalBitmap); }

shared_ptr<GameButton> GameButton::spawn(const Rectangle& rect)
{
    return Actor::initialize(new GameButton(rect));
}

GameButton::GameButton(const Rectangle& rect) :
	GameControl(rect.x, rect.y, rect.width, rect.height),
	m_pressed(false),
    m_textSize(12)
{
    memset(&m_color, 255, sizeof(Common::Color));
    
    std::stringstream ss;
    ss << s_instances++ << TYPE;
    m_textBitmap = ss.str();
    
	setNormalBitmap(DEFAULT_NORMAL_BITMAP);
	setPressedBitmap(DEFAULT_NORMAL_BITMAP);
    SET_BITMAP();
}

GameButton::~GameButton()
{

}

void GameButton::addActionListener(ActionListener* listener)
{
	assert(std::find(m_listeners.begin(), m_listeners.end(), listener) == m_listeners.end());
	m_listeners.push_back(listener);
}

void GameButton::setNormalBitmap(const std::string& bitmap)
{
    m_normalBitmap = bitmap;
    SET_BITMAP();
}

void GameButton::setPressedBitmap(const std::string& bitmap)
{
    m_pressedBitmap = bitmap;
    SET_BITMAP();
}

void GameButton::notifyListeners()
{
	for(ListenersIter it = m_listeners.begin(); it != m_listeners.end(); ++it)
	{
		(*it)->onActionPerformed(this, m_actionId);
	}
}

bool GameButton::isPressed() const
{
	return m_pressed;
}

void GameButton::setPressed(bool pressed)
{
	if(!isEnabled())
	{
		return;
	}
    if(m_pressed == pressed)
    {
        return;
    }
	m_pressed = pressed;
    SET_BITMAP();
}

bool GameButton::touchPressed(int x, int y)
{
	bool pressed = GameControl::touchPressed(x, y);
	setPressed(pressed);
	return pressed;
}

bool GameButton::touchReleased(int x, int y)
{
	setPressed(false);
	return GameControl::touchReleased(x, y);
}

void GameButton::execute()
{
	if(isEnabled())
	{
		notifyListeners();
	}
}

void GameButton::setActionId(const std::string& actionId)
{
	m_actionId = actionId;
}

std::string GameButton::getActionId() const
{
	return m_actionId;
}

void GameButton::setText(const std::string& text)
{
    if(text == m_text)
        return;

    m_text = text;
    
    createBitmap();
}

void GameButton::setTextColor(unsigned char r, unsigned char g, unsigned char b)
{    
    setTextColor(Common::Color(r, g, b, 255));
}

void GameButton::setTextColor(const Common::Color& color)
{
    if(m_color == color)
        return;
    
    m_color = color;
    
    updateTextColor();
}

void GameButton::updateTextColor()
{
    if(m_text == "")
        return;
    
    // Here the same idea is used as in GameLabel, however
    // I had no idea how to reuse that code in an other way than
    // copy-pasting, so it is copy-pasted
    ResourceManager& mgr = Game::getInstance().getResourceManager();
    shared_ptr<GameBitmap> myBitmap = mgr.getBitmap(m_textBitmap);
    
    GameBitmap::transform(myBitmap.get(), m_color, GameBitmap::BO_OVERLAY);
    mgr.registerBitmap(myBitmap, m_textBitmap);
}

void GameButton::setTextSize(int size)
{
    if(size == m_textSize)
        return;
    
    m_textSize = size;
    
    createBitmap();
}

void GameButton::createBitmap()
{
    Game::getInstance().getFontEngine().setFontSize(m_textSize);
    
    // Get the bitmap with rendered text from the font engine
    shared_ptr<GameBitmap> textBmp = Game::getInstance().\
    getFontEngine().getFontBitmapPositioned(m_text, getBounds().width, getBounds().height, Common::HA_CENTER, Common::VA_CENTER);
    
    // If the link to the base mesh of GameControl wasn't yet done
    // it should be prepared now
    if(!getModel().hasElement(ELEMENT_NAME))
    {
        getModel().addElementLink(ELEMENT_NAME, getModel().getElement()->getName());
        
        MaterialInstance* mInst = getModel().getElement(ELEMENT_NAME)->getMaterialInstance();
        mInst->setMaterialName("hud");
        mInst->setValue("u_textureSampler", m_textBitmap);
    }
    
    if(m_color != Common::Color(255, 255, 255, 255))
        GameBitmap::transform(textBmp.get(), m_color, GameBitmap::BO_OVERLAY);
    
    // Re-register the bitmap to update stuff
    Game::getInstance().getResourceManager().registerBitmap(textBmp, m_textBitmap);
}

void GameButton::onAddedToHud()
{
    // TODO: implement lazy initialization which will be fired here
}

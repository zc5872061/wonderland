/*
 * GamePanel.cpp
 *
 *  Created on: 2011-01-10
 *      Author: artur.m
 */

#include "HUD/GamePanel.h"

shared_ptr<GamePanel> GamePanel::spawn(const Rectangle& bounds)
{
    return Actor::initialize(new GamePanel(bounds));
}

GamePanel::GamePanel(const Rectangle& bounds) :
	GameControl(bounds.x, bounds.y, bounds.width, bounds.height)
{
    ignoreTrace(true);
}

GamePanel::~GamePanel()
{

}

const std::string& GamePanel::getBitmap() const
{
	return m_bitmap;
}

void GamePanel::setBitmap(const std::string& bitmap)
{
	m_bitmap = bitmap;
    getModel().getElement()->getMaterialInstance()->setValue("u_textureSampler", m_bitmap);
}

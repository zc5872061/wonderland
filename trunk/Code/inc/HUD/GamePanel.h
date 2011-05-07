/*
 * GamePanel.h
 *
 *  Created on: 2011-01-10
 *      Author: artur.m
 */

#ifndef GAMEPANEL_H_
#define GAMEPANEL_H_

#include "HUD/GameControl.h"
#include "MathHelper.h"

#include <string>

class GamePanel : public GameControl
{
public:
	static shared_ptr<GamePanel> spawn(const Rectangle& bounds);
	virtual ~GamePanel();
    
    virtual std::string getType() const { return "GamePanel"; }

	void setBitmap(const std::string& bitmap);
    const std::string& getBitmap() const;

private:
    GamePanel(const Rectangle& bounds);
    
private:
	std::string m_bitmap;
};

#endif /* GAMEPANEL_H_ */

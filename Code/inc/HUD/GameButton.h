/*
 * GameButton.h
 *
 *  Created on: 2011-01-03
 *      Author: artur.m
 */

#ifndef GAMEBUTTON_H_
#define GAMEBUTTON_H_

#include "GameControl.h"

#include "pi.h"
#include "GameBitmap.h"
#include "MathHelper.h"
#include "shared_ptr.h"

#include <vector>
#include <string>
#include <memory>

class GameLabel;

class GameButton : public GameControl
{
public:
	friend class HUD;

	static const std::string DEFAULT_NORMAL_BITMAP;
    static const std::string TYPE;
    virtual std::string getType() const { return TYPE; }

    static shared_ptr<GameButton> spawn(const Rectangle& rect);
	virtual ~GameButton();

	void addActionListener(ActionListener* listener);
	void setNormalBitmap(const std::string& bitmap);
	void setPressedBitmap(const std::string& bitmap);

	bool isPressed() const;

	virtual bool touchPressed(int x, int y);
	virtual bool touchReleased(int x, int y);

	void setActionId(const std::string& actionId);
	std::string getActionId() const;
    
    std::string getText() const { return m_text; }
    void setText(const std::string& text);

    void setTextColor(unsigned char r, unsigned char g, unsigned char b);
    void setTextColor(const Common::Color& color);
    Common::Color getTextColor() const { return m_color; }
    
    void setTextSize(int size);
    int getTextSize() const { return m_textSize; }
    
private:
    GameButton(const Rectangle& rect); // TODO: add a text here ;)
    
    // When something regarding text is changed (size, color)
    // Text painting should be re-done.
    void updateTextColor();
    // Creates the new bitmap with rendered text and paints it to proper
    // color.
    void createBitmap();
    
private:
    static int s_instances;
    static const std::string ELEMENT_NAME;
    
	void notifyListeners();
	void setPressed(bool pressed);
    
    void onAddedToHud();
	void execute();

	typedef std::vector<ActionListener*> ListenersContainer;
	typedef ListenersContainer::iterator ListenersIter;
	ListenersContainer m_listeners;

    // These are bitmaps that are really used by the GameButton
    // i.e. bitmaps it copied and copied text over it
	std::string m_normalBitmap; 
	std::string m_pressedBitmap;
    // The name of the bitmap that will be created to hold text
    std::string m_textBitmap;
    
	std::string m_actionId;
    
    std::string m_text;

	GLfloat m_pressedUvs[8];

	bool m_pressed;
    
    Common::Color m_color;
    int m_textSize;
};

#endif /* GAMEBUTTON_H_ */

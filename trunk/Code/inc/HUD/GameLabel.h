/*
 * GameLabel.h
 *
 *  Created on: 2011-01-10
 *      Author: artur.m
 */

#ifndef GAMELABEL_H_
#define GAMELABEL_H_

#include "GameControl.h"
#include "GamePanel.h"
#include "MathHelper.h"
#include "GameBitmap.h"
#include "GameCommon.h"

#include <string>
#include <vector>
#include <memory>

class GamePanel;

class GameLabel : public GameControl
{
public:
    virtual std::string getType() const { return "GameLabel"; }
    
	static shared_ptr<GameLabel> spawn(const Rectangle& rect);
	virtual ~GameLabel();

	void setText(const std::string& text);
	const std::string& getText() const;
    
    void setTextVerticalAlignment(Common::VerticalAlignment align);
    Common::VerticalAlignment getTextVerticalAlignment() const { return m_vAlign; }
    
    void setTextHorizontalAlignment(Common::HorizontalAlignment align);
    Common::HorizontalAlignment getTextHorizontalAlignment() const { return m_hAlign; }
    
    void setTextAlignment(Common::HorizontalAlignment hAlign, Common::VerticalAlignment vAlign);
    
    void setTextColor(unsigned char r, unsigned char g, unsigned char b);
    Common::Color getTextColor() const { return m_color; }
    
    int getTextSize() const { return m_fontSize; }
    void setFontSize(int size);

private:
    GameLabel(const Rectangle& bounds);
    
	void initialize();
	void cleanOldText();
    // Creates the bitmap which holds the rendered by FreeType text
    void createBitmap();
    // Updates the color of the text in the rendered bitmap
    void updateColor();
    
private:
    static int s_instances;
    
	std::string m_text;
    std::string m_bitmapId;

    Common::HorizontalAlignment m_hAlign;
    Common::VerticalAlignment m_vAlign;
    
    Common::Color m_color;
    int m_fontSize;
};

#endif /* GAMELABEL_H_ */

/*
 * Control.h
 *
 *  Created on: 2010-12-23
 *      Author: artur.m
 */

#ifndef GAME_CONTROL_H_
#define GAME_CONTROL_H_

#include "pi.h"

#include "MathHelper.h"
#include "Engine/BasicMesh.h"
#include "Actor.h"

#include <string>

class CreatedMesh;

class GameControl : public Actor
{
public:
	friend class HUD;
    virtual std::string getType() const { return "GameControl"; }

	virtual ~GameControl();

	virtual const GLfloat* getUVs();

	void setBounds(const Rectangle& rect); 
	Rectangle getBounds() const;

	bool isEnabled() const;
	void setEnabled(bool value);

protected:
	GameControl(int x, int y, int width, int height);

	void prepareVertices();
	void prepareUVs(GLfloat* target, GLfloat u = 0.0f, GLfloat v = 0.0f, GLfloat ul = 1.0f, GLfloat vl = 1.0f);

	virtual bool touchPressed(int x, int y);
	virtual bool touchReleased(int x, int y);
	virtual void execute() {};
    
    virtual void onAddedToHud() {}
    virtual void onRemovedFromHud() {}
    bool isAddedToHud() const { return m_added; }

	Rectangle m_bounds;
	Rectangle m_originalBounds;

	GLfloat m_uvs[8]; // 4 vertices * 2 values

private:
    // Made private to give access to it only to the Game object
    void addedToHud() { m_added = true; onAddedToHud(); }
    void removedFromHud() { m_added = false; onRemovedFromHud(); }
    
private:
    static int s_instances;
	bool m_enabled;
    bool m_added;
};

class ActionListener
{
public:
	virtual void onActionPerformed(GameControl* source, const std::string& actionId) = 0;
};

#endif /* GAME_CONTROL_H_ */

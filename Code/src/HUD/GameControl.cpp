/*
 * Control.cpp
 *
 *  Created on: 2010-12-23
 *      Author: artur.m
 */

#include "HUD/GameControl.h"

#include "Game.h"
#include "GameCommon.h"

int GameControl::s_instances = 0;

GameControl::GameControl(int x, int y, int width, int height) :
    Actor(Vector(), true),
	m_enabled(true)
{
    // set bounds will prepare the mesh. This has to be done there because every time
    // the bounds are changed there is a posibility that mesh modifications will be needed
	setBounds(Rectangle(x, y, width, height));

    getModel().getElement()->getMaterialInstance()->setMaterialName("hud");
    getModel().getElement()->getMaterialInstance()->setValue("u_enabled", 1.0f);
    getModel().getElement()->getMaterialInstance()->setValue("u_textureSampler", "dummy");
    setDrawLayer(Common::DL_FOREGROUND);
}

GameControl::~GameControl()
{
	Game::getInstance().getMeshManager().destroyMesh(getModel().getElement()->getMeshName());
}

void GameControl::prepareVertices()
{
	memset(m_uvs, 0, sizeof(m_uvs));
    // TODO - make it don't create new meshes all the time!
    if(getModel().getElementsCount() == 0)
    {
        getModel().addElement("mainMesh", Game::getInstance().getMeshManager().createHUDPanel(m_bounds));
    }
    else
    {
        getModel().setMesh(Game::getInstance().getMeshManager().createHUDPanel(m_bounds), 0);
    }

	prepareUVs(m_uvs);
}

const GLfloat* GameControl::getUVs()
{
	return m_uvs;
}

void GameControl::setBounds(const Rectangle& rect)
{
	m_originalBounds = rect;
	m_bounds = rect;

	// index 0 is bottom left in the plane actually. This is a bit unfortunate
	// and since opengl counts from bottom left and we want top left corner of the screen as
	// (0, 0) there is this annoying transformation going for y coordinate
	int height = Game::getInstance().getHUD().getHeight();
	if(!Game::getInstance().getHUD().flipUi())
	{
		m_bounds.y = height - m_bounds.y - m_bounds.height;
	}

	if(Game::getInstance().getHUD().flipUi())
	{
		Rectangle tempRect;
		tempRect.x = m_bounds.y;
		tempRect.y = m_bounds.x;
		tempRect.width = m_bounds.height;
		tempRect.height = m_bounds.width;

		m_bounds = tempRect;
	}

	prepareVertices();
}

Rectangle GameControl::getBounds() const
{
	return m_originalBounds; // return the untransformed bounds
}

bool GameControl::isEnabled() const
{
	return m_enabled;
}

void GameControl::setEnabled(bool value)
{
	m_enabled = value;
}

void GameControl::prepareUVs(GLfloat* target, GLfloat u, GLfloat v, GLfloat ul, GLfloat vl)
{
	if(!Game::getInstance().getHUD().flipUi())
	{
		target[0] = u; 		target[1] = (v + vl);
		target[2] = u + ul; 	target[3] = (v + vl);
		target[4] = u + ul; 	target[5] = v;
		target[6] = u; 		target[7] = v;
	}
	else
	{
		target[0] = u; 		target[1] = v;
		target[2] = u; 		target[3] = v + vl;
		target[4] = u + ul; 	target[5] = v + vl;
		target[6] = u + ul; 	target[7] = v;
	}
}

bool GameControl::touchPressed(int x, int y)
{
    //Picking should be checked against the original bounds,
    //i.e. the bounds that weren't messed up with to display stuff properly
    //but with those bounds that were given from client code.
	if(getBounds().isInside(x, y))
	{
		return true;
	}
	return false;
}

bool GameControl::touchReleased(int x, int y)
{
    //Picking should be checked against the original bounds,
    //i.e. the bounds that weren't messed up with to display stuff properly
    //but with those bounds that were given from client code.
	if(getBounds().isInside(x, y))
	{
		return true;
	}
	return false;
}

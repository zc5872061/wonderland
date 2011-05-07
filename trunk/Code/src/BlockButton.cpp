/*
 * BlockButton.cpp
 *
 *  Created on: 2011-02-08
 *      Author: Artur
 */

#include "BlockButton.h"

#include <algorithm>

shared_ptr<BlockButton> BlockButton::spawn(const Vector& position)
{
    return Actor::initialize(new BlockButton(position));
}

const std::string BlockButton::MESH_NAME("buttonMesh_iOS");

BlockButton::BlockButton(const Vector& position) :
	StaticMesh(position, MESH_NAME),
	m_selected(false)
{
    // We are interested in modifing the mesh thath was created by GameControl,
    // so we are asking for the default one (no arguments)
    getModel().getElement()->getMaterialInstance()->setMaterialName("default");
	getModel().getElement()->getMaterialInstance()->setValue("u_diffuseColor", Vector(1.0f, 0.4f, 0.4f));
}

BlockButton::~BlockButton()
{

}


void BlockButton::fireListeners()
{
	for(ListenersIter it = m_listeners.begin(); it != m_listeners.end(); ++it)
	{
		(*it)->actionPerformed(this, m_action);
	}
}

void BlockButton::addListener(BlockButtonListener* listener)
{
	assert(std::find(m_listeners.begin(), m_listeners.end(), listener) == m_listeners.end());
	m_listeners.push_back(listener);
}

void BlockButton::update(int milis)
{

}

void BlockButton::touched(const Actor* target, const Vector& touchPoint)
{
	if(target == this)
	{
		m_selected = true;
		m_originalPos = getPosition();
		setPosition(m_originalPos + Vector(0, 0, -0.5f));
	}
}

void BlockButton::released(const Actor* target, const Vector& touchPoint)
{
	bool wasSelected = m_selected;
	m_selected = false;
	if(wasSelected)
	{
		setPosition(m_originalPos);
		if(target == this)
		{
			fireListeners();
		}
	}
}

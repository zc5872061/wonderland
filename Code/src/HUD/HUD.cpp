/*
 * HUD.cpp
 *
 *  Created on: 2010-12-23
 *      Author: artur.m
 */

#include "HUD/HUD.h"

#include "pi.h"
#include "Game.h"
#include "HUD/GamePanel.h"

#include <algorithm>

const std::string HUD::DEFAULT_STATE_NAME("DefaultState");

HUD::HUD() :
    m_pressedControl(null),
#if defined (SHP) // TODO - is this UI flip really needed? This is actually quite strange
    m_flipUI(false),
#elif defined (IOS)
	m_flipUI(false),
#else
    #error
#endif
	m_valid(true)
{
    m_width = Constants::SCREEN_NARROW;
    m_height = Constants::SCREEN_WIDE;
	registerState(DEFAULT_STATE_NAME);
	setState(DEFAULT_STATE_NAME);
}

HUD::~HUD()
{
	m_valid = false;
}

void HUD::initialize()
{
	onInitializing();
}

void HUD::addControl(shared_ptr<GameControl> control)
{
	assert(std::find(m_states[m_currentState].controls.begin(), m_states[m_currentState].controls.end(), control) == m_states[m_currentState].controls.end());
	m_states[m_currentState].controls.push_back(control);
    // All controls are added as hidden, but later on are set visible when hud enters proper state
    control->setHidden(true);
    control->addedToHud();
}

void HUD::removeControl(shared_ptr<GameControl> control)
{
	if(!m_valid)
	{
		return;
	}
	for(StatesIter it = m_states.begin(); it != m_states.end(); ++it)
	{
		if((*it).second.controls.size() == 0)
		{
			continue;
		}

		ControlsIter begin = (*it).second.controls.begin();
		ControlsIter end = (*it).second.controls.end();
		ControlsContainer& container = (*it).second.controls;
		ControlsIter toDelete = std::find(begin, end, control);
		if(toDelete == container.end())
		{
			continue;
		}
		container.erase(std::find(begin, end, control));
        control->removedFromHud();
        Actor::destroy(control);
        return;
	}
}

void HUD::drawPlane(BasicMesh* mesh, const std::string& textureName)
{
	glUniform1i(m_hudProgram->getLocation(Program::UNIFORM_SAMPLER2D), 0);
	glBindTexture(GL_TEXTURE_2D, Game::getInstance().getResourceManager().getBitmapId(textureName));

	glVertexAttribPointer(m_hudProgram->getLocation(Program::ATTRIBUTE_POSITION), 3, GL_FLOAT, GL_FALSE, 0/*3 * sizeof(GLfloat)*/, mesh->getVertices());
	glVertexAttribPointer(m_hudProgram->getLocation(Program::ATTRIBUTE_UV), 2, GL_FLOAT, GL_FALSE, 0/*2 * sizeof(GLfloat)*/, mesh->getUVs()); // uvs need to be taken from the control

	glEnableVertexAttribArray(m_hudProgram->getLocation(Program::ATTRIBUTE_POSITION));
	glEnableVertexAttribArray(m_hudProgram->getLocation(Program::ATTRIBUTE_UV));

	glDrawElements(GL_TRIANGLES, mesh->getIndicesCount(), GL_UNSIGNED_SHORT, mesh->getIndices());
}

bool HUD::touchPressed(int x, int y)
{
	for(ControlsIter it = m_states[m_currentState].controls.begin(); it != m_states[m_currentState].controls.end(); ++it)
	{
        if((*it)->isIgnoreTrace())
            continue;
        if((*it)->getDrawLayer() == Common::DL_BACKGROUND)
            continue; // only foreground stuff can be touched for now...
		if((*it)->touchPressed(x, y))
		{
            m_pressedControl = (*it).get();
            return true;
		}
	}
	return false;
}

bool HUD::touchReleased(int x, int y)
{
	GameControl* releasedControl = null;
	for(ControlsIter it = m_states[m_currentState].controls.begin(); it != m_states[m_currentState].controls.end(); ++it)
	{
        if((*it)->isIgnoreTrace())
            continue;
        if((*it)->getDrawLayer() == Common::DL_BACKGROUND)
            continue; // only foreground stuff can be touched for now...
		if((*it)->touchReleased(x, y))
		{
			releasedControl = (*it).get();
		}
	}
	if(releasedControl && releasedControl == m_pressedControl)
	{
		releasedControl->execute();
		m_pressedControl = null;
		return true;
	}
	m_pressedControl = null;
	return false;
}

int HUD::getWidth() const
{
	return m_width;
}

int HUD::getHeight() const
{
	return m_height;
}

void HUD::registerState(const std::string& stateName)
{
	assert(m_states.find(stateName) == m_states.end());
	m_states[stateName].controls = ControlsContainer();
}

void HUD::setCurrentStateHidden(bool hidden)
{
    HUDState& current = m_states[m_currentState];
    for(ControlsIter it = current.controls.begin(); it != current.controls.end(); ++it)
    {
        (*it)->setHidden(hidden);
    }
}

void HUD::setState(const std::string& stateName)
{
    setCurrentStateHidden(true);
	assert(m_states.find(stateName) != m_states.end());
	m_currentState = stateName;
    setCurrentStateHidden(false);
}

void HUD::setBackgroundImage(const std::string& fileName)
{
    if(m_states[m_currentState].background.get() == null)
    {
        m_states[m_currentState].background = GamePanel::spawn(Rectangle(0, 0, m_width, m_height));
        m_states[m_currentState].background->setDrawLayer(Common::DL_BACKGROUND);
        addControl(m_states[m_currentState].background); // this is done on purpose
        // The non-in-container pointer is left to have easy access to background
    }
    m_states[m_currentState].background->setBitmap(fileName);
}

bool HUD::flipUi()
{
	return m_flipUI;
}

void HUD::loadDataFile(const std::string& fileName)
{
    m_dataLoader.loadUIFile(fileName);
}

Rectangle HUD::getRectangle(const std::string& id)
{
    return m_dataLoader.getBounds(id);
}

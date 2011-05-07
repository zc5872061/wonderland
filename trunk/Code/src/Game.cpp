/*
 * Game.cpp
 *
 *  Created on: 2010-12-03
 *      Author: artur.m
 */

#include "Game.h"

#include "pi.h"

#include <cstdlib>
#include <ctime>

#include "GLRenderer.h"
#include "MathHelper.h"
#include "Actor.h"
#include "Board.h"
#include "Ball.h"
#include "BallsInformations.h"

Game* Game::s_instance = null;

Game& Game::getInstance()
{
	if(s_instance == null)
	{
		s_instance = new Game();
	}
	return *s_instance;
}

void Game::cleanup()
{
	delete s_instance;
	s_instance = null;
}

Game::Game()
{
	srand((unsigned int)time(null));
}

Game::~Game()
{
    delete m_renderer;
    delete m_resources;
    delete m_meshes;
    delete m_physics;
    delete m_materialsManager;
}

void Game::initialize(std::auto_ptr<GameController> controller, std::auto_ptr<HUD> hud)
{
    m_renderer = new GLRenderer();
	m_resources = new ResourceManager();
	m_meshes = new MeshManager();
	m_physics = new PhysicsEngine();
	m_materialsManager = new MaterialsManager();
    m_gameController = controller;
    m_fontEngine = new FontEngine();
    
    getFontEngine().initialize();
#ifndef SHP
    getRenderer().initialize();
#endif
    getRenderer().getCamera().initialize(Constants::SCREEN_NARROW, Constants::SCREEN_WIDE, 30, 1, 100, Vector(0, 0, -26));
    setHUD(hud);
    getHUD().initialize();
    getResourceManager().initialize();
    getMaterialsManager().initialize();

	m_gameController->initialize();
}

#ifndef IOS
bool Game::initializeGraphics(EGLNativeWindowType window)
{
	return getRenderer().initialize(window);
}
#endif

void Game::update(int milis)
{
    deleteActors();
    
	m_gameController->update(milis);
	m_physics->update(milis);
}

void Game::touchPressed(int x, int y)
{
    Log("Touch pressed - %d:%d", x, y);
	if(m_hud->touchPressed(x, y))
	{
		return;
	}
	m_gameController->touchPressed(x, y);
}

void Game::touchReleased(int x, int y)
{
	if(m_hud->touchReleased(x, y))
	{
		return;
	}
	m_gameController->touchReleased(x, y);
}

GLRenderer& Game::getRenderer()
{
	return *m_renderer;
}

ResourceManager& Game::getResourceManager()
{
	return *m_resources;
}

MeshManager& Game::getMeshManager()
{
	return *m_meshes;
}

GameController* Game::getGameController()
{
	return m_gameController.get();
}

void Game::setHUD(std::auto_ptr<HUD> hud)
{
	m_hud = hud;
}

PhysicsEngine& Game::getPhysicsEngine()
{
	return *m_physics;
}

MaterialsManager& Game::getMaterialsManager()
{
	return *m_materialsManager;
}

FontEngine& Game::getFontEngine()
{
    return *m_fontEngine;
}

HUD& Game::getHUD()
{
	return *m_hud;
}

void Game::deleteActors()
{
    DeletedContainer copy(m_actorsToDelete);
    m_actorsToDelete.clear(); // this is done so that in an Actor's destructor it will be possible to destroy some Actor
    
	copy.clear();
}

void Game::add(shared_ptr<Actor> actor)
{
    getGameController()->addActor(actor);
    getRenderer().draw(actor.get());
    getPhysicsEngine().addActor(actor);
}

void Game::remove(shared_ptr<Actor> actor)
{
    // shared_pointer created below will be destroyed in the next invocation
    // of update for the Game. This is done this way so that actors will be able to
    // do safely something like "delete this"
    m_actorsToDelete.push_back(actor);
    
    getGameController()->removeActor(actor);
    getRenderer().drop(actor.get());
    getPhysicsEngine().removeActor(actor);
}

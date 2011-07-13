/*
 * Game.h
 *
 *  Created on: 2010-12-03
 *      Author: artur.m
 */

#ifndef GAME_H_
#define GAME_H_

#include "pi.h"

#include <vector>
#include <string>
#include <memory>
#include <list>

//#include "Actor.h"
#include "GLRenderer.h"
#include "ResourceManager.h"
#include "MeshManager.h"
#include "GameController.h"
#include "PhysicsEngine.h"
#include "Engine/MaterialsManager.h"
#include "Vector.h"
#include "Fonts/FontEngine.h"

class Actor;

class Game
{
public:
	static Game& getInstance();
	static void cleanup();
    // Obviously this method must be called exactly once
    void initialize(std::auto_ptr<GameController> controller);
    void setHud(std::auto_ptr<HUD> hud);
#ifdef SHP
	bool initializeGraphics(EGLNativeWindowType window);
#endif

	void update(int milis);
	void touchPressed(int x, int y);
	void touchReleased(int x, int y);

	HUD& getHUD();

	GLRenderer& getRenderer();
	ResourceManager& getResourceManager();
	MeshManager& getMeshManager();
	GameController* getGameController();
	PhysicsEngine& getPhysicsEngine();
	MaterialsManager& getMaterialsManager();
    FontEngine& getFontEngine();
    
    void add(shared_ptr<Actor> actor);
    void remove(shared_ptr<Actor> actor);

private:
	static Game* s_instance;

	Game();
	virtual ~Game();

	void deleteActors();
    void setHUD(std::auto_ptr<HUD> hud);

	std::auto_ptr<GameController> m_gameController;
	std::auto_ptr<HUD> m_hud;

    GLRenderer* m_renderer;
    ResourceManager* m_resources;
    MeshManager* m_meshes;
    PhysicsEngine* m_physics;
    MaterialsManager* m_materialsManager;
    FontEngine* m_fontEngine;

    typedef std::vector<shared_ptr<Actor> > DeletedContainer;
	DeletedContainer m_actorsToDelete;
};

#endif /* GAME_H_ */

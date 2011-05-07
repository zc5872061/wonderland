/*
 * GameController.cpp
 *
 *  Created on: 2010-12-16
 *      Author: artur.m
 */

#include "GameController.h"

#include <limits>
#include <algorithm>

#include "Game.h"

const std::string GameController::CLASS_NAME("GameController");

GameController::GameController()
{

}

GameController::~GameController()
{

}

std::string GameController::getClass() const
{
	return CLASS_NAME;
}

bool GameController::checkPicking(const BasicMesh& mesh, const Matrix& meshTransformation, Vector& result, const Ray& ray) const
{
	const BaseCollisionShape* cs = mesh.getCollisionShape();
	if(cs && cs->checkPicking(result, ray, meshTransformation))
	{
		return true;
	}
	return false;
}

void GameController::touchReleased(int x, int y)
{
	std::vector<TouchInfo> intersected;
	getTracedActors(intersected, Game::getInstance().getRenderer().getCamera().getRay(x, y));

	TouchInfo actuallyTouchedActor = getCameraClosestTouch(intersected);
	if(!actuallyTouchedActor.actor)
	{
		return;
	}

	Log("Actually touched - %s", actuallyTouchedActor.actor->getType().c_str());
	for(InternalIter it = m_gameObjects.begin(); it != m_gameObjects.end(); ++it)
	{
		if((*it)->isIgnoreTrace())
		{
			continue;
		}
		(*it)->engineReleased(actuallyTouchedActor.actor.get(), actuallyTouchedActor.intersection);
	}
}

void GameController::touchPressed(int x, int y)
{
	std::vector<TouchInfo> intersected;
	getTracedActors(intersected, Game::getInstance().getRenderer().getCamera().getRay(x, y));

	TouchInfo actuallyTouchedActor = getCameraClosestTouch(intersected);

	for(InternalIter it = m_gameObjects.begin(); it != m_gameObjects.end(); ++it)
	{
		(*it)->engineTouched(actuallyTouchedActor.actor.get(), actuallyTouchedActor.intersection);
	}
}

void GameController::update(int milis)
{
	for(InternalIter it = m_gameObjects.begin(); it != m_gameObjects.end(); ++it)
	{
		(*it)->engineUpdate(milis);
	}
}

void GameController::getTracedActors(std::vector<TouchInfo>& actors, const Ray& ray)
{
	Vector intersection;

	for(InternalIter it = m_gameObjects.begin(); it != m_gameObjects.end(); ++it)
	{
        if((*it)->isHidden())
            continue;
        
        for(Model::MeshesIterator m = (*it)->getModel().begin(); m != (*it)->getModel().end(); ++m)
        {
            const std::string& meshName = (*m)->getMeshName();
            
            if(meshName.size() == 0)
                continue;

            Vector intersection;
            BasicMesh* mesh = Game::getInstance().getMeshManager().getMesh(meshName);
            Matrix transformation = (*it)->getTransformation();
            if(checkPicking(*mesh, transformation, intersection, ray))
            {
                TouchInfo ti = {*it, intersection};
                actors.push_back(ti);
            }
        }
	}
}

GameController::TouchInfo GameController::getCameraClosestTouch(const std::vector<TouchInfo>& allTouched)
{
	Vector cameraPos = Game::getInstance().getRenderer().getCamera().getPosition();
	GLfloat smallestDistance = std::numeric_limits<GLfloat>::max();
	TouchInfo touched = {shared_ptr<Actor>(), Vector()};
	for(std::vector<TouchInfo>::const_iterator it = allTouched.begin(); it != allTouched.end(); ++it)
	{
		GLfloat cameraDistance = (cameraPos - (*it).intersection).length();
		if(cameraDistance < smallestDistance)
		{
			touched = *it;
			smallestDistance = cameraDistance;
		}
	}
	return touched;
}

void GameController::addActor(shared_ptr<Actor> actor)
{
	assert(std::find(m_gameObjects.begin(), m_gameObjects.end(), actor) == m_gameObjects.end());
    // Cannot log it because it is called from within Actor's constructor thereFore there is a hard binding
    // and virtual calling doesn't work...
//	Log("Adding %s with mesh %s to m_gameObjects", actor->getType().c_str(), actor->getModel().getMeshName().c_str());
	m_gameObjects.push_back(actor);
}

void GameController::removeActor(shared_ptr<Actor> actor)
{
    // Probably will be better without this assert anyway...
//	assert(std::find(m_gameObjects.begin(), m_gameObjects.end(), actor) != m_gameObjects.end());
    if(std::find(m_gameObjects.begin(), m_gameObjects.end(), actor) == m_gameObjects.end())
    {
        Log("GameController - removing a non-existent %s. Double \"delete\"?", actor->getType().c_str());
        return;
    }
	m_gameObjects.erase(std::find(m_gameObjects.begin(), m_gameObjects.end(), actor));
}

shared_ptr<Actor> GameController::getActorPtr(Actor* actor)
{
    for(InternalIter it = m_gameObjects.begin(); it != m_gameObjects.end(); ++it)
    {
        if((*it).get() == actor)
        {
            return *it;
        }
    }
    return shared_ptr<Actor>();
}

void GameController::getActors(const std::string& actorType, ActorsContainer& result)
{
	for(InternalIter it = m_gameObjects.begin(); it != m_gameObjects.end(); ++it)
	{
		if((*it)->getType() == actorType)
		{
			result.push_back(*it);
		}
	}
}

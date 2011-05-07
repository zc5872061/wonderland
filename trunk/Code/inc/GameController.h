/*
 * GameController.h
 *
 *  Created on: 2010-12-16
 *      Author: artur.m
 */

#ifndef GAMECONTROLLER_H_
#define GAMECONTROLLER_H_

#include <string>
#include <list>
#include <vector>

#include "Actor.h"
#include "Engine/BasicMesh.h"

class GameController
{
public:
	struct TouchInfo
	{
		shared_ptr<Actor> actor;
		Vector intersection;
        int meshIndex;
	};

	typedef std::vector<shared_ptr<Actor> > ActorsContainer;
	typedef ActorsContainer::iterator ActorsIter;

	static const std::string CLASS_NAME;

	GameController();
	virtual ~GameController();

	virtual std::string getClass() const;

//	ActorsContainer& getActors();
	void getActors(const std::string& actorType, ActorsContainer& result);

	void update(int milis);

	virtual void touchReleased(int x, int y);
	virtual void touchPressed(int x, int y);

	void addActor(shared_ptr<Actor> actor);
	void removeActor(shared_ptr<Actor> actor);
    shared_ptr<Actor> getActorPtr(Actor* actor);

	virtual void initialize() {};

private:
	bool checkPicking(const BasicMesh& mesh, const Matrix& meshTransformation, Vector& result, const Ray& ray) const;

	void getTracedActors(std::vector<TouchInfo>& actors, const Ray& ray);
	TouchInfo getCameraClosestTouch(const std::vector<TouchInfo>& allTouched);

    typedef std::list<shared_ptr<Actor> > InternalContainer;
    typedef InternalContainer::iterator InternalIter;
	InternalContainer m_gameObjects;
};

#endif /* GAMECONTROLLER_H_ */

/*
 * PhysicsEngine.h
 *
 *  Created on: 2010-12-17
 *      Author: artur.m
 */

#ifndef PHYSICSENGINE_H_
#define PHYSICSENGINE_H_

#include <vector>
#include <memory>
#include <map>

#include "Vector.h"
#include "Actor.h"

// Time should be relative to the moment of animation node creation
class AnimNode
{
public:
	AnimNode(Vector position = Vector(), long long time  = 0);
	Vector position;
	long long time;
};

class AnimationListener
{
public:
    virtual ~AnimationListener() {};
	virtual void animationFinished(Actor* target) = 0;
};

// Time should be relative to the moment of AnimCurve creation
class AnimCurve
{
public:
	enum InterpolationMethod
	{
		IM_LINEAR,
		IM_EASE_INOUT,
		IM_ENUM_SIZE
	};

	friend class PhysicsEngine;
	AnimCurve(const std::vector<Vector>& nodes, long long startTime, long long endTime, InterpolationMethod method = IM_LINEAR);

private:
	typedef std::vector<AnimNode> AnimNodesContainer;
	typedef AnimNodesContainer::iterator AnimNodesIter;
	AnimNodesContainer m_curve;

	long long m_startTime;
	long long m_endTime;
	InterpolationMethod m_method;
};

class PhysicsEngine
{
public:
	PhysicsEngine();
	virtual ~PhysicsEngine();

	void addActor(shared_ptr<Actor> actor);
	void removeActor(shared_ptr<Actor> actor);

	void update(int milis);
	// As of now - the bound Actor must not be already bound - to make everything easier
	void bindAnimation(shared_ptr<Actor> target, std::auto_ptr<AnimCurve> anim, AnimationListener* listener = null);

private:
	void updateInterpolating();
	long long getTransformedTime(long long start, long long end, long long elapsed, AnimCurve::InterpolationMethod method) const;

	long long m_elapsed;
	long long m_lastTick;

	typedef std::vector<shared_ptr<Actor> > ActorsContainer;
	typedef ActorsContainer::iterator ActorsIter;
	ActorsContainer m_actors;

	struct AnimCurveInfo
	{
		AnimCurve* curve;
		AnimationListener* listener;
		bool operator==(const AnimCurveInfo& rs);
	};
	typedef std::map<shared_ptr<Actor>, AnimCurveInfo> AnimCurvesContainer;
	typedef AnimCurvesContainer::iterator AnimCurvesIter;
	AnimCurvesContainer m_animCurves;
};

#endif /* PHYSICSENGINE_H_ */

/*
 * PhysicsEngine.cpp
 *
 *  Created on: 2010-12-17
 *      Author: artur.m
 */

#include "PhysicsEngine.h"

#include "pi.h"

#include <algorithm>
#include <stack>

AnimNode::AnimNode(Vector position, long long time) :
	position(position),
	time(time)
{

}

AnimCurve::AnimCurve(const std::vector<Vector>& nodes, long long startTime, long long endTime, InterpolationMethod method) :
		m_method(method)
{
	GLfloat totalDistance = 0;
	for(unsigned int i = 0; i < nodes.size() - 1; ++i)
	{
		totalDistance += (nodes[i+1] - nodes[i]).length();
	}
	long long totalTime = endTime - startTime;
	assert(totalTime > 0);

	AnimNode node(nodes[0], startTime);
	m_curve.push_back(node);
	for(unsigned int i = 1; i < nodes.size(); ++i)
	{
		long long timeDiff = (nodes[i] - nodes[i-1]).length() / totalDistance * totalTime;
		m_curve.push_back(AnimNode(nodes[i], m_curve[m_curve.size()-1].time + timeDiff));
	}
	m_curve[m_curve.size() - 1].time = endTime;
}

PhysicsEngine::PhysicsEngine() :
	m_elapsed(0),
	m_lastTick(0)
{

}

PhysicsEngine::~PhysicsEngine()
{

}

void PhysicsEngine::addActor(shared_ptr<Actor> actor)
{
	assert(std::find(m_actors.begin(), m_actors.end(), actor) == m_actors.end());
	m_actors.push_back(actor);
}

void PhysicsEngine::removeActor(shared_ptr<Actor> actor)
{
	if(std::find(m_actors.begin(), m_actors.end(), actor) != m_actors.end())
	{
		m_actors.erase(std::find(m_actors.begin(), m_actors.end(), actor));
	}
	if(m_animCurves.find(actor) != m_animCurves.end())
	{
		m_animCurves.erase(actor);
	}
}

void PhysicsEngine::update(int milis)
{
	m_elapsed += milis;
	updateInterpolating();

//	updatePhysics(); // TODO: For future ;)

	m_lastTick = milis;
}

void PhysicsEngine::bindAnimation(shared_ptr<Actor> target, std::auto_ptr<AnimCurve> anim, AnimationListener* listener)
{
	AnimCurveInfo aci;
	aci.curve = anim.release();
	aci.listener = listener;

	assert(m_animCurves.find(target) == m_animCurves.end());
	for(AnimCurve::AnimNodesIter it = aci.curve->m_curve.begin(); it != aci.curve->m_curve.end(); ++it)
	{
		(*it).time += m_elapsed;
	}
	m_animCurves[target] = aci;
}

void PhysicsEngine::updateInterpolating()
{
	std::stack<AnimCurvesContainer::key_type> keysToDelete;
	for(AnimCurvesIter it = m_animCurves.begin(); it != m_animCurves.end(); ++it)
	{
		shared_ptr<Actor> target = (*it).first;
		AnimCurve::AnimNodesContainer& anim = (*it).second.curve->m_curve;

		assert(anim.size() >= 2);
		if(anim[0].time > m_elapsed)
		{
			return;
		}
		if(target->getPhysics() != PHYS_INTERPOLATING)
		{
			target->setPhysics(PHYS_INTERPOLATING);
		}
		while(anim.size() >= 2 && anim[1].time < m_elapsed)
		{
			anim.erase(anim.begin());
		}
		if(anim.size() == 1)
		{
			keysToDelete.push(target);
			target->setPosition(anim[0].position);
			target->setPhysics(PHYS_STATIC);
			if((*it).second.listener)
			{
				(*it).second.listener->animationFinished(target.get());
			}
			break;
		}
		// Here a trick is done - instead of transforming all the vertices in the curve,
		// time which is used to interpolate it is transformed according to the wanted curve
		long long transformedTime = getTransformedTime(anim[0].time, anim[1].time, m_elapsed, (*it).second.curve->m_method);
		target->setPosition(MathHelper::lerp(anim[0].position, anim[1].position, anim[0].time, anim[1].time, transformedTime));
	}
	while(!keysToDelete.empty())
	{
		delete m_animCurves[keysToDelete.top()].curve;
		m_animCurves.erase(keysToDelete.top());
		keysToDelete.pop();
	}
}

long long PhysicsEngine::getTransformedTime(long long start, long long end, long long elapsed, AnimCurve::InterpolationMethod method) const
{
	switch(method)
	{
		case AnimCurve::IM_LINEAR:
		{
			return elapsed;
			break; // redundant break is never too much ;)
		}
		case AnimCurve::IM_EASE_INOUT:
		{
			return MathHelper::easeInOut(start, end, start, end, elapsed);
			break;
		}
		default:
		{
			break;
		}
	}
	Log("Unknown enumeration value %d in PhysicsEngine::getTransformedTime", method);
	assert(0);
	return -1;
}

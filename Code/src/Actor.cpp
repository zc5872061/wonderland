/*
 * Actor.cpp
 *
 *  Created on: 2010-12-01
 *      Author: artur.m
 */
#include "Actor.h"

#include "pi.h"
#include "GLRenderer.h"
#include "Game.h"

#include <cmath>

void Actor::initializeImpl(shared_ptr<Actor> child)
{
    Game::getInstance().add(child);
}

const std::string Actor::DEFAULT_STATE("Default");

void Actor::destroy(shared_ptr<Actor> actor)
{
    Game::getInstance().remove(actor);
}

void Actor::destroy(Actor* actor)
{
    shared_ptr<Actor> ptr = Game::getInstance().getGameController()->getActorPtr(actor);
    assert(ptr != null);
    destroy(ptr);
}

Actor::Actor(const Vector& position, bool ortho) :
		m_position(position),
		m_rotationAngle(0),
		m_parent(null),
		m_physics(PHYS_STATIC),
		m_hidden(false),
		m_currentState(null),
		m_ignoreTrace(false),
        m_ortho(ortho),
        m_drawLayer(m_ortho ? Common::DL_FOREGROUND : Common::DL_WRONG_OBJECT),
		m_scale(1.0f)
{
	// Actor is a bit hacked to support UE3-like states
	// In general a state is a BasicState object
	// Actor inherits from BasicState but can also hold
	// BasicStates.
	// In runtime it calls BasicState's methods which
	// are called by a pointer which may be 'this' or any
	// other BasicState pointer.
	// However it makes sense only if these other BasicStates are
	// interested only in one (this) actor.
	// Check Ball code for reference
	registerState(this, DEFAULT_STATE);
	goToState(DEFAULT_STATE);
}

Actor::~Actor()
{

}

Vector Actor::getPosition() const
{
	return m_position;
}

void Actor::setPosition(const Vector& pos)
{
	m_position = pos;
}

Vector Actor::getRotationAxis() const
{
	return m_rotationAxis;
}

void Actor::setRotationAxis(const Vector& axis)
{
	Log("Rotation unsupported yet");
	m_rotationAxis = axis;
}

GLfloat Actor::getRotationAngle() const
{
	return m_rotationAngle;
}

void Actor::setRotationAngle(GLfloat angle)
{
	Log("Rotation unsupported yet");
	assert(0);
	m_rotationAngle = angle;
}

void Actor::setParent(Actor* parent)
{
	m_parent = parent;
}

Actor* Actor::getParent() const
{
	return m_parent;
}

Matrix Actor::getTransformation() const
{
	Matrix result;
	MathHelper::LoadIdentity(result);

	if(m_scale != 1.0f)
	{
		Matrix matScale;
		MathHelper::Scale(matScale, m_scale);
		result = MathHelper::Multiply(result, matScale);
	}

	const Actor* tempActor = this;
	while(tempActor != null)
	{
		Matrix translation;
		Matrix rotation;

		Vector temp = tempActor->getRotationAxis();
//		MathHelper::Rotate(roation, tempActor->getRotationAngle(), temp.x, temp.y, temp.z); // TODO Fix rotations
		MathHelper::LoadIdentity(rotation);
		temp = tempActor->getPosition();

		MathHelper::Translate(translation, temp.x, temp.y, temp.z);

		Matrix both = MathHelper::Multiply(translation, rotation);
		result = MathHelper::Multiply(result, both);

		tempActor = tempActor->getParent();
	}

	return result;
}

PhysicsState Actor::getPhysics() const
{
	return m_physics;
}

void Actor::setPhysics(PhysicsState physics)
{
	m_physics = physics;
}

void Actor::registerState(BasicState* state, const std::string& name)
{
	m_states[name] = state;
}

void Actor::goToState(const std::string& name)
{
	assert(m_states.find(name) != m_states.end());
	if(m_currentState)
	{
		m_currentState->stateEnded();
	}
	m_currentState = m_states[name];
	m_currentState->stateEntered();
}

void Actor::engineUpdate(int milis)
{
	m_currentState->update(milis);
}

void Actor::engineTouched(const Actor* target, const Vector& touchPoint)
{
	m_currentState->touched(target, touchPoint);
}

void Actor::engineReleased(const Actor* target, const Vector& touchPoint)
{
	m_currentState->released(target, touchPoint);
}

bool Actor::isHidden() const
{
	return m_hidden;
}

void Actor::setHidden(bool value)
{
    if(m_hidden == value) return;
    m_hidden = value;
}

void Actor::ignoreTrace(bool value)
{
	m_ignoreTrace = value;
}

bool Actor::isIgnoreTrace() const
{
	return m_ignoreTrace;
}

void Actor::setScale(GLfloat scale)
{
	m_scale = scale;
}

GLfloat Actor::getScale() const
{
	return m_scale;
}

bool Actor::isOrtho() const
{
    return m_ortho;
}

void Actor::setDrawLayer(Common::DrawLayer layer)
{
    // Setting draw layers is correct only for orthogonally
    // drawn objects
    assert(m_ortho == true);
    m_drawLayer = layer;
}

Common::DrawLayer Actor::getDrawLayer() const
{
    return m_drawLayer;
}

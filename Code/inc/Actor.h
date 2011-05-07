/*
 * Actor.h
 *
 *  Created on: 2010-12-01
 *      Author: artur.m
 */

#ifndef PAWN_H_
#define PAWN_H_

#include "BasicState.h"
#include "Vector.h"
#include "MathHelper.h"
#include "Program.h"
#include "CollisionShapes.h"
#include "Engine/Model.h"
#include "Engine/Material.h"
#include "shared_ptr.h"
#include "GameCommon.h"

#include <memory>
#include <string>
#include <map>

enum PhysicsState
{
	PHYS_STATIC,
	PHYS_INTERPOLATING,
	PHYS_ENUM_SIZE
};

class Actor : public BasicState
{
public:
	typedef void* CreationParams;
	friend class Game;

	static const std::string DEFAULT_STATE;

	virtual std::string getType() const = 0;
    
    // Destroys the actor - i.e. removes it from all the game's systems
    // and it will no longer be drawn, no longer will react to anything,
    // so for the player it is like if it was not existing anymore
    // Whether it is deleted depends on what you do with the shared_ptr later
    static void destroy(shared_ptr<Actor> actor);
    static void destroy(Actor* actor);
    // This function must be called by a child object whenever it is created.
    // This method creates the proper shared pointer that will be used with this actor
    template <class ChildT>
    static shared_ptr<ChildT> initialize(ChildT* child)
    {
        // Done to check if the passed pointer is really an Actor instance
        Actor* isChild = child;
        isChild = 0; 
        
        shared_ptr<ChildT> result(child);
        initializeImpl(result);
        return result;
    }

	// Functions that are called by the engine, and then proper
	// update, touched and released are called in classes that inherit from
	// actor or methods in their states are called
	// As of now, I will simply leave a warning:
	// DON'T CALL THESE METHODS FROM ACTORS' CODE!
	// If you want informations about touch look at BasicState and overload
	// those methods
	void engineUpdate(int milis);
	void engineTouched(const Actor* target, const Vector& touchPoint);
	void engineReleased(const Actor* target, const Vector& touchPoint);

	virtual Vector getPosition() const;
	virtual void setPosition(const Vector& pos);

	virtual Vector getRotationAxis() const;
	virtual void setRotationAxis(const Vector& axis);

	virtual GLfloat getRotationAngle() const;
	virtual void setRotationAngle(GLfloat angle);

	Matrix getTransformation() const;

	Model& getModel() { return m_model; }

	void setParent(Actor* parent);
	Actor* getParent() const;

	PhysicsState getPhysics() const;
	void setPhysics(PhysicsState physics);

	void registerState(BasicState* state, const std::string& name);
	void goToState(const std::string& name);

	bool isHidden() const;
    void setHidden(bool value);

	void ignoreTrace(bool value);
	bool isIgnoreTrace() const;

	void setScale(GLfloat scale);
	GLfloat getScale() const;
    
    bool isOrtho() const;
    void setDrawLayer(Common::DrawLayer layer);
    Common::DrawLayer getDrawLayer() const;
    
protected:
	Actor(const Vector& position, bool ortho = false);
	virtual ~Actor();

protected:
	Vector m_position;
	Vector m_rotationAxis;
	GLfloat m_rotationAngle;
	Actor* m_parent;
	PhysicsState m_physics;

private:
    static void initializeImpl(shared_ptr<Actor> child);
    
	typedef std::map<std::string, BasicState*> StatesMap;
	typedef StatesMap::iterator StatesIter;
	StatesMap m_states;
	BasicState* m_currentState;
    bool m_hidden;
	bool m_ignoreTrace;
    // Sets if the actor should be rendered using proper Camera's matrices
    // or using orthogonal projection (e.g. if it is a Hud Control).
    // This is a characteristic of a whole inheriting class, therefore 'const'
    const bool m_ortho;
    Common::DrawLayer m_drawLayer;

	GLfloat m_scale;

	Model m_model;
};

#endif /* PAWN_H_ */

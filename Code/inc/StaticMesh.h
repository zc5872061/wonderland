/*
 * StaticMesh.h
 *
 *  Created on: 2011-02-08
 *      Author: Artur
 */

#ifndef STATICMESH_H_
#define STATICMESH_H_

#include "Actor.h"

#include <string>

class StaticMesh : public Actor
{
public:
	typedef std::string CreationParams;
	virtual ~StaticMesh();

	std::string getType() const { return "StaticMesh"; }
    
protected:
    StaticMesh(const Vector& position, const CreationParams& mesh);
};

#endif /* STATICMESH_H_ */

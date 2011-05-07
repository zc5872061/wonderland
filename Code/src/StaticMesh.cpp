/*
 * StaticMesh.cpp
 *
 *  Created on: 2011-02-08
 *      Author: Artur
 */

#include "StaticMesh.h"

StaticMesh::StaticMesh(const Vector& position, const CreationParams& mesh) :
	Actor(position)
{
	getModel().addElement("mesh", mesh);
}

StaticMesh::~StaticMesh()
{

}

/*
 * BasicMesh.cpp
 *
 *  Created on: 2011-02-13
 *      Author: Artur
 */

#include "Engine/BasicMesh.h"

#include "Game.h"

BasicMesh::BasicMesh() :
	m_vertices(null),
	m_indices(null),
	m_normals(null),
	m_uvs(null),
	m_indicesCount(0),
	m_verticesCount(0),
	m_collisionType(CS_NONE)
{

}

BasicMesh::~BasicMesh()
{
	delete[] m_vertices;
	delete[] m_indices;
	delete[] m_normals;
	delete[] m_uvs;
}

void BasicMesh::setCollisionType(CollisionShape type)
{
	m_collisionType = type;
}

void BasicMesh::debugPrint() const
{
    Log("Mesh name: %s", getName().c_str());
    Log("Vertices count: %d", getVerticesCount());
    for(int i = 0; i < getVerticesCount(); i+=1)
    {
        Log("%f %f %f", getVertices()[3*i], getVertices()[3*i+1], getVertices()[3*i+2]);
    }
}
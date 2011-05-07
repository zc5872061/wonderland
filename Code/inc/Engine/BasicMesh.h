/*
 * BasicMesh.h
 *
 *  Created on: 2011-02-13
 *      Author: Artur
 */

#ifndef BASICMESH_H_
#define BASICMESH_H_

#include "pi.h"
#include "CollisionShapes.h"
#include "Material.h"

#include <string>
#include <memory>

class BasicMesh
{
public:
	friend class MeshManager;
	BasicMesh();

	const GLfloat* getVertices() const { return m_vertices; }
	const GLshort* getIndices() const { return m_indices; }
	const GLfloat* getNormals() const { return m_normals; }
	const GLfloat* getUVs() const { return m_uvs; }
	int getIndicesCount() const  { return m_indicesCount; }
	int getVerticesCount() const { return m_verticesCount; }

	const BaseCollisionShape* getCollisionShape() const { return m_collisionShape.get(); }

	CollisionShape getCollisionType() const { return m_collisionType; }
	void setCollisionType(CollisionShape type);

	const std::string& getName() const { return m_name; }
    
    void debugPrint() const;

protected:
	GLfloat* m_vertices;
	GLshort* m_indices;
	GLfloat* m_normals;
	GLfloat* m_uvs;
	int m_indicesCount;
	int m_verticesCount;

	std::auto_ptr<BaseCollisionShape> m_collisionShape;
	CollisionShape m_collisionType;

	std::string m_name;

private:
	BasicMesh(const BasicMesh&);
	BasicMesh& operator=(const BasicMesh&);
	~BasicMesh();
};

#endif /* BASICMESH_H_ */

/*
 * MeshManager.h
 *
 *  Created on: 2010-12-15
 *      Author: artur.m
 */

#ifndef MESHMANAGER_H_
#define MESHMANAGER_H_

#include <map>
#include <string>
#include <vector>
#include <memory>

#include "Engine/BasicMesh.h"
#include "CollisionShapes.h"
#include "GameFile.h"

class MeshManager
{
public:
	static const std::string MESH_FILE_EXTENSION;

	MeshManager();
	virtual ~MeshManager();
	BasicMesh* getMesh(const std::string& name);
	const BaseCollisionShape* getCollisionShape(const std::string& name);
	std::auto_ptr<BaseCollisionShape> createCollisionShape(BasicMesh* mesh);

	typedef std::vector<GLfloat> FloatDataContainer;
	typedef std::vector<GLshort> ShortDataContainer;

	void createMesh(const std::string& name,
					const FloatDataContainer& vertices,
					const FloatDataContainer& uvs,
					const FloatDataContainer& normals,
					const ShortDataContainer& indices,
					CollisionShape type = CS_NONE
					);

	std::string createHUDPanel(const Rectangle& bounds);

	void destroyMesh(const std::string& name);
	void destroyMesh(std::auto_ptr<BasicMesh> mesh);

private:

	BasicMesh* loadMesh(const std::string& fileName, const std::string meshName);
	void loadName(BasicMesh* result, const std::string& readLine);
	void loadVertices(BasicMesh* result, const std::string& readLine, GameFile* file);
	void loadUvs(BasicMesh* result, const std::string& readLine, GameFile* file);
	void loadIndices(BasicMesh* result, const std::string& readLine, GameFile* file);
	void loadNormals(BasicMesh* result, const std::string& readLine, GameFile* file);
	void setCollision(BasicMesh* result, const std::string& line);

	std::auto_ptr<BallCollisionShape> createBallCollisionShape(BasicMesh* source) const;
	std::auto_ptr<PlaneCollisionShape> createPlaneCollisionShape(BasicMesh* source) const;
	std::auto_ptr<BoxCollisionShape> createBoxCollisionShape(BasicMesh* source) const;

private:

	static int s_panelsCount;

	static const std::string NAME_SECTION;
	static const std::string VERTICES_SECTION;
	static const std::string UVS_SECTION;
	static const std::string INDICES_SECTION;
	static const std::string NORMALS_SECTION;
	static const std::string COLLISION_SECTION;

	typedef std::map<std::string, BasicMesh*> MeshesContainer;
	typedef MeshesContainer::iterator MeshesIter;
	MeshesContainer m_meshes;

	bool m_valid;
};

#endif /* MESHMANAGER_H_ */

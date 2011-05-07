/*
 * MeshManager.cpp
 *
 *  Created on: 2010-12-15
 *      Author: artur.m
 */

#include "MeshManager.h"

#include "pi.h"

#include "HUD/HUD.h"
#include "Game.h"


#include <algorithm>
#include <memory>
#include <sstream>
#include <limits>

const std::string MeshManager::MESH_FILE_EXTENSION(".dta");

const std::string MeshManager::NAME_SECTION("name");
const std::string MeshManager::VERTICES_SECTION("vertices");
const std::string MeshManager::UVS_SECTION("uvs");
const std::string MeshManager::INDICES_SECTION("indices");
const std::string MeshManager::NORMALS_SECTION("normals");
const std::string MeshManager::COLLISION_SECTION("collision");

int MeshManager::s_panelsCount(0);

MeshManager::MeshManager() : m_valid(true)
{

}

MeshManager::~MeshManager()
{
	m_valid = false;
	for(MeshesIter it = m_meshes.begin(); it != m_meshes.end(); ++it)
	{
		delete (*it).second;
	}
	m_meshes.clear();
}

BasicMesh* MeshManager::getMesh(const std::string& name)
{
	assert(name.size() != 0);
	if(m_meshes.find(name) == m_meshes.end())
	{
		m_meshes[name] = loadMesh(Constants::getRootPath()+name+MESH_FILE_EXTENSION, name);
	}
	return m_meshes[name];
}

const BaseCollisionShape* MeshManager::getCollisionShape(const std::string& name)
{
	Log("Looking for collision shape for %s", name.c_str());
	return m_meshes[name]->getCollisionShape();
}

std::auto_ptr<BaseCollisionShape> MeshManager::createCollisionShape(BasicMesh* mesh)
{
	Log("Create collision shape for %s", mesh->getName().c_str());
	std::auto_ptr<BaseCollisionShape> result;
	switch(mesh->getCollisionType())
	{

		case CS_NONE:
			break;
		case CS_BALL:
			result = createBallCollisionShape(mesh);
			break;
		case CS_BOX:
			result = createBoxCollisionShape(mesh);
			break;
		case CS_PLANE:
			result = createPlaneCollisionShape(mesh);
			break;
		default:
			Log("Unknown collsion type - %d", mesh->getCollisionType());
			assert(0);
	}

	return result;
}

template <typename TargetT>
int _fillData(TargetT*& target, GameFile* source, int stride, const std::string& readLine)
{
	std::string countStr = readLine.substr(readLine.find(":")+1);
	std::stringstream ss;
	ss << countStr;
	int count = 0;
	ss >> count;

	assert(count > 0);

	target = new TargetT[stride * count];

	for(int i = 0; i < count; ++i)
	{
		std::string temp = source->readLine();
		assert(temp.size() != 0);
		std::stringstream dataStream;
		dataStream << temp;

		for(int j = 0; j < stride; ++j)
		{
			dataStream >> target[stride*i + j];
		}
	}

	return stride * count;
}

BasicMesh* MeshManager::loadMesh(const std::string& fileName, const std::string meshName)
{
	shared_ptr<GameFile> file = GameFile::openFile(fileName, "r");
	std::string readLine;
	BasicMesh* result = new BasicMesh();
	std::string collisionLine;

	while(!(file->eof()))
	{
		readLine = file->readLine();
		if(readLine.size() == 0 || readLine == "\n")
		{
			continue;
		}
		if(readLine.find(NAME_SECTION) == 0)
		{
			loadName(result, readLine);
			continue;
		}
		else if(readLine.find(VERTICES_SECTION) == 0)
		{
			loadVertices(result, readLine, file.get());
			continue;
		}
		else if(readLine.find(UVS_SECTION) == 0)
		{
			loadUvs(result, readLine, file.get());
			continue;
		}
		else if(readLine.find(NORMALS_SECTION) == 0)
		{
			loadNormals(result, readLine, file.get());
			continue;
		}
		else if(readLine.find(INDICES_SECTION) == 0)
		{
			loadIndices(result, readLine, file.get());
			continue;
		}
		else if(readLine.find(COLLISION_SECTION) == 0)
		{
			collisionLine = readLine; // it has to be calculated after all the geometry
			continue;
		}
		else
		{
			Log("Skipping unknown line in mesh file - %s", readLine.c_str());
		}
	}

	if(collisionLine.size() != 0)
	{
		setCollision(result, collisionLine);
	}
	else
	{
		// by default create box collision
		result->setCollisionType(CS_BOX);
		result->m_collisionShape = createCollisionShape(result);
	}

	return result;
}

void MeshManager::setCollision(BasicMesh* result, const std::string& line)
{
	std::string number = line.substr(line.find(':')+1);
	std::istringstream iss(number);

	int type = CS_NONE;
	iss >> type;

	result->setCollisionType(static_cast<CollisionShape>(type));
	result->m_collisionShape = createCollisionShape(result);
}

void MeshManager::loadName(BasicMesh* result, const std::string& readLine)
{
	std::string name = readLine.substr(readLine.find(":")+1);
	result->m_name = name;
}

void MeshManager::loadVertices(BasicMesh* result, const std::string& readLine, GameFile* file)
{
	int count = _fillData(result->m_vertices, file, 3, readLine);
	result->m_verticesCount = count / 3; // fillData returns the float array size, which is 3*vertices count
}

void MeshManager::loadUvs(BasicMesh* result, const std::string& readLine, GameFile* file)
{
	_fillData(result->m_uvs, file, 2, readLine);
}

void MeshManager::loadIndices(BasicMesh* result, const std::string& readLine, GameFile* file)
{
	 result->m_indicesCount = _fillData(result->m_indices, file, 3, readLine);
}

void MeshManager::loadNormals(BasicMesh* result, const std::string& readLine, GameFile* file)
{
	_fillData(result->m_normals, file, 3, readLine);
}

template <typename ContainerT, typename ResultT>
void _copyData(const ContainerT& data, ResultT*& result)
{
	if(data.size() == 0)
	{
		return;
	}
	result = new ResultT[data.size()];
	std::copy(data.begin(), data.end(), result);
}

void MeshManager::createMesh(const std::string& name,
					const FloatDataContainer& vertices,
					const FloatDataContainer& uvs,
					const FloatDataContainer& normals,
					const ShortDataContainer& indices,
					CollisionShape type
					)
{
	assert(m_meshes.find(name) == m_meshes.end());
	BasicMesh* result = new BasicMesh();

	result->m_name = name;
	_copyData(vertices, result->m_vertices);
	result->m_verticesCount = vertices.size() / 3;
	_copyData(indices, result->m_indices);
	_copyData(uvs, result->m_uvs);
	_copyData(normals, result->m_normals);
	_copyData(indices, result->m_indices);
	result->m_indicesCount = indices.size() / 3;
	result->setCollisionType(type);

	m_meshes[name] = result;
}

void MeshManager::destroyMesh(const std::string& name)
{
	if(!m_valid)
	{
		return;
	}
	if(m_meshes.find(name) == m_meshes.end())
	{
		Log("Could not find mesh %s", name.c_str());
		assert(0);
	}
	delete m_meshes[name];
	m_meshes.erase(name);
}

void MeshManager::destroyMesh(std::auto_ptr<BasicMesh> mesh)
{
	if(mesh.get() == null)
	{
		return;
	}
	BasicMesh* m = mesh.release();
	for(MeshesIter it = m_meshes.begin(); it != m_meshes.end(); ++it)
	{
		if((*it).second == m)
		{
			destroyMesh((*it).first);
			return;
		}
	}
}

std::string MeshManager::createHUDPanel(const Rectangle& bounds)
{       
	BasicMesh* result = new BasicMesh();

	result->m_vertices = new float[12];
	memset(result->m_vertices, 0, 12*sizeof(float));
	result->m_vertices[0] = bounds.x; 					result->m_vertices[1] = bounds.y;
	result->m_vertices[3] = bounds.x + bounds.width; 	result->m_vertices[4] = bounds.y;
	result->m_vertices[6] = bounds.x + bounds.width;	result->m_vertices[7] = bounds.y + bounds.height;
	result->m_vertices[9] = bounds.x; 					result->m_vertices[10]= bounds.y + bounds.height;

	result->m_uvs = new GLfloat[8];
	memset(result->m_uvs, 0, 8 * sizeof(GLfloat));
	if(!Game::getInstance().getHUD().flipUi())
	{
		result->m_uvs[0] = 0; 		result->m_uvs[1] = 1;
		result->m_uvs[2] = 1; 		result->m_uvs[3] = 1;
		result->m_uvs[4] = 1; 		result->m_uvs[5] = 0;
		result->m_uvs[6] = 0; 		result->m_uvs[7] = 0;
	}
	else
	{
		result->m_uvs[0] = 0; 		result->m_uvs[1] = 0;
		result->m_uvs[2] = 0; 		result->m_uvs[3] = 1;
		result->m_uvs[4] = 1; 		result->m_uvs[5] = 1;
		result->m_uvs[6] = 1; 		result->m_uvs[7] = 0;
	}

	result->m_indices = new GLshort[6];
	result->m_indices[0] = 0;
	result->m_indices[1] = 1;
	result->m_indices[2] = 2;
	result->m_indices[3] = 0;
	result->m_indices[4] = 2;
	result->m_indices[5] = 3;

	result->m_indicesCount = 6;
    result->m_verticesCount = 4;

	std::stringstream ss;
	ss << s_panelsCount++;
	std::string meshName("");
    
    Log("Panels count: %d", s_panelsCount);

	ss >> meshName;
	meshName += "HUDPanel";
    
    result->m_name = meshName;

	m_meshes[result->m_name] = result;
	return meshName;
}

void _findBoundaries(Vector& low, Vector& high, const BasicMesh& from)
{
	assert(sizeof(Vector) == 3*sizeof(*(from.getVertices())));
	low.x = low.y = low.z = std::numeric_limits<float>::max();
	high.x = high.y = high.z = -std::numeric_limits<float>::max(); // numeric::min is actually minimal *positive* value

	const Vector* vertex = reinterpret_cast<const Vector*>(from.getVertices());

	for(int i = 0; i < from.getVerticesCount(); ++i)
	{
		if(low.x > vertex->x) low.x = vertex->x;
		if(low.y > vertex->y) low.y = vertex->y;
		if(low.z > vertex->z) low.z = vertex->z;

		if(high.x < vertex->x) high.x = vertex->x;
		if(high.y < vertex->y) high.y = vertex->y;
		if(high.z < vertex->z) high.z = vertex->z;

		++vertex;
	}
}

std::auto_ptr<BallCollisionShape> MeshManager::createBallCollisionShape(BasicMesh* source) const
{
    Vector center;
    const Vector* vertices = reinterpret_cast<const Vector*>(source->getVertices());
    for(int i = 0; i < source->getVerticesCount(); ++i)
    {
        center += vertices[i];
    }
    center /= source->getVerticesCount();
    
    float maxLength = std::numeric_limits<float>::min();
    for(int i = 0; i < source->getVerticesCount(); ++i)
    {
        float length = (vertices[i] - center).length();
        if(length > maxLength)
        {
            maxLength = length;
        }
    }
    
	BallCollisionShape* result = new BallCollisionShape(center, maxLength);
	return std::auto_ptr<BallCollisionShape>(result);
}

 // TODO: remove the plane collision shape from the engine at all because it's non physical
std::auto_ptr<PlaneCollisionShape> MeshManager::createPlaneCollisionShape(BasicMesh* source) const
{
	PlaneCollisionShape* result = new PlaneCollisionShape(Vector(0, 0, 1));
	return std::auto_ptr<PlaneCollisionShape>(result);
}

std::auto_ptr<BoxCollisionShape> MeshManager::createBoxCollisionShape(BasicMesh* source) const
{
	Vector min;
	Vector max;
	_findBoundaries(min, max, *source);
	Log("createBoxCollisionShape");
	min.debugPrint();
	max.debugPrint();
	BoxCollisionShape* result = new BoxCollisionShape(min, max);
	return std::auto_ptr<BoxCollisionShape>(result);
}

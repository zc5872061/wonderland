/*
 * LineActor.cpp
 *
 *  Created on: 2011-01-05
 *      Author: artur.m
 */

#include "LineActor.h"

#include "pi.h"

#include "Game.h"
#include "MeshManager.h"
#include "CollisionShapes.h"

#include <sstream>
#include <memory>

shared_ptr<LineActor> LineActor::spawn(const Vector& position, const CreationParams& points)
{
    return Actor::initialize(new LineActor(position, points));
}

const std::string LineActor::TYPE("LineActor");
int LineActor::s_instancesCount(0);

LineActor::LineActor(const Vector& position, const CreationParams& points) :
		Actor(position),
		m_lineWidth(0.1f)
{
	s_instancesCount++;
	createMesh(points);
    getModel().getElement()->getMaterialInstance()->setValue("u_lineWidth", m_lineWidth);
}

LineActor::~LineActor()
{
	Game::getInstance().getMeshManager().destroyMesh(m_meshName);
}

std::string LineActor::getType() const
{
	return TYPE;
}

inline void _addValue(MeshManager::FloatDataContainer& container, const Vector& vector)
{
	container.push_back(vector.x);
	container.push_back(vector.y);
	container.push_back(vector.z);
}

void LineActor::createMesh(const std::vector<Vector>& points)
{
	std::stringstream ss;
	ss << s_instancesCount;
	ss >> m_meshName;
	m_meshName += "LineMesh";

	MeshManager::FloatDataContainer lineVertices;
	MeshManager::FloatDataContainer lineNormals;
	MeshManager::FloatDataContainer dummyFloat;
	MeshManager::ShortDataContainer lineIndices;

	assert(points.size() > 1);
	const Vector cameraPos = Game::getInstance().getRenderer().getCamera().getPosition();
	for(unsigned int i = 0; i < points.size() - 1; ++i)
	{
		Vector vertex1 = points[i];
		Vector vertex2 = points[i+1];
		Vector lineDir = (vertex2 - vertex1).normalize();

		vertex1.z -= 0.4f;
		vertex2.z -= 0.4f;

		Vector normal1 = cross(lineDir, ( cameraPos)).normalize();
		Vector normal2 = -normal1;

		_addValue(lineVertices, vertex1); _addValue(lineNormals, normal1);
		_addValue(lineVertices, vertex1); _addValue(lineNormals, normal2);

		_addValue(lineVertices, vertex2); _addValue(lineNormals, normal1);
		_addValue(lineVertices, vertex2); _addValue(lineNormals, normal2);
	}

	// TODO: Check why it's not working with triangles but only with triangle strips?
	Game::getInstance().getMeshManager().createMesh(m_meshName, lineVertices, dummyFloat, lineNormals, lineIndices);
	getModel().addElement("line", m_meshName);
	getModel().getElement()->getMaterialInstance()->setMaterialName("line");
}

void LineActor::setLineWidth(GLfloat value)
{
	m_lineWidth = value;
    getModel().getElement()->getMaterialInstance()->setValue("u_lineWidth", value);
}

GLfloat LineActor::getLineWidth() const
{
	return m_lineWidth;
}

void LineActor::setColor(const Vector& color)
{
    m_color = color;
    getModel().getElement()->getMaterialInstance()->setValue("u_diffuseColor", color);
}

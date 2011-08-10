/*
 * Camera.cpp
 *
 *  Created on: 2010-12-02
 *      Author: artur.m
 */

#include "Camera.h"

#include "pi.h"
#include "MathHelper.h"

const std::string Camera::TYPE("Camera");

shared_ptr<Camera> Camera::spawn()
{
    return Actor::initialize(new Camera());
}

Camera::Camera() :
	Actor(Vector()),
	m_width(0),
	m_height(0)
{
	MathHelper::LoadIdentity(m_matModelView);
	MathHelper::LoadIdentity(m_matProjection);
    
    setHidden(true);
}

Camera::~Camera()
{

}

void Camera::initialize(int width, int height, float fov, float near, float far, Vector position)
{
	m_width = width;
	m_height = height;
	GLfloat aspect = static_cast<GLfloat>(m_width)/m_height;

	MathHelper::Perspective(m_matProjection, fov, aspect, near, far);
	setPosition(position);
    
    m_matOrthoMatrix = MathHelper::Ortho(m_width, m_height, -1.0f, 1.0f);
}

void Camera::setPosition(const Vector& pos)
{
	Actor::setPosition(pos);
	MathHelper::Translate(m_matModelView, m_position.x, m_position.y, m_position.z);
}

Vector Camera::getPosition() const
{
	Vector result = Actor::getPosition();
	// Result times -1 because that's the wa OpenGL works
	result *= -1;
	return result;
}

const Matrix& Camera::getProjectionMatrix() const
{
	return m_matProjection;
}

const Matrix& Camera::getModelViewMatrix() const
{
	return m_matModelView;
}

const Matrix& Camera::getOrthoMatrix() const
{
    return m_matOrthoMatrix;
}

int Camera::getWidth() const
{
	return m_width;
}

int Camera::getHeight() const
{
	return m_height;
}

Vector Camera::unproject(const Vector& point) const
{
	Vector result = MathHelper::Unproject(point, getModelViewMatrix(), getProjectionMatrix(), Viewport(0, 0, getWidth(), getHeight()));
	return result;
}

Ray Camera::getRay(int x, int y) const
{
	Vector near = unproject(Vector(x, y, 0));
	Vector far = unproject(Vector(x, y, 10));
	Vector diff = far - near;
	diff.normalize();
	// fix for the fact that camera is actually positioned negativelly in space ;)
    diff.x *= -1;
    diff.z *= -1;

	return Ray(near, diff);
}

std::string Camera::getType() const
{
	return TYPE;
}


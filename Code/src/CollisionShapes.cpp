#include "CollisionShapes.h"

CollisionShape BaseCollisionShape::getType() const
{
	return TYPE;
}

bool BaseCollisionShape::checkPicking(Vector&, const Ray&, const Matrix&) const
{
	return false;
}

BallCollisionShape::BallCollisionShape(const Vector& center, float radius) :
		m_sphere(center, radius)
{

}

bool BallCollisionShape::checkPicking(Vector& intersectionPoint, const Ray& ray, const Matrix& transformation) const
{
	Sphere transformed = m_sphere.getTransformed(transformation);
	return MathHelper::SphereRayIntersection(intersectionPoint, transformed, ray);
}

CollisionShape BallCollisionShape::getType() const
{
	return CS_BALL;
}

PlaneCollisionShape::PlaneCollisionShape(const Vector& normal) :
		m_plane(Vector(), normal)
{

}

CollisionShape PlaneCollisionShape::getType() const
{
	return CS_PLANE;
}

void PlaneCollisionShape::setNormal(const Vector& normal)
{
	m_plane.normal = normal;
}

Vector PlaneCollisionShape::getNormal() const
{
	return m_plane.normal;
}

bool PlaneCollisionShape::checkPicking(Vector& intersectionPoint, const Ray& ray, const Matrix& transformation) const
{
	return MathHelper::PlaneRayIntersection(intersectionPoint, m_plane.getTransformed(transformation), ray);
}

BoxCollisionShape::BoxCollisionShape(const Vector& lowCorner, const Vector& highCorner) :
		m_box(lowCorner, highCorner)
{

}

bool BoxCollisionShape::checkPicking(Vector& intersectionPoint, const Ray& ray, const Matrix& transformation) const
{
	return m_box.getTransformed(transformation).checkPicking(intersectionPoint, ray);
}



#ifndef BASE_COLLISION_SHAPE_H_
#define BASE_COLLISION_SHAPE_H_

#include "pi.h"

#include "MathHelper.h"

enum CollisionShape
{
	CS_NONE,
	CS_BALL,
	CS_PLANE,
	CS_BOX,
	CS_ENUM_SIZE
};

class BaseCollisionShape
{
public:
	static const CollisionShape TYPE = CS_NONE;

	virtual ~BaseCollisionShape() {}

	virtual CollisionShape getType() const;
	virtual bool checkPicking(Vector& intersectionPoint, const Ray& ray, const Matrix& transformation) const;
};

class BallCollisionShape : public BaseCollisionShape
{
public:
	static const CollisionShape TYPE = CS_BALL;

	BallCollisionShape(const Vector& center, float radius);

	virtual CollisionShape getType() const;

	bool checkPicking(Vector& intersectionPoint, const Ray& ray, const Matrix& transformation) const;

private:
	Sphere m_sphere;
};

class PlaneCollisionShape : public BaseCollisionShape
{
public:
	static const CollisionShape TYPE = CS_PLANE;

	PlaneCollisionShape(const Vector& normal);

	virtual CollisionShape getType() const;

	void setNormal(const Vector& normal);
	Vector getNormal() const;

	bool checkPicking(Vector& intersectionPoint, const Ray& ray, const Matrix& transformation) const;

private:
	Plane m_plane;
};

class BoxCollisionShape : public BaseCollisionShape
{
public:
	static const CollisionShape TYPE = CS_BOX;

	BoxCollisionShape(const Vector& lowCorner, const Vector& highCorner);

	virtual CollisionShape getType() const { return TYPE; }

	bool checkPicking(Vector& intersectionPoint, const Ray& ray, const Matrix& transformation) const;

private:
	BoundingBox m_box;
};

#endif // BASE_COLLISION_SHAPE_H_

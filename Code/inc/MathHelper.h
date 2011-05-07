/*
 * MathHelper.h
 *
 *  Created on: 2010-12-01
 *      Author: artur.m
 */

#ifndef MATHHELPER_H_
#define MATHHELPER_H_

#include "pi.h"

#include "Vector.h"

#define ARRAY_SIZE(x) (sizeof(x)/sizeof(*x))

class Matrix
{
public:
	Matrix();
	Matrix(const Matrix& rs);
    Matrix(float* m); // to construct from a table of float values

	Matrix& operator=(const Matrix& rs);

	void debugPrint() const;

	float m[16];
};

class Ray
{
public:
	Ray();
	Ray(const Vector& source, const Vector& direction);

	void debugPrint() const;

	Ray getTransformed(const Matrix& transformation) const;

	Vector source;
	Vector direction;
};

class Triangle
{
public:
	Triangle() { memset(corners, 0, sizeof(corners)); }
	Triangle(const Vector* vertices) { memcpy(corners, vertices, sizeof(corners)); }
	Triangle(const Vector& v1, const Vector& v2, const Vector& v3) { corners[0]=v1; corners[1]=v2; corners[2]=v3; }
	Triangle(const Triangle& rs) { memcpy(corners, rs.corners, sizeof(corners)); }
	Triangle& operator=(const Triangle& rs) { memcpy(corners, rs.corners, sizeof(corners)); return *this; }

	Triangle getTransformed(const Matrix& transform) const;
	bool checkPicking(Vector& result, const Ray& ray) const;

	// Obviously always 3 and also clockwise
	Vector corners[3];
};

class Plane
{
public:
	Plane();
	Plane(const Vector& point, const Vector& normal);
	// The normal vector will be calculated as cross(planar1, planar2).normalize()
	Plane(const Vector& point, const Vector& planar1, const Vector& planar2);

	static Plane createPlane(const Triangle& triangle);

	Plane getTransformed(const Matrix& transformation) const;

	void debugPrint() const;

	Vector point;
	Vector normal;
};

class Sphere
{
public:
	Sphere(const Vector& center = Vector(), float radius = 0);
	Sphere(const Sphere& other) : center(other.center), radius(other.radius) {}
	Sphere& operator=(const Sphere& other) { center = other.center; radius = other.radius; return *this;}
	Sphere getTransformed(const Matrix& transform) const;

	void debugPrint() const;

	Vector center;
	float radius;
};

class Viewport
{
public:
	Viewport();
	Viewport(int x, int y, int width, int height);

	int v[4];
};

class Rectangle
{
public:
	Rectangle(int x = 0, int y = 0, int width = 0, int height = 0);
	Rectangle(float x, float y, float width, float height);
	float x;
	float y;
	float width;
	float height;

	bool isInside(int x, int y) const;

	void debugPrint() const;

	Rectangle& operator=(const Rectangle& rs);
};

class BoundingBox
{
public:
	BoundingBox() { memset(m_triangles, 0, sizeof(m_triangles)); }
	BoundingBox(const BoundingBox& other) :
		m_boundingSphere(other.m_boundingSphere.center, other.m_boundingSphere.radius) {
		memcpy(m_triangles, other.m_triangles, sizeof(m_triangles));
	}
	BoundingBox(const Vector& lowCorner, const Vector& highCorner);
	BoundingBox& operator=(const BoundingBox& other) {
		memcpy(m_triangles, other.m_triangles, sizeof(m_triangles));
		m_boundingSphere = other.m_boundingSphere;
		return *this;
	}

	BoundingBox getTransformed(const Matrix& transform) const;
	bool checkPicking(Vector& intersection, const Ray& ray) const;

private:
	Triangle m_triangles[12]; // also always 12
	Sphere m_boundingSphere;
};

class MathHelper
{
public:
	static const float PI;

	static void LoadIdentity(Matrix& result);
	static void Perspective(Matrix& result, float fovy, float aspect, float nearZ, float farZ);
	static Matrix Ortho(float width, float height, float near, float far);
	static void Translate(Matrix& result, float tx, float ty, float tz);
	static void Rotate(Matrix& result, float angle, float x, float y, float z);
	static void Scale(Matrix& result, float scale);
	static Matrix Multiply(const Matrix& srcA, const Matrix& srcB);
	static void Invert(Matrix& result, const Matrix& src);
	static Vector Unproject(const Vector& source, const Matrix& modelView, const Matrix& projection, const Viewport& viewport);
	// Multiplies a (x, y, z, 0) vector
	static Vector MultiplyTransform(const Vector& source, const Matrix& transformation);
	// Mulitplies a (x, y, z, 1) vector
	static Vector MultiplyNormal(const Vector& source, const Matrix& transformation);
	static bool SphereRayIntersection(Vector& out, const Sphere& sphere, const Ray& ray);
	static bool PlaneRayIntersection(Vector& out, const Plane& plane, const Ray& ray);
	static bool BoundingBoxRayIntersection(Vector& out, const BoundingBox& box, const Ray& ray);

	template<class ValueT, class DiffT>
	static ValueT lerp(const ValueT& start, const ValueT& end, DiffT rangeA, DiffT rangeB, DiffT current)
	{
		float amount = static_cast<float>(current - rangeA) / (rangeB - rangeA);
		return lerp(start, end, amount);
	}

	template<class ValueT, class DiffT>
	static ValueT easeInOut(const ValueT& start, const ValueT& end, DiffT rangeA, DiffT rangeB, DiffT current)
	{
		float amount = static_cast<float>(current - rangeA) / (rangeB - rangeA);
		return easeInOut(start, end, amount);
	}

#define MH_CHECK_BOUNDARIES(start, end, x)\
	if(x <= 0) return start; \
	if(x >= 1) return end; \

#define MH_POW3(x) ((x)*(x)*(x))

	template<class ValueT>
	static ValueT lerp(const ValueT& start, const ValueT& end, float amount)
	{
		MH_CHECK_BOUNDARIES(start, end, amount);
		return start + ((end - start) * amount);
	}

	template<class ValueT>
	static ValueT easeInOut(const ValueT& start, const ValueT& end, float amount)
	{
		MH_CHECK_BOUNDARIES(start, end, amount);
		ValueT diff = end - start;
		if(amount < 0.5f)
		{
			return diff * 0.5f * MH_POW3(amount * 2) + start;
		}
		else
		{
			return diff * 0.5f * (MH_POW3(amount * 2 - 2) + 2) + start;
		}
	}

private:

	static void Multiply(const Matrix& matrix, const float in[4], float out[4]);

private:
	MathHelper();
	virtual ~MathHelper();
};

#endif /* MATHHELPER_H_ */

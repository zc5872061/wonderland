/*
 * MathHelper.cpp
 *
 *  Created on: 2010-12-01
 *      Author: artur.m
 */

#include <cmath>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <algorithm>

#include "pi.h"

#include "MathHelper.h"

Matrix::Matrix()
{
	for(int i = 0; i < 16; ++i)
	{
		m[i] = 0;
	}
}

Matrix::Matrix(const Matrix& rs)
{
	for(int i = 0; i < 16; ++i)
	{
		m[i] = rs.m[i];
	}
}

Matrix::Matrix(float* m)
{
    memcpy(this->m, m, sizeof(this->m));
}

Matrix& Matrix::operator=(const Matrix& rs)
{
	for(int i = 0; i < 16; ++i)
	{
		m[i] = rs.m[i];
	}
	return *this;
}

void Matrix::debugPrint() const
{
	Log("Matrix:");
	Log("    %f %f %f %f", m[0], m[4], m[8],  m[12]);
	Log("    %f %f %f %f", m[1], m[5], m[9],  m[13]);
	Log("    %f %f %f %f", m[2], m[6], m[10], m[14]);
	Log("    %f %f %f %f", m[3], m[7], m[11], m[15]);
}

Triangle Triangle::getTransformed(const Matrix& transform) const
{
	Triangle result;
	result.corners[0] = MathHelper::MultiplyTransform(corners[0], transform);
	result.corners[1] = MathHelper::MultiplyTransform(corners[1], transform);
	result.corners[2] = MathHelper::MultiplyTransform(corners[2], transform);
	return result;
}

bool Triangle::checkPicking(Vector& result, const Ray& ray) const
{
	// first find a point on the traingle's plane
	Plane plane(corners[0], corners[1]-corners[0], corners[2]-corners[0]);
	if(!MathHelper::PlaneRayIntersection(result, plane, ray))
	{
		return false;
	}

	Vector v;
	Vector diff;

	for(int i = 0; i < 3; ++i)
	{
		v = cross(plane.normal, corners[(i+1)%3] - corners[i]);
		diff = result - corners[i];
		if(dot(v, diff) < 0)
		{
			return false;
		}
	}
	return true;
}

Ray::Ray()
{

}

Ray::Ray(const Vector& source, const Vector& direction) :
		source(source),
		direction(direction)
{

}

void Ray::debugPrint() const
{
	Log("Ray - source (%f, %f, %f), direction (%f, %f, %f)", source.x, source.y, source.z, direction.x, direction.y, direction.z);
}

Ray Ray::getTransformed(const Matrix& transformation) const
{
	Vector newSource = MathHelper::MultiplyTransform(source, transformation);
	Vector newDirection = MathHelper::MultiplyNormal(direction, transformation);
	newDirection.normalize();
	return Ray(newSource, newDirection);
}

Plane::Plane() :
		point(),
		normal(0, 0, 1)
{

}

Plane::Plane(const Vector& point, const Vector& normal) :
		point(point),
		normal(normal)
{

}

Plane::Plane(const Vector& point, const Vector& planar1, const Vector& planar2) :
		point(point)
{
	normal = cross(planar1, planar2).normalize();
}

Plane Plane::getTransformed(const Matrix& transformation) const
{
	Plane result;
	result.normal = MathHelper::MultiplyNormal(normal, transformation);
	result.point = MathHelper::MultiplyTransform(point, transformation);
	return result;
}

void Plane::debugPrint() const
{
	Log("Plane - point (%f, %f, %f), normal (%f, %f, %f)", point.x, point.y, point.z, normal.x, normal.y, normal.z);
}

Plane Plane::createPlane(const Triangle& triangle)
{
	Plane result;
	result.point = triangle.corners[0];
	Vector diff1 = (triangle.corners[1] - triangle.corners[0]).normalize();
	Vector diff2 = (triangle.corners[2] - triangle.corners[0]).normalize();
	result.normal = cross(diff1, diff2).normalize();
	return result;
}

Sphere::Sphere(const Vector& center, GLfloat radius) :
		center(center),
		radius(radius)
{
}

Sphere Sphere::getTransformed(const Matrix& transform) const
{
	Sphere result;

	// To calculate radius a vector is generated from its value and transformed;
	result.radius = MathHelper::MultiplyNormal(Vector(0, 0, radius), transform).length();
	result.center = MathHelper::MultiplyTransform(center, transform);
	return result;
}

void Sphere::debugPrint() const
{
	Log("Sphere: center - (%f, %f, %f), radius - %f", center.x, center.y, center.z, radius);
}

Viewport::Viewport()
{
	v[0] = v[1] = v[2] = v[3] = 0;
}

Viewport::Viewport(int x, int y, int width, int height)
{
	v[0] = x;
	v[1] = y;
	v[2] = width;
	v[3] = height;
}

Rectangle::Rectangle(int x, int y, int width, int height) :
		x(x),
		y(y),
		width(width),
		height(height)
{

}

Rectangle::Rectangle(GLfloat x, GLfloat y, GLfloat width, GLfloat height) :
	x(x),
	y(y),
	width(width),
	height(height)
{

}

Rectangle& Rectangle::operator=(const Rectangle& rs)
{
	x = rs.x;
	y = rs.y;
	width = rs.width;
	height = rs.height;
	return *this;
}

bool Rectangle::isInside(int px, int py) const
{
	return px >= x && px <= (x+width) && py >= y && py <= (y+height);
}

void Rectangle::debugPrint() const
{
	Log("Rectangle: %f, %f, %f, %f", x, y, width, height);
}

const float MathHelper::PI(3.1415926535897932384626433832795f);

MathHelper::MathHelper() 
{

}

MathHelper::~MathHelper() 
{

}

void
MathHelper::LoadIdentity(Matrix& result)
{
	for(int i = 0; i < 16; ++i)
	{
		result.m[i] = 0;
	}
	for(int i = 0; i < 4; ++i)
	{
		result.m[i*4+i] = 1;
	}
}

void
MathHelper::Perspective(Matrix& result, float fovy, float aspect, float nearZ, float farZ)
{
	result = Matrix();

	GLfloat f = 1.f / tanf( (PI * fovy /180) / 2);
	result.m[0] = f / aspect;
	result.m[4*1 + 1] = f;
	result.m[4*2 + 2] = (farZ + nearZ) / (nearZ - farZ);
	result.m[4*2 + 3] = -1;
	result.m[4*3 + 2] = (2 * farZ * nearZ) / (nearZ - farZ);
}


void
MathHelper::Translate(Matrix& result, GLfloat tx, GLfloat ty, GLfloat tz)
{
	LoadIdentity(result);
	result.m[3*4 + 0] = tx;
	result.m[3*4 + 1] = ty;
	result.m[3*4 + 2] = tz;
}


void
MathHelper::Rotate(Matrix& result, GLfloat angle, GLfloat x, GLfloat y, GLfloat z)
{
	GLfloat c = cosf(angle);
	GLfloat s = sinf(angle);
	Vector axis(x, y, z);
	axis.normalize();

	LoadIdentity(result);
	x = axis.x;
	y = axis.y;
	z = axis.z;

	result.m[0*4 + 0] = x*x * (1-c) + c;
	result.m[0*4 + 1] = y*x * (1-c) + z*s;
	result.m[0*4 + 2] = x*z * (1-c) - y*s;

	result.m[1*4 + 0] = x*y * (1-c) - z*s;
	result.m[1*4 + 1] = y*y * (1-c) + c;
	result.m[1*4 + 2] = y*z * (1-c) + x*s;

	result.m[2*4 + 0] = x*z * (1-c) + y*s;
	result.m[2*4 + 1] = y*z * (1-c)	- x*s;
	result.m[2*4 + 2] = z*z * (1-c) + c;
}

void MathHelper::Scale(Matrix& result, GLfloat scale)
{
	LoadIdentity(result);
	result.m[0] = scale;
	result.m[5] = scale;
	result.m[10] = scale;
	result.m[15] = 1.0f;
}

Matrix
MathHelper::Multiply(const Matrix& srcA, const Matrix& srcB)
{
	Matrix m;
	Matrix a = srcA;
	Matrix b = srcB;

	m.m[0] = a.m[0]*b.m[0] + a.m[1]*b.m[4] + a.m[2]*b.m[8] + a.m[3]*b.m[12];
	m.m[1] = a.m[0]*b.m[1] + a.m[1]*b.m[5] + a.m[2]*b.m[9] + a.m[3]*b.m[13];
	m.m[2] = a.m[0]*b.m[2] + a.m[1]*b.m[6] + a.m[2]*b.m[10] + a.m[3]*b.m[14];
	m.m[3] = a.m[0]*b.m[3] + a.m[1]*b.m[7] + a.m[2]*b.m[11] + a.m[3]*b.m[15];

	m.m[4] = a.m[4]*b.m[0] + a.m[5]*b.m[4] + a.m[6]*b.m[8] + a.m[7]*b.m[12];
	m.m[5] = a.m[4]*b.m[1] + a.m[5]*b.m[5] + a.m[6]*b.m[9] + a.m[7]*b.m[13];
	m.m[6] = a.m[4]*b.m[2] + a.m[5]*b.m[6] + a.m[6]*b.m[10] + a.m[7]*b.m[14];
	m.m[7] = a.m[4]*b.m[3] + a.m[5]*b.m[7] + a.m[6]*b.m[11] + a.m[7]*b.m[15];

	m.m[8] = a.m[8]*b.m[0] + a.m[9]*b.m[4] + a.m[10]*b.m[8] + a.m[11]*b.m[12];
	m.m[9] = a.m[8]*b.m[1] + a.m[9]*b.m[5] + a.m[10]*b.m[9] + a.m[11]*b.m[13];
	m.m[10] = a.m[8]*b.m[2] + a.m[9]*b.m[6] + a.m[10]*b.m[10] + a.m[11]*b.m[14];
	m.m[11] = a.m[8]*b.m[3] + a.m[9]*b.m[7] + a.m[10]*b.m[11] + a.m[11]*b.m[15];

	m.m[12] = a.m[12]*b.m[0] + a.m[13]*b.m[4] + a.m[14]*b.m[8] + a.m[15]*b.m[12];
	m.m[13] = a.m[12]*b.m[1] + a.m[13]*b.m[5] + a.m[14]*b.m[9] + a.m[15]*b.m[13];
	m.m[14] = a.m[12]*b.m[2] + a.m[13]*b.m[6] + a.m[14]*b.m[10] + a.m[15]*b.m[14];
	m.m[15] = a.m[12]*b.m[3] + a.m[13]*b.m[7] + a.m[14]*b.m[11] + a.m[15]*b.m[15];

	return m;
}

void MathHelper::Invert(Matrix& inverse, const Matrix& src)
{
	int i, j, k, swap;
	double t;
	GLfloat temp[4][4];

	for (i=0; i<4; i++)
	{
		for (j=0; j<4; j++)
		{
			temp[i][j] = src.m[i*4+j];
		}
	}

	LoadIdentity(inverse);

	for (i = 0; i < 4; i++)
	{
		/*
		** Look for largest element in column
		*/
		swap = i;
		for (j = i + 1; j < 4; j++)
		{
			if (fabs(temp[j][i]) > fabs(temp[i][i]))
			{
				swap = j;
			}
		}

		if (swap != i)
		{
			/*
			** Swap rows.
			*/
			for (k = 0; k < 4; k++)
			{
				t = temp[i][k];
				temp[i][k] = temp[swap][k];
				temp[swap][k] = t;

				t = inverse.m[i*4+k];
				inverse.m[i*4+k] = inverse.m[swap*4+k];
				inverse.m[swap*4+k] = t;
			}
		}

		if (temp[i][i] == 0)
		{
			/*
			** No non-zero pivot.  The matrix is singular, which shouldn't
			** happen.  This means the user gave us a bad matrix.
			*/
			assert(0);
		}

		t = temp[i][i];
		for (k = 0; k < 4; k++)
		{
			temp[i][k] /= t;
			inverse.m[i*4+k] /= t;
		}
		for (j = 0; j < 4; j++)
		{
			if (j != i)
			{
				t = temp[j][i];
				for (k = 0; k < 4; k++)
				{
					temp[j][k] -= temp[i][k]*t;
					inverse.m[j*4+k] -= inverse.m[i*4+k]*t;
				}
			}
		}
	}
}

Vector MathHelper::Unproject(const Vector& source, const Matrix& modelView, const Matrix& projection, const Viewport& viewport)
{
	GLfloat in[4];
	GLfloat out[4];

	Matrix finalMatrix = Multiply(modelView, projection);
	Invert(finalMatrix, finalMatrix);

	in[0]=source.x;
	in[1]=source.y;
	in[2]=source.z;
	in[3]=1.0;

	/* Map x and y from window coordinates */
	in[0] = (in[0] - viewport.v[0]) / viewport.v[2];
	in[1] = (in[1] - viewport.v[1]) / viewport.v[3];

	/* Map to range -1 to 1 */
	in[0] = in[0] * 2 - 1;
	in[1] = in[1] * 2 - 1;
	in[2] = in[2] * 2 - 1;

	Multiply(finalMatrix, in, out);
	if (out[3] == 0.0)
	{
		assert(0);
	}
	out[0] /= out[3];
	out[1] /= out[3];
	out[2] /= out[3];

	return Vector(out[0], out[1], out[2]);
}

Matrix MathHelper::Ortho(GLfloat width, GLfloat height, GLfloat near, GLfloat far)
{
	Matrix result;
	LoadIdentity(result);
	result.m[0] = 2.0f / width;
	result.m[5] = 2.0f / height;
	result.m[10] = -1.0f;
	result.m[12] = -1.0f;
	result.m[13] = -1.0f;

	return result;
}

Vector MathHelper::MultiplyTransform(const Vector& source, const Matrix& transformation)
{
	GLfloat in[4] = {source.x, source.y, source.z, 1};
	GLfloat out[4];
	Multiply(transformation, in, out);
	return Vector(out[0]/out[3], out[1]/out[3], out[2]/out[3]);
}

Vector MathHelper::MultiplyNormal(const Vector& source, const Matrix& transformation)
{
	GLfloat in[4] = {source.x, source.y, source.z, 0};
	GLfloat out[4];
	Multiply(transformation, in, out);
	return Vector(out[0], out[1], out[2]);
}

void MathHelper::Multiply(const Matrix& matrix, const GLfloat in[4], GLfloat out[4])
{
    for (int i=0; i<4; ++i)
    {
		out[i] =
				in[0] * matrix.m[0*4+i] +
				in[1] * matrix.m[1*4+i] +
				in[2] * matrix.m[2*4+i] +
				in[3] * matrix.m[3*4+i];
    }
}

bool MathHelper::SphereRayIntersection(Vector& out, const Sphere& sphere, const Ray& ray)
{
	GLfloat a = ray.direction.x*ray.direction.x +
				ray.direction.y*ray.direction.y +
				ray.direction.z*ray.direction.z;
	GLfloat b = 2 * ((ray.source.x-sphere.center.x)*ray.direction.x +
					 (ray.source.y-sphere.center.y)*ray.direction.y +
					 (ray.source.z-sphere.center.z)*ray.direction.z );
	GLfloat c = (ray.source.x-sphere.center.x)*(ray.source.x-sphere.center.x) +
				(ray.source.y-sphere.center.y)*(ray.source.y-sphere.center.y) +
				(ray.source.z-sphere.center.z)*(ray.source.z-sphere.center.z) -
				sphere.radius*sphere.radius;

	GLfloat delta = b*b - 4*a*c;

	if(delta < 0)
	{
		return false;
	}

	GLfloat deltaSqrt = sqrtf(delta);
	GLfloat t = (-b - deltaSqrt) / (2*a);

	if(t < 0)
	{
		return false;
	}

	out = ray.source + t * ray.direction;

	return true;
}

bool MathHelper::PlaneRayIntersection(Vector& out, const Plane& plane, const Ray& ray)
{
	GLfloat nominator = dot((plane.point - ray.source), plane.normal);
	GLfloat denominator = dot(ray.direction, plane.normal);

	if(denominator == 0)
	{
		return false;
	}

	GLfloat distance = nominator / denominator;

	if(distance < 0)
	{
		return false;
	}

	out = ray.source + distance * ray.direction;

	return true;
}

BoundingBox::BoundingBox(const Vector& lowCorner, const Vector& highCorner)
{
	Triangle* trianglePointer = m_triangles;
	//top side
	Vector v1(lowCorner.x, lowCorner.y, highCorner.z);
	Vector v2(highCorner.x, lowCorner.y, highCorner.z);
	Vector v3(highCorner);
	Vector v4(lowCorner.x, highCorner.y, highCorner.z);

	//bottom side
	Vector v5(lowCorner);
	Vector v6(highCorner.x, lowCorner.y, lowCorner.z);
	Vector v7(highCorner.x, highCorner.y, lowCorner.z);
	Vector v8(lowCorner.x, highCorner.y, lowCorner.z);

	// top
	*(trianglePointer++) = Triangle(v1, v2, v3);
	*(trianglePointer++) = Triangle(v1, v3, v4);

	//bottom
	*(trianglePointer++) = Triangle(v5, v7, v6);
	*(trianglePointer++) = Triangle(v5, v8, v7);

	//left
	*(trianglePointer++) = Triangle(v5, v1, v8);
	*(trianglePointer++) = Triangle(v1, v4, v8);

	//right
	*(trianglePointer++) = Triangle(v3, v7, v2);
	*(trianglePointer++) = Triangle(v2, v7, v6);

	//front
	*(trianglePointer++) = Triangle(v1, v5, v2);
	*(trianglePointer++) = Triangle(v2, v5, v6);

	//back
	*(trianglePointer++) = Triangle(v8, v4, v3);
	*(trianglePointer++) = Triangle(v8, v3, v7);

	m_boundingSphere.center = (lowCorner + highCorner) * 0.5f;
	m_boundingSphere.radius = (highCorner - lowCorner).length();
}

BoundingBox BoundingBox::getTransformed(const Matrix& transform) const
{
	BoundingBox result(*this);
	for(size_t i = 0; i < ARRAY_SIZE(m_triangles); ++i)
	{
		result.m_triangles[i] = m_triangles[i].getTransformed(transform);
	}
	result.m_boundingSphere = m_boundingSphere.getTransformed(transform);
	return result;
}

bool BoundingBox::checkPicking(Vector& intersection, const Ray& ray) const
{
	// First check against bounding sphere, so then only if the bounding sphere is
	// intersected following more consuming calculations will run
	if(!MathHelper::SphereRayIntersection(intersection, m_boundingSphere, ray))
	{
		return false;
	}
	// since it's a box at most two triangles can be intersected (and unless there is a strange
	// boundary case or the start point is inside the box there will usually be exactly two
	Vector intersected[2];
	Vector* current = intersected;
	bool found = false;
	for(const Triangle* it = m_triangles; it != m_triangles + ARRAY_SIZE(m_triangles); ++it)
	{
		if((*it).checkPicking(*current, ray))
		{
			found = true;
			if(current == intersected + 1)
			{
				break;
			}
			++current;
		}
	}
	if(!found)
	{
		return false;
	}
	float l0 = (ray.source - intersected[0]).length();
	float l1 = (ray.source - *current).length();

	intersection = l0 < l1 ? intersected[0] : intersected[1];

	return true;
}

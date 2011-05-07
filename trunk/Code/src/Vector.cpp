/*
 * Vector.cpp
 *
 *  Created on: 2010-12-01
 *      Author: artur.m
 */

#include "Vector.h"


Vector::Vector() :
	x(0),
	y(0),
	z(0)
{
}

Vector::Vector(float x, float y, float z) :
		x(x),
		y(y),
		z(z)
{
}

float Vector::length() const
{
	return sqrtf(x*x + y*y + z*z);
}

Vector& Vector::normalize()
{
	float len = length();
	x /= len;
	y /= len;
	z /= len;

	return *this;
}

Vector Vector::getNormalized() const
{
	Vector result(x, y, z);
	result.normalize();
	return result;
}

void Vector::debugPrint() const
{
	Log("Vector - (%f, %f, %f)", x, y, z);
}

Vector& Vector::operator+=(const Vector& other)
{
	x += other.x;
	y += other.y;
	z += other.z;

	return *this;
}

Vector& Vector::operator/=(float value)
{
	return operator*=(1.0f/value);
}

Vector& Vector::operator*=(float value)
{
	x *= value;
	y *= value;
	z *= value;
	return *this;
}

Vector& Vector::operator-=(const Vector& other)
{
	return operator+=(-other);
}

Vector operator-(const Vector& rs)
{
	return Vector(-rs.x, -rs.y, -rs.z);
}

Vector operator-(const Vector& ls, const Vector& rs)
{
	return Vector(ls.x - rs.x, ls.y - rs.y, ls.z - rs.z);
}

Vector operator+(const Vector& ls, const Vector& rs)
{
	return Vector(ls.x + rs.x, ls.y + rs.y, ls.z + rs.z);
}

Vector operator*(const Vector& ls, const float amount)
{
	return Vector(ls.x * amount, ls.y * amount, ls.z * amount);
}

Vector operator*(const float amount, const Vector& ls)
{
	return operator*(ls, amount);
}

float dot(const Vector& ls, const Vector& rs)
{
	return ls.x * rs.x + ls.y * rs.y + ls.z * rs.z;
}

Vector cross(const Vector& b, const Vector& c)
{
	Vector result;
	result.x = b.y*c.z - b.z*c.y;
	result.y = b.z*c.x - b.x*c.z;
	result.z = b.x*c.y - b.y*c.x;
	return result;
}

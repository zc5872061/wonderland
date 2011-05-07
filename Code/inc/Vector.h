/*
 * Vector.h
 *
 *  Created on: 2010-12-01
 *      Author: artur.m
 */

#ifndef VECTOR_H_
#define VECTOR_H_

#include <cmath>

#include "pi.h"

class Vector
{
public:
	Vector();
	Vector(float x, float y, float z);

	float length() const;
	Vector& normalize();
	Vector getNormalized() const;

	void debugPrint() const;

	Vector& operator+=(const Vector& other);
	Vector& operator-=(const Vector& other);
	Vector& operator/=(float value);
	Vector& operator*=(float value);


	float x;
	float y;
	float z;
};

Vector operator-(const Vector& rs);
Vector operator-(const Vector& ls, const Vector& rs);
Vector operator+(const Vector& ls, const Vector& rs);
Vector operator*(const Vector& ls, const float amount);
Vector operator*(const float amount, const Vector& ls);
float dot(const Vector& ls, const Vector& rs);
Vector 	cross(const Vector& ls, const Vector& rs);

#endif /* VECTOR_H_ */

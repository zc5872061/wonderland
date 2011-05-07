/*
 * Camera.h
 *
 *  Created on: 2010-12-02
 *      Author: artur.m
 */

#ifndef CAMERA_H_
#define CAMERA_H_

#include <string>

#include "MathHelper.h"
#include "Actor.h"
#include "shared_ptr.h"

class Camera : public Actor
{
public:
	static const std::string TYPE;
    
    static shared_ptr<Camera> spawn();
	virtual ~Camera();
    
	virtual std::string getType() const;
	void initialize(int width, int height, float fov, float near, float far, Vector position);

	virtual void setPosition(const Vector& pos);
	virtual Vector getPosition() const;

	const Matrix& getProjectionMatrix() const;
	const Matrix& getModelViewMatrix() const;
    // Returns the orthogonal projection that will map (x,y) to (x,y) on screen exactly
    const Matrix& getOrthoMatrix() const;

	int getWidth() const;
	int getHeight() const;

	Vector unproject(const Vector& point) const;
	Ray getRay(int x, int y) const;
private:
	Matrix m_matProjection;
	Matrix m_matModelView;
    Matrix m_matOrthoMatrix;
	int m_width;
	int m_height;
    
private:
    Camera();
};

#endif /* CAMERA_H_ */

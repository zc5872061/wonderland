/*
 * LineActor.h
 *
 *  Created on: 2011-01-05
 *      Author: artur.m
 */

#ifndef LINEACTOR_H_
#define LINEACTOR_H_

#include "Actor.h"

#include <vector>
#include <string>

#include "Vector.h"
#include "Program.h"
#include "shared_ptr.h"

class LineActor : public Actor
{
public:
	static const std::string TYPE;

	typedef std::vector<Vector> CreationParams;

    static shared_ptr<LineActor> spawn(const Vector& position, const CreationParams& points);
	virtual ~LineActor();

	virtual std::string getType() const;

	void setLineWidth(GLfloat value);
	GLfloat getLineWidth() const;
    
    void setColor(const Vector& color);
    Vector getColor() const { return m_color; }

private:
	LineActor(const Vector& position, const CreationParams& points);

	void createMesh(const std::vector<Vector>& points);
    
private:
    static int s_instancesCount;

	std::string m_meshName;

	GLfloat m_lineWidth;
    Vector m_color;
};

#endif /* LINEACTOR_H_ */

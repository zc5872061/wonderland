/*
 * Shader.h
 *
 *  Created on: 2010-12-10
 *      Author: artur.m
 */

#ifndef SHADER_H_
#define SHADER_H_

#include "pi.h"

#include <string>

class Shader
{
public:
	friend class ShaderManager;

	enum ShaderType
	{
		ST_NONE,
		ST_VERTEX,
		ST_FRAGMENT
	};

	ShaderType getType() const;

	GLuint getShader();
	void deleteShader();

private:
	ShaderType m_type;
	GLuint m_shaderObject;

	Shader();
	~Shader();
	Shader(const std::string& fileName, ShaderType type);

	Shader(const Shader&);
	Shader& operator=(const Shader&);
};

#endif /* SHADER_H_ */

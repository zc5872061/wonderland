/*
 * Shader.cpp
 *
 *  Created on: 2010-12-10
 *      Author: artur.m
 */

#include "Shader.h"
#include "GameFile.h"

#include "GLRenderer.h"

Shader::Shader() :
	m_type(ST_NONE)
{

}

Shader::Shader(const std::string& fileName, ShaderType type) :
	m_type(type),
	m_shaderObject(0)
{
	if(m_type == ST_VERTEX)
	{
		m_shaderObject = glCreateShader(GL_VERTEX_SHADER);
	}
	else if(m_type == ST_FRAGMENT)
	{
		m_shaderObject = glCreateShader(GL_FRAGMENT_SHADER);
	}
	else
	{
		assert(0);
	}

	GLboolean shaderCompiler = GL_FALSE;
	glGetBooleanv(GL_SHADER_COMPILER, &shaderCompiler);

	assert(shaderCompiler == GL_TRUE);

    shared_ptr<GameFile> shaderFile = GameFile::openFile(fileName, "r");
	std::string shaderText = shaderFile->read();
	const char* shaderTextCstr = shaderText.c_str();

	glShaderSource(m_shaderObject, 1, &shaderTextCstr, null);
	glCompileShader(m_shaderObject);

	GLint bShaderCompiled = GL_FALSE;
	glGetShaderiv(m_shaderObject, GL_COMPILE_STATUS, &bShaderCompiled);

	assert(bShaderCompiled == GL_TRUE);
}

Shader::~Shader()
{

}

Shader::ShaderType Shader::getType() const
{
	return m_type;
}

void Shader::deleteShader()
{
	glDeleteShader(m_shaderObject);
}

GLuint Shader::getShader()
{
	return m_shaderObject;
}

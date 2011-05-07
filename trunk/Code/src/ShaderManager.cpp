/*
 * ShaderManager.cpp
 *
 *  Created on: 2010-12-13
 *      Author: artur.m
 */

#include "ShaderManager.h"

ShaderManager::ShaderManager()
{

}

ShaderManager::~ShaderManager()
{
	for(ShadersIter it = m_vertexShaders.begin(); it != m_vertexShaders.end(); ++it)
	{
		(*it).second->deleteShader();
		delete (*it).second;
	}
	m_vertexShaders.clear();
	for(ShadersIter it = m_fragmentShaders.begin(); it != m_fragmentShaders.end(); ++it)
	{
		(*it).second->deleteShader();
		delete (*it).second;
	}
	m_fragmentShaders.clear();
	for(ProgramsIter it = m_programs.begin(); it != m_programs.end(); ++it)
	{
		(*it).second->deleteProgram();
		delete (*it).second;
	}
	m_programs.clear();
}

Shader* ShaderManager::getVertexShader(const std::string& shaderName)
{
	if(m_vertexShaders.find(shaderName) != m_vertexShaders.end())
	{
		Shader* result = m_vertexShaders[shaderName];
		assert(result->getType() == Shader::ST_VERTEX);
		return result;
	}
	Shader* result = new Shader(Constants::getRootPath() + shaderName, Shader::ST_VERTEX);
	m_vertexShaders[shaderName] = result;
	return result;
}

Shader* ShaderManager::getFragmentShader(const std::string& shaderName)
{
	if(m_fragmentShaders.find(shaderName) != m_fragmentShaders.end())
	{
		Shader* result = m_fragmentShaders[shaderName];
		assert(result->getType() == Shader::ST_FRAGMENT);
		return result;
	}
	Shader* result = new Shader(Constants::getRootPath() + shaderName, Shader::ST_FRAGMENT);
	m_fragmentShaders[shaderName] = result;
	return result;
}

Program* ShaderManager::getProgram(const std::string& vertexShaderPath, const std::string& fragmentShaderPath)
{
	ProgramsIter it = m_programs.find(std::make_pair(vertexShaderPath, fragmentShaderPath));
	if(it != m_programs.end())
	{
		return (*it).second;
	}

	Shader* vertexShader = getVertexShader(vertexShaderPath);
	Shader* fragmentShader = getFragmentShader(fragmentShaderPath);

	Program* program = new Program(vertexShader, fragmentShader);
	m_programs[std::make_pair(vertexShaderPath, fragmentShaderPath)] = program;

	return program;
}

// Placed here so that one day when we need to use binary shaders it will be easier to implement them
//GLint numFormats = 0;
//	glGetIntegerv(GL_NUM_SHADER_BINARY_FORMATS, &numFormats);
//	else if (0 < numFormats)
//	{
//		Log("0<numFormats");
//		GLboolean compiled = GL_FALSE;
//		GLint* formats = new GLint[numFormats];
//		glGetIntegerv(GL_SHADER_BINARY_FORMATS, formats);
//		for (GLint i = 0; i < numFormats; i++)
//		{
////			glShaderBinary(1, &fragShader, formats[i] , fragment, fragment_size);
//			if (glGetError())
//			{
//				continue;
//			}
////			glShaderBinary(1, &vertShader, formats[i] , vertex, vertex_size);
//			if (glGetError())
//			{
//				continue;
//			}
//			compiled = GL_TRUE;
//			break;
//		}
//		delete [] formats;
//
//		if (GL_FALSE == compiled)
//		{
////			goto CATCH;
//		}
//	}

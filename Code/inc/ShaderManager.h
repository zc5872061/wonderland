/*
 * ShaderManager.h
 *
 *  Created on: 2010-12-13
 *      Author: artur.m
 */

#ifndef SHADERMANAGER_H_
#define SHADERMANAGER_H_

#include "pi.h"

#include <string>
#include <map>
#include <utility>

#include "Shader.h"
#include "Program.h"

class ShaderManager
{
public:
	ShaderManager();
	virtual ~ShaderManager();

	Shader* getVertexShader(const std::string& shaderName);
	Shader* getFragmentShader(const std::string& shaderName);
	Program* getProgram(const std::string& vertexShader, const std::string& fragmentShader);
//	GLuint getProgram(Shader* vertexShader, Shader* fragmentShader);

private:
	typedef std::map<std::string, Shader*> ShadersContainer;
	typedef ShadersContainer::iterator ShadersIter;
	ShadersContainer m_vertexShaders;
	ShadersContainer m_fragmentShaders;

	typedef std::map<std::pair<std::string, std::string>, Program*> ProgramsContainer;
	typedef ProgramsContainer::iterator ProgramsIter;
	ProgramsContainer m_programs;
};

#endif /* SHADERMANAGER_H_ */

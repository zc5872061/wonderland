/*
 * Program.h
 *
 *  Created on: 2010-12-13
 *      Author: artur.m
 */

#ifndef PROGRAM_H_
#define PROGRAM_H_

#include "pi.h"

#include "Shader.h"

#include <string>
#include <map>
#include <memory>

class Program
{
public:
	friend class ShaderManager;

	static const std::string ATTRIBUTE_POSITION;
	static const std::string ATTRIBUTE_NORMAL;
	static const std::string ATTRIBUTE_UV;
	static const std::string UNIFORM_MATRIX;
	static const std::string UNIFORM_MODEL_MATRIX;
	static const std::string UNIFORM_LIGHT_DIR;
	static const std::string UNIFORM_DIFFUSE_COLOR;
	static const std::string UNIFORM_AMBIENT_COLOR;
	static const std::string UNIFORM_SAMPLER2D;
	static const std::string UNIFORM_LINE_WIDTH;
	static const std::string UNIFORM_ENABLED;
	static const std::string UNIFORM_CAMERA_POS;
	static const std::string UNIFORM_FRESNEL_AMOUNT;


	void deleteProgram();

	GLuint getId() const;

	GLint getLocation(const std::string& locationName);

private:
	void loadLocations();
	void initialize();

private:
	GLuint m_id;
	Shader* m_vertexShader;
	Shader* m_fragmentShader;

	typedef std::map<std::string, GLint>::iterator LocationsIter;
	std::map<std::string, GLint> m_locations;

private:
	Program(Shader* vertexShader, Shader* fragmentShader);
	Program(const std::string& vertexShaderPath, const std::string& fragmentShaderPath);
	virtual ~Program();

	Program& operator=(const Program&);
	Program(const Program&);
};

#endif /* PROGRAM_H_ */

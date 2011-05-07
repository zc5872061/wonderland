/*
 * Program.cpp
 *
 *  Created on: 2010-12-13
 *      Author: artur.m
 */

#include "Program.h"

#include "Game.h"
//
const std::string Program::ATTRIBUTE_POSITION("a_position");
const std::string Program::ATTRIBUTE_NORMAL("a_normal");
const std::string Program::ATTRIBUTE_UV("a_uv");
const std::string Program::UNIFORM_MATRIX("u_mvpMatrix");
const std::string Program::UNIFORM_MODEL_MATRIX("u_mMatrix");
const std::string Program::UNIFORM_LIGHT_DIR("u_lightDirection");
const std::string Program::UNIFORM_DIFFUSE_COLOR("u_diffuseColor");
const std::string Program::UNIFORM_AMBIENT_COLOR("u_ambientColor");
const std::string Program::UNIFORM_SAMPLER2D("u_textureSampler");
const std::string Program::UNIFORM_LINE_WIDTH("u_lineWidth");
const std::string Program::UNIFORM_ENABLED("u_enabled");
const std::string Program::UNIFORM_CAMERA_POS("u_cameraPos");
const std::string Program::UNIFORM_FRESNEL_AMOUNT("u_fresnelAmount");

Program::Program(Shader* vertexShader, Shader* fragmentShader) :
	m_id(-1),
	m_vertexShader(vertexShader),
	m_fragmentShader(fragmentShader)
{
	initialize();
}

Program::Program(const std::string& vertexShaderPath, const std::string& fragmentShaderPath) :
	m_id(-1),
	m_vertexShader(Game::getInstance().getRenderer().getShaderManager().getVertexShader(vertexShaderPath)),
	m_fragmentShader(Game::getInstance().getRenderer().getShaderManager().getFragmentShader(fragmentShaderPath))
{
	initialize();
}

void Program::initialize()
{
	m_id = glCreateProgram();
	glAttachShader(m_id, m_vertexShader->getShader());
	glAttachShader(m_id, m_fragmentShader->getShader());

	GLint linked = GL_FALSE;
	glLinkProgram(m_id);
	glGetProgramiv(m_id, GL_LINK_STATUS, &linked);
	if (GL_FALSE == linked)
	{
		GLint infoLen = 0;
		glGetProgramiv(m_id, GL_INFO_LOG_LENGTH, &infoLen);
		if (infoLen > 1)
		{
			char* infoLog = new char[infoLen];
			glGetProgramInfoLog(m_id, infoLen, null, infoLog);
			Log("Linking has failed. log: %s\n", infoLog);
			delete [] infoLog;
		}
		assert(0);
	}

	loadLocations();
}

Program::~Program()
{
	deleteProgram();
}

void Program::deleteProgram()
{
	glDeleteProgram(m_id);
}

GLuint Program::getId() const
{
	return m_id;
}

void Program::loadLocations()
{
	m_locations[ATTRIBUTE_POSITION] = glGetAttribLocation(m_id, ATTRIBUTE_POSITION.c_str());
	m_locations[ATTRIBUTE_NORMAL] = glGetAttribLocation(m_id, ATTRIBUTE_NORMAL.c_str());
	m_locations[ATTRIBUTE_UV] = glGetAttribLocation(m_id, ATTRIBUTE_UV.c_str());
	m_locations[UNIFORM_MATRIX] = glGetUniformLocation(m_id, UNIFORM_MATRIX.c_str());
	m_locations[UNIFORM_MODEL_MATRIX] = glGetUniformLocation(m_id, UNIFORM_MODEL_MATRIX.c_str());
	m_locations[UNIFORM_DIFFUSE_COLOR] = glGetUniformLocation(m_id, UNIFORM_DIFFUSE_COLOR.c_str());
	m_locations[UNIFORM_AMBIENT_COLOR] = glGetUniformLocation(m_id, UNIFORM_AMBIENT_COLOR.c_str());
	m_locations[UNIFORM_LIGHT_DIR] = glGetUniformLocation(m_id, UNIFORM_LIGHT_DIR.c_str());
	m_locations[UNIFORM_SAMPLER2D] = glGetUniformLocation(m_id, UNIFORM_SAMPLER2D.c_str());
	m_locations[UNIFORM_LINE_WIDTH] = glGetUniformLocation(m_id, UNIFORM_LINE_WIDTH.c_str());
	m_locations[UNIFORM_ENABLED] = glGetUniformLocation(m_id, UNIFORM_ENABLED.c_str());
	m_locations[UNIFORM_CAMERA_POS] = glGetUniformLocation(m_id, UNIFORM_CAMERA_POS.c_str());
	m_locations[UNIFORM_FRESNEL_AMOUNT] = glGetUniformLocation(m_id, UNIFORM_FRESNEL_AMOUNT.c_str());

	for(LocationsIter it = m_locations.begin(); it != m_locations.end(); ++it)
	{
		if((*it).second == GL_INVALID_OPERATION)
		{
			Log("GLAttributes::initialize - problem with %s", (*it).first.c_str());
			assert(0);
		}
	}
}

GLint Program::getLocation(const std::string& locationName)
{
	// If assert fails make sure that the location name was added in Program::loadLocations
	assert(m_locations.find(locationName) != m_locations.end());
	return m_locations[locationName];
}



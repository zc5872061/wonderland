/*
 * Material.cpp
 *
 *  Created on: 2011-02-13
 *      Author: Artur
 */

#include "Engine/Material.h"

#include "pi.h"
#include "Game.h"

#include <algorithm>

std::vector<std::string> Material::s_warningVariables;

Material::Material(Program* program, const std::string& name) :
	m_program(program),
    m_name(name)
{
	memset(m_locations, GL_INVALID_LOCATION, sizeof(m_locations));
}

void Material::setAttribute(const LocationInfo& location, const float* data, int stride)
{
	// no assert here to make at least some optimizations ;P
	glVertexAttribPointer(location.location, stride, GL_FLOAT, GL_FALSE, 0 * stride * sizeof(GLfloat), data);
	glEnableVertexAttribArray(location.location);
}

void Material::setUniform(const LocationInfo& location, const Matrix& matrix)
{
	glUniformMatrix4fv(location.location, 1, false, reinterpret_cast<const GLfloat*>(&(matrix.m)));
}

void Material::setUniform(const LocationInfo& location, float value)
{
    glUniform1f(location.location, value);
}

void Material::setUniform(const LocationInfo& location, const std::string& textureName)
{
    glActiveTexture(GL_TEXTURE0);
    glUniform1i(location.location, 0);
    glBindTexture(GL_TEXTURE_2D, Game::getInstance().getResourceManager().getBitmapId(textureName));
}

void Material::setUniform(const LocationInfo& location, const Vector& vector)
{
    switch(location.size)
    {
        case 3:
            glUniform3f(location.location, vector.x, vector.y, vector.z);
            break;
        case 4:
            glUniform4f(location.location, vector.x, vector.y, vector.z, 1);
            break;
        default:
            Log("Wrong size in location %d - %d", location.location, static_cast<int>(location.size));
            assert(0);
    }
}

void Material::disableAttribute(MaterialVariables id)
{
	assert(id == MV_POSITION || id == MV_NORMAL || id == MV_UV);
	if(m_locations[id].location == GL_INVALID_LOCATION) return;
	glDisableVertexAttribArray(m_locations[id].location);
}

bool Material::addVariable(const std::string& var, size_t size)
{
	GLint location = m_program->getLocation(var);
	if(location == GL_INVALID_LOCATION) 
    {
        Log("Could not map '%s' in material '%s' - .mat file issue or shader optimizer issue", var.c_str(), m_name.c_str());
        return false;
    }
    Log("Location %d is %s", location, var.c_str());
	m_variables[var].location = location;
    m_variables[var].size = size;
	return true;
}

bool Material::addVariable(const std::string& var, MaterialVariables id, size_t size)
{
	assert(id >= MV_POSITION && id < MV_ENUMERATION_SIZE);
	GLint location = m_program->getLocation(var);
	if(location == GL_INVALID_LOCATION) return false;
    Log("Location %d is %s", location, var.c_str());
	m_locations[id].location = location;
    m_locations[id].size = size;
	return true;
}

void Material::notInMap(const std::string& var)
{
    if(std::find(s_warningVariables.begin(), s_warningVariables.end(), var) != s_warningVariables.end())
        return;
    Log("WARNING: Material(%s)::setValue(%s) not in available names list (not put into material file?)", m_name.c_str(), var.c_str());
    s_warningVariables.push_back(var);
}

void Material::invalidLocation(const std::string& var)
{
    if(std::find(s_warningVariables.begin(), s_warningVariables.end(), var) != s_warningVariables.end())
        return;
    Log("WARNING: Material(%s)::setValue(%s) - underlaying location == -1 - is the mapping correct?", m_name.c_str(), var.c_str());
    s_warningVariables.push_back(var);
}

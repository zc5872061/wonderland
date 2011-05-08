/*
 * MaterialsManager.cpp
 *
 *  Created on: 2011-02-20
 *      Author: Artur
 */

#include "Engine/MaterialsManager.h"

#include <algorithm>
#include <memory>
#include <cstdlib>
#include <string>

#include "Game.h"
#include "GameFile.h"
#include "pi.h"
#include "StringHelper.h"
#include "shared_ptr.h"

const std::string MaterialsManager::MATERIAL_EXTENSION(".mat");
const std::string MaterialsManager::DEFAULT_MATERIAL("default");

const std::string MaterialsManager::SECTION_SHADERS("shaders");
const std::string MaterialsManager::SECTION_ENGINE("engine");
const std::string MaterialsManager::SECTION_CONFIG("config");
const std::string MaterialsManager::SECTION_INPUT("input");

const std::string MaterialsManager::ENG_LIGHT_DIRECTION("lightdirection");
const std::string MaterialsManager::ENG_CAMERA_POSITION("cameraposition");
const std::string MaterialsManager::ENG_MODELVIEWPROJECTION("modelviewprojection");
const std::string MaterialsManager::ENG_MODEL("model");

const std::string MaterialsManager::INPUT_POSITION("position");
const std::string MaterialsManager::INPUT_NORMAL("normal");
const std::string MaterialsManager::INPUT_UV("uv");

MaterialsManager::MaterialsManager() :
		m_currentMaterial(null)
{
}

MaterialsManager::~MaterialsManager()
{
	for(MaterialsContainer::iterator it = m_materials.begin(); it != m_materials.end(); ++it)
	{
		delete it->second;
	}
}

void MaterialsManager::initialize()
{
#ifndef SHP // For some strange reason this crashes on bada. TODO: fix it
	preloadMaterials();
#endif
}

void MaterialsManager::preloadMaterials()
{
	// Preloading materials should be considered as a fix to overcome some problems.
	// No materials should be placed here without an explicit reason.

	// Line is created in a separate thread so to overcome problems on iOS with glGetAttributeLocation
	// called during opengl's 'begin()-end()' (not actual begin-end, but nevertheless, problems did appear...)
	loadMaterial("line");
}

Material* MaterialsManager::getMaterial(const std::string& name)
{
	assert(name != "");
	if(m_materials.find(name) == m_materials.end())
	{
		loadMaterial(name);
	}
	return m_materials[name];
}

void MaterialsManager::loadMaterial(const std::string& name)
{
    Log("[MaterialsManager] loadMaterial(%s)", name.c_str());
	std::string fullName = Constants::getRootPath() + Constants::getMaterialsDir() + name + MATERIAL_EXTENSION;
	shared_ptr<GameFile> file = GameFile::openFile(fullName, "r");
    m_currentMaterialName = name;
	m_currentMaterial = null;
	m_currentSection = "";
	m_vertexName = "";
	m_fragmentName = "";
	m_currentVar = "";
    m_currentSize = "";
	while(!(file->eof()))
	{
		std::string readLine = file->readLine();
		if(readLine.size() == 0) continue;
		if(readLine.find_first_of(" ") == 0 && readLine.find_first_not_of(" ") == std::string::npos)
		{
			continue; // only whitespaces in string
		}
		if(readLine.find("[") == 0 && readLine.find("]") == readLine.size() - 1)
		{
			std::string section = readLine.substr(1, readLine.size() - 2);
			setSection(section);
			continue;
		}
		if(m_currentSection == "")
		{
			Log("Line \"%s\" in unknown section.", readLine.c_str());
			assert(0);
		}
		parseLine(readLine);
	}

	assert(m_currentMaterial != null);
	if(!m_currentMaterial->isVariableValid(Material::MV_POSITION))
	{
		Log("No position variable specified for material %s", name.c_str());
		assert(0);
	}

    m_currentMaterialName = "";
	m_materials[name] = m_currentMaterial;
	m_currentMaterial = null;
	m_currentSection = "";
	m_vertexName = "";
	m_fragmentName = "";
	m_currentVar = "";
    m_currentSize = "";
}

void MaterialsManager::setSection(const std::string& section)
{
	// not a very intelligent way to set section, but this
	// method's purpose is to throw an assert when an unknown
	// section is encountered
	if(section == SECTION_SHADERS || section == SECTION_ENGINE ||
			section == SECTION_INPUT || section == SECTION_CONFIG)
	{
		m_currentSection = section;
	}
	else
	{
		Log("Unknown section named: %s", section.c_str());
		assert(0);
	}
}

void MaterialsManager::parseLine(const std::string& line)
{
	std::string varName = line.substr(0, line.find("="));
	m_currentVar = varName;

	if(m_currentSection == SECTION_SHADERS)
	{
		// Note that as of now the shaders section needs to be first in the material file
		std::string path = line.substr(line.find("=") + 1);
		if(varName == "vertex") m_vertexName = path;
		if(varName == "fragment") m_fragmentName = path;
		if(m_vertexName.size() && m_fragmentName.size())
		{
			ShaderManager& sm = Game::getInstance().getRenderer().getShaderManager();
			m_currentMaterial = new Material(sm.getProgram(m_vertexName, m_fragmentName), m_currentMaterialName);
		}
		return;
	}

	std::string rest = line.substr(line.find("=") + 1);
    
	int tokensCount = std::count(rest.begin(), rest.end(), ';');
	assert(tokensCount > 0);

	std::vector<std::string> tokens;
	StringHelper::tokenize(rest, tokens, ";");
    checkSize(tokens);
    if(!executeMapping(tokens))
    {
        assert(m_currentSection == SECTION_CONFIG);
        assert(m_currentSize != "");
        m_currentMaterial->addVariable(m_currentVar, atoi(m_currentSize.c_str()));
    }
}

void MaterialsManager::checkSize(const std::vector<std::string>& tokens)
{
    m_currentSize = "";
    for(std::vector<std::string>::const_iterator it = tokens.begin(); it != tokens.end(); ++it)
    {
        std::string left = (*it).substr(0, (*it).find(":"));
        std::string right = (*it).substr((*it).find(":") + 1);
        if(left == "size")
        {
            m_currentSize = right;
        }
    }
}

bool MaterialsManager::executeMapping(const std::vector<std::string>& tokens)
{
    for(std::vector<std::string>::const_iterator it = tokens.begin(); it != tokens.end(); ++it)
    {
        std::string left = (*it).substr(0, (*it).find(":"));
        std::string right = (*it).substr((*it).find(":") + 1);
        if(left == "map")
        {
            right = StringHelper::strip(right, "'");
            if(m_currentSection == SECTION_ENGINE)
            {
                if(right == ENG_CAMERA_POSITION)
                    m_currentMaterial->addVariable(m_currentVar, Material::MV_CAMERA_POS, atoi(m_currentSize.c_str()));
                else if(right == ENG_LIGHT_DIRECTION)
                    m_currentMaterial->addVariable(m_currentVar, Material::MV_LIGHT_DIRECTION, atoi(m_currentSize.c_str()));
                else if(right == ENG_MODEL)
                    m_currentMaterial->addVariable(m_currentVar, Material::MV_MODEL, atoi(m_currentSize.c_str()));
                else if(right == ENG_MODELVIEWPROJECTION)
                    m_currentMaterial->addVariable(m_currentVar, Material::MV_MODEL_VIEW_PROJECTION, atoi(m_currentSize.c_str()));
                else
                {
                    Log("Not parsed token: %s", (*it).c_str());
                    assert(0);
                }
            }
            else if(m_currentSection == SECTION_INPUT)
            {
                if(right == INPUT_POSITION)
                    m_currentMaterial->addVariable(m_currentVar, Material::MV_POSITION, atoi(m_currentSize.c_str()));
                else if(right == INPUT_NORMAL)
                    m_currentMaterial->addVariable(m_currentVar, Material::MV_NORMAL, atoi(m_currentSize.c_str()));
                else if(right == INPUT_UV)
                    m_currentMaterial->addVariable(m_currentVar, Material::MV_UV, atoi(m_currentSize.c_str()));
                else
                {
                    Log("Not parsed token: %s", (*it).c_str());
                    assert(0);
                }
            }
            else
            {
                Log("Unknown current section: <%s>", m_currentSection.c_str());
                assert(0);
            }
            return true;
        }
    }
    return false; 
}

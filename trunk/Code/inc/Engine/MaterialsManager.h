/*
 * MaterialsManager.h
 *
 *  Created on: 2011-03-10
 *      Author: Artur
 */

#ifndef MATERIALSMANAGER_H_
#define MATERIALSMANAGER_H_

#include "Material.h"

class MaterialsManager
{
public:
	friend class Game; // to give Game access to MaterialsManager's contructor

	// must be called once after creation
	void initialize();

	Material* getMaterial(const std::string& materialName);

private:
	static const std::string MATERIAL_EXTENSION;
	static const std::string DEFAULT_MATERIAL;

	static const std::string SECTION_SHADERS;
	static const std::string SECTION_ENGINE;
	static const std::string SECTION_CONFIG;
	static const std::string SECTION_INPUT;

	static const std::string ENG_LIGHT_DIRECTION;
	static const std::string ENG_CAMERA_POSITION;
	static const std::string ENG_MODELVIEWPROJECTION;
	static const std::string ENG_MODEL;

	static const std::string INPUT_POSITION;
	static const std::string INPUT_NORMAL;
	static const std::string INPUT_UV;

	typedef std::map<std::string, Material*> MaterialsContainer;
	MaterialsContainer m_materials;

	std::string m_currentSection;
	std::string m_vertexName;
	std::string m_fragmentName;
	std::string m_currentVar;
    std::string m_currentMaterialName;
    std::string m_currentSize;
	Material* m_currentMaterial;

private:
	void preloadMaterials();
	void loadMaterial(const std::string& name);
	void setSection(const std::string& section);
	void parseLine(const std::string& line);
    
    // Checks tokens and looks for the one responsible for setting the size
    void checkSize(const std::vector<std::string>& tokens);
    // Checks tokens and if finds a map:sdadas it will create the mapping for it in material
    // Returns true if mapping found and false if not found
    bool executeMapping(const std::vector<std::string>& tokens);

	MaterialsManager();
	~MaterialsManager();
	MaterialsManager(const MaterialsManager&);
	MaterialsManager& operator=(const MaterialsManager&);
};

#endif /* MATERIALSMANAGER_H_ */

/*
 * Material.h
 *
 *  Created on: 2011-02-13
 *      Author: Artur
 */

#ifndef MATERIAL_H_
#define MATERIAL_H_

#include <string>
#include <vector>

#include "Program.h"
#include "MathHelper.h"

// Class which is intended to abstract a material i.e. a pair of shaders + their possible variables.
// It is intended to be rather heavy weight and only single instance of each shaders' combination should exist.
// MaterialInstance is the light-weight class which holds specific config variables for materials.
class Material
{
public:
	friend class MaterialsManager;

	static const int GL_INVALID_LOCATION = -1;

	// Note: when changing this enumeration be sure to also check the change value family!
	enum MaterialVariables
	{
		MV_POSITION, 	// attribute - holds position information, must be filled to have objects properly rendered, requires stride 3 data
		MV_NORMAL, 		// attribute - holds normal informations, requires stride 3 data
		MV_UV, 			// attribute - holds uv information, requires stride 2 data
		MV_MODEL_VIEW_PROJECTION, 	// uniform which holds model-view-projection matrix
		MV_MODEL,		// uniform which holds model matrix
		MV_CAMERA_POS, 	// uniform with the camera position
		MV_LIGHT_DIRECTION, 		// uniform with the light direction for directional lighting

		MV_ENUMERATION_SIZE
	};

	Program* getProgram() { return m_program; }
	// Returns if the specified variable exists in the underlying program
	bool isVariableValid(MaterialVariables id) { return m_locations[id].location != GL_INVALID_LOCATION; }
	// Disables the attribute arrey specified by the id can be either position, normal or uv
	void disableAttribute(MaterialVariables id);

	// This method is a bit funny, because it checks if the argument is in range
	// and then calls another proper method. This is for convenience.
	template <typename DataT>
	bool setValue(MaterialVariables id, const DataT& data);
	// This one should be used for material-specific variables, i.e. those that are marked in
	// the <config> section
	template <typename DataT>
	bool setValue(const std::string& var, const DataT& data);
    
    void setName(const std::string& name) { m_name = name; }
    const std::string& getName() const { return m_name; }

private:
    // This POD structure holds information about the size of
    // the variable that is associated with this location. This is required
    // to make setting up vector variables in program working correctly
    struct LocationInfo
    {
        GLint location;
        size_t size;
    };
    
	Program* m_program;
	LocationInfo m_locations[MV_ENUMERATION_SIZE];
    std::string m_name;
    
    // Used to print variables that are set by material by material instances 
    // but does not exist in the effect file (or at least weren't mapped to GLint)
    static std::vector<std::string> s_warningVariables;

	// Non typical variables which are specific for one material need
	// to be expressed by strings to achieve some flexibility
	typedef std::map<std::string, LocationInfo> VariablesMap;
	VariablesMap m_variables;

private:
	void setAttribute(const LocationInfo& location, const float* data, int stride);
	void setUniform(const LocationInfo& location, const Matrix& matrix);
	void setUniform(const LocationInfo& location, const Vector& vector);
    void setUniform(const LocationInfo& location, const std::string& textureName);
    void setUniform(const LocationInfo& location, float value);

	template<typename WrongCallT>
	void setUniform(const LocationInfo&, const WrongCallT&) {assert(0);} //not implemented, here only for template/compilation error
	template<typename WrongCallT>
	void setAttribute(const LocationInfo&, const WrongCallT&, int) {assert(0);}

	// registers a variable which should exist the program file
	// It queries the underlying Program for location and later this variable
	// can be referenced and used to set data
	// Intended for use by the MaterialsManager
	bool addVariable(const std::string& var, size_t size);
	// Registers a location from the underlying program which should be
	// mapped to one of the predefined engine variables (those found
	// in the enumeration above).
	// Intended for use by the engine
	bool addVariable(const std::string& var, MaterialVariables id, size_t size);
    
    void notInMap(const std::string& var);
    void invalidLocation(const std::string& var);

	Material(Program* program, const std::string& name);
	~Material() {}
	Material(const Material&);
	Material& operator=(const Material&);
};

template <typename DataT>
bool Material::setValue(MaterialVariables id, const DataT& data)
{
	LocationInfo location = m_locations[id];
	if(location.location == GL_INVALID_LOCATION) return false;
	switch(id)
	{
		case MV_POSITION:
		case MV_NORMAL:
			setAttribute(location, data, 3);
			break;
		case MV_UV:
			setAttribute(location, data, 2);
			break;
		case MV_MODEL_VIEW_PROJECTION:
		case MV_MODEL:
		case MV_CAMERA_POS:
		case MV_LIGHT_DIRECTION:
			setUniform(location, data);
			break;
		default:
			Log("Critical error - unknown id used in Material::setValue - %d", id);
			assert(0);
	}
	return true;
}

template <typename DataT>
bool Material::setValue(const std::string& var, const DataT& data)
{
	VariablesMap::iterator it = m_variables.find(var);
	if(it == m_variables.end()) 
    {
        notInMap(var);
        return false;
    }
	if(it->second.location == GL_INVALID_LOCATION)
    {
        invalidLocation(var);
        return false;
    }
    setUniform(it->second, data);
    return true;
}

#endif /* MATERIAL_H_ */

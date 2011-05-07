/*
 * MaterialInstance.cpp(mm)
 *
 *  Created on: 2011-03-30
 *      Author: Artur
 */
#ifndef _MATERIAL_INSTANCE_H_
#define _MATERIAL_INSTANCE_H_

#include "Material.h"
#include "MathHelper.h"

#include <string>
#include <map>

class MaterialInstance
{
public:
    MaterialInstance() {}
    ~MaterialInstance() {}
    
    void setMaterialName(const std::string& materialName) { m_materialName = materialName; }
    const std::string& getMaterialName() const { return m_materialName; }
    
    void setValue(const std::string& name, const Vector& value) { setValueT(name, value, m_vectors); }
    void setValue(const std::string& name, const Matrix& value) { setValueT(name, value, m_matrices); }
    void setValue(const std::string& name, float value)         { setValueT(name, value, m_floats); }
    void setValue(const std::string& name, const std::string& value) { setValueT(name, value, m_bitmaps); }
    
    // Most probably will be inlined anyway, but if I later want to change something this way will be much easier
    template <class ValueType>
    void setValueT(const std::string& name, const ValueType& value, std::map<std::string, ValueType>& container)
    {
        container[name] = value;
    }
    
    // Fills material with its data. This method should be used only with the 'parent' material
    // It is here for potential optimization
    void fillMaterial(Material* material);
    // Fills its parent material asking MaterialManager to get it
    void fillMaterial(); 
    
private:
    typedef std::map<std::string, Vector> VectorMap;
    typedef std::map<std::string, Matrix> MatrixMap;
    typedef std::map<std::string, float> FloatMap;
    typedef std::map<std::string, std::string> BitmapsMap;
    
    VectorMap m_vectors;
    MatrixMap m_matrices;
    FloatMap m_floats;
    BitmapsMap m_bitmaps;
    
    std::string m_materialName;
};

#endif // _MATERIAL_INSTANCE_H_
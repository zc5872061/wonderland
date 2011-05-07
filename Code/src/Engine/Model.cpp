/*
 * Model.mm(cpp)
 *
 *  Created on: 2011-04-14
 *      Author: Artur
 */
#include "Engine/Model.h"
#include "pi.h"

#include <algorithm>

Model::Model()
{
    
}

Model::~Model()
{
    for(MeshesIterator it = m_meshes.begin(); it != m_meshes.end(); ++it)
    {
        delete *it;
    }
}

Model::MeshesContainer* Model::getElements()
{
    return &m_meshes;
}

int Model::getElementsCount() const
{
    return m_meshes.size();
}

Model::MeshesIterator Model::begin()
{
    return m_meshes.begin();
}

Model::MeshesIterator Model::end()
{
    return m_meshes.end();
}

Model::ModelElement::ModelElement(const std::string& name, const std::string& meshName) :
    m_usedMethod(&ModelElement::getMeshNameImpl),
    m_linkParent(null),
    m_matInstance(new MaterialInstance()),
    m_name(name),
    m_meshName(meshName)
{
}

Model::ModelElement::ModelElement(const std::string& name, ModelElement* linkParent) :
    m_usedMethod(&ModelElement::getMeshNameLinked),
    m_linkParent(linkParent),
    m_matInstance(new MaterialInstance()),
    m_name(name)
{
}

Model::ModelElement::~ModelElement()
{
    delete m_matInstance;
}

MaterialInstance* Model::ModelElement::getMaterialInstance()
{
    return m_matInstance;
}

const std::string& Model::ModelElement::getName() const
{
    return m_name;
}

const std::string& Model::ModelElement::getMeshName() const
{
    return (this->*m_usedMethod)();
}

const std::string& Model::ModelElement::getMeshNameImpl() const
{
    return m_meshName;
}

const std::string& Model::ModelElement::getMeshNameLinked() const
{
    return m_linkParent->getMeshName();
}

void Model::ModelElement::setMeshName(const std::string& meshName)
{
    if(m_usedMethod == &ModelElement::getMeshNameLinked)
    {
        m_usedMethod = &ModelElement::getMeshNameImpl;
    }
    m_meshName = meshName;
}

bool Model::ModelElement::isLinked() const
{
    return m_usedMethod == &ModelElement::getMeshNameLinked;
}

Model::ModelElement* Model::getElement(const std::string& name)
{
    for(MeshesIterator it = m_meshes.begin(); it != m_meshes.end(); ++it)
    {
        if((*it)->getName() == name)
        {
            return *it;
        }
    }
    assert(!"No mesh of given name");
    return null;
}

Model::ModelElement* Model::getElement(int index)
{
    assert(index >= 0 && index < m_meshes.size());
    return m_meshes[index];
}

void Model::addElement(const std::string& name, const std::string& meshName)
{
    m_meshes.push_back(new ModelElement(name, meshName));
}

void Model::addElementLink(const std::string& name, const std::string& targetElement)
{
    assert(hasElement(targetElement));
    m_meshes.push_back(new ModelElement(name, getElement(targetElement)));
}

void Model::setMesh(const std::string& newMeshName, int index)
{
    getElement(index)->m_name = newMeshName;
}

void Model::setMesh(const std::string& newMeshName, const std::string& elementName)
{
    getElement(elementName)->setMeshName(elementName);
}

bool Model::hasElement(const std::string& name)
{
    for(MeshesIterator mesh = m_meshes.begin(); mesh != m_meshes.end(); ++mesh)
    {
        if((*mesh)->getName() == name)
        {
            return true;
        }
    }
    return false;
}


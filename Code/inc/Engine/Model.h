/*
 * Model.h
 *
 *  Created on: 2011-02-13
 *      Author: Artur
 */

#ifndef MODEL_H_
#define MODEL_H_

#include <string>
#include <vector>

#include "shared_ptr.h"
#include "MaterialInstance.h"

class Model
{
public:
    friend class Actor;
    
    class ModelElement
    {
    public:
        friend class Model;
        
        // name - the id of this mesh element of the Model
        // basicMeshName - the name of the geometry
        ModelElement(const std::string& name, const std::string& meshName);
        // And the constructor that will create a linked element, i.e.
        // an element that will have its own material but will use the basic mesh
        // of a different ModelElement.
        ModelElement(const std::string& name, ModelElement* linkParent);
        ~ModelElement();
        
        //The name of this specific ModelElement
        const std::string& getName() const;        
        
        // Gets the name of the geometry that should be used to render this 
        // part of the model.
        // If the Element is linked to another element it will return the name 
        // of that mesh
        const std::string& getMeshName() const;
        // And sets the name of geometry.
        // Setting mesh name to a linked element will result in breaking the link
        void setMeshName(const std::string& meshName);
        
        MaterialInstance* getMaterialInstance();
        
        // Returns true if this ModelElement links to a geometry that is held
        // by another ModelElement instance
        bool isLinked() const;
        
    private:
        void setLink(ModelElement* element);
        const std::string& getMeshNameImpl() const;
        const std::string& getMeshNameLinked() const;
        
    private:
        // Depending on if is the ModelElement linked it will
        // return the mesh name using either a typical getMeshName
        // or a special one that takes mesh name from another ModelElement.
        // It is done this way to remove conditional in a very frequent 
        // part of code that asks for mesh name. And I think sometimes things like 
        // that make code funnier to read;)
        typedef const std::string& (ModelElement::*NameGetterPtr)() const;
        NameGetterPtr m_usedMethod;
        ModelElement* m_linkParent;
        
        MaterialInstance* m_matInstance;
        std::string m_name;
        std::string m_meshName;
    };
    
    typedef std::vector<ModelElement*> MeshesContainer;
    typedef MeshesContainer::iterator MeshesIterator;
    
    MeshesContainer* getElements();
    int getElementsCount() const;
    // Will return the element that has this name.
    ModelElement* getElement(const std::string& name);
    ModelElement* getElement(int index = 0); // to make it easier for actors that have only one mesh
    bool hasElement(const std::string& name);
    void addElement(const std::string& name, const std::string& meshName);
    // Adds a ModelElement with name 'name' that has the same mesh as the 'targetElement'
    // Useful when a model can consist of elements that have identical geometry, like
    // a moving car maybe.
    void addElementLink(const std::string& name, const std::string& targetElement);
    // overwrites the mesh name from the existing mesh
    // at index with the new meshName. The mesh must already
    // exist;
    void setMesh(const std::string& newMeshName, int atIndex);
    // Does the same as above but takes the element name as a parameter.
    void setMesh(const std::string& newMeshName, const std::string& elementName);
    // To make iterating easier
    MeshesIterator begin();
    MeshesIterator end();
    

private:
    MeshesContainer m_meshes;
    
private:
    Model();
    ~Model();
};

#endif /* MODEL_H_ */

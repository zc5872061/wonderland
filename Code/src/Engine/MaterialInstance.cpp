/*
 * MaterialInstance.cpp(mm)
 *
 *  Created on: 2011-03-30
 *      Author: Artur
 */

#include "Engine/MaterialInstance.h"
#include "Game.h"

template <class IteratorT>
void _fillData(IteratorT start, IteratorT end, Material* material)
{
    while(start != end)
    {
        material->setValue(start->first, start->second);
        ++start;
    }
}

void MaterialInstance::fillMaterial(Material* material)
{
    assert(material && "Null material given, this is unacceptable");

    // As of now iterate over all containers and fill in everything
    // TODO: invent a better way!
    _fillData(m_vectors.begin(), m_vectors.end(), material);
    _fillData(m_matrices.begin(), m_matrices.end(), material);
    _fillData(m_floats.begin(), m_floats.end(), material);
    _fillData(m_bitmaps.begin(), m_bitmaps.end(), material);
}

void MaterialInstance::fillMaterial()
{
    if(m_materialName == "")
    {
        return;
    }
    fillMaterial(Game::getInstance().getMaterialsManager().getMaterial(m_materialName));
}

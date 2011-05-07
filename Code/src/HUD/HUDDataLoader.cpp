/*
 * HUDDataLoader.mm(cpp)
 *
 *  Created on: 2011-03-26
 *      Author: artur.m
 */

#include "HUD/HUDDataLoader.h"

#include "pi.h"
#include "GameFile.h"
#include "shared_ptr.h"
#include "StringHelper.h"

#include <memory>
#include <vector>
#include <cstdlib>

const std::string HUDDataLoader::DATA_FILE_EXTENSION(".dti");

void HUDDataLoader::loadUIFile(const std::string& fileName)
{
    shared_ptr<GameFile> file = GameFile::openFile(Constants::getRootPath() + Constants::getUiDataPath() + fileName + DATA_FILE_EXTENSION, "r");
    parseFile(file.get());
}

void HUDDataLoader::parseFile(GameFile* file)
{
    while(!file->eof())
    {
        std::string readLine = file->readLine();
        if(StringHelper::strip(readLine) == "") continue;
        if(readLine[0] == '@')
        {
            addElement(readLine.substr(1), file->readLine());
            continue;
        }
        Log("Shouldn't get here with line %s", readLine.c_str());
        assert(!"Shouldn't get here!");
    }
}

void HUDDataLoader::addElement(const std::string& elemName, const std::string& line)
{
    assert(m_bounds.find(elemName) == m_bounds.end());
    
    std::vector<std::string> tokens;
    StringHelper::tokenize(line, tokens);
    assert(tokens.size() == 4 && "There must be 4 elements to create a rectangle");
    Rectangle bounds(atoi(tokens[0].c_str()), atoi(tokens[1].c_str()), atoi(tokens[2].c_str()), atoi(tokens[3].c_str()));
    
    m_bounds[elemName] = bounds;
}

const Rectangle& HUDDataLoader::getBounds(const std::string& name) const
{
    BoundsMap::const_iterator it = m_bounds.find(name);
    assert(it != m_bounds.end() && "Did you load UI data file?");
    return it->second;
}

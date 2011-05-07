/*
 * HUDDataLoader.h
 *
 *  Created on: 2011-03-26
 *      Author: artur.m
 */

#ifndef _HUD_DATA_LOADER_H_
#define _HUD_DATA_LOADER_H_

#include <map>

#include "MathHelper.h"

class GameFile;

class HUDDataLoader
{
public:
    HUDDataLoader() {}
    ~HUDDataLoader() {}
    
    // Loads UI data from a given file, but also
    // removes all the old data (note however that
    // this won't affect already existing controls)
    // filename should be given without extension
    void loadUIFile(const std::string& fileName);
    // Returns named rectangle that was defined in the UI file
    const Rectangle& getBounds(const std::string& name) const;
    
private:
    void parseFile(GameFile* gameFile);
    // Adds new element to the map
    // elemName is the name of the element, and
    // data is a line with its data, i.e. "123 324 123 12"
    void addElement(const std::string& elemName, const std::string& data);
    
private:
    static const std::string DATA_FILE_EXTENSION;
    typedef std::map<std::string, Rectangle> BoundsMap;
    BoundsMap m_bounds;
};

#endif // _HUD_DATA_LOADER_H_
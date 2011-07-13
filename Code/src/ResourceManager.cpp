/*
 * ResourceManager.cpp
 *
 *  Created on: 2010-04-02
 *      Author: Artur
 */

#include "ResourceManager.h"

#include "pi.h"
#include "Fonts/FontEngine.h"
#include "Game.h"

#include <memory>

ResourceManager::ResourceManager()
{

}

void ResourceManager::initialize()
{

}

ResourceManager::~ResourceManager()
{

}

shared_ptr<GameBitmap> ResourceManager::getBitmap(const std::string& fileName)
{
	return loadBitmap(fileName).bitmap;
}

GLuint ResourceManager::getBitmapId(const std::string& fileName)
{
	return loadBitmap(fileName).textureName;
}

BitmapInfo ResourceManager::loadBitmap(const std::string& fileName)
{
	std::string fullName = Constants::getRootPath() + Constants::getBitmapsDir() + fileName;
	if(m_bitmaps.find(fileName) == m_bitmaps.end())
	{
        shared_ptr<GameBitmap> bitmap;
        bitmap = GameBitmap::createBitmap(fullName);
        m_bitmaps[fileName] = registerForOpenGL(bitmap, fileName);
	}

	return m_bitmaps[fileName];
}

BitmapInfo ResourceManager::registerForOpenGL(shared_ptr<GameBitmap> bitmap, const std::string &name)
{
    BitmapInfo bi;
    bi.bitmap = bitmap;
    glGenTextures(1, &(bi.textureName));
    glBindTexture(GL_TEXTURE_2D, bi.textureName);
    
    int width = bi.bitmap->getWidth();
    int height = bi.bitmap->getHeight();
    unsigned char* data = reinterpret_cast<unsigned char*>(bi.bitmap->getBitmap());
    
    glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);

    int error = glGetError();
    if(error != GL_NO_ERROR) {
    	Log("GL error 0x%x with texture %s.", error, name.c_str());
    }
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    
    return bi;
}

void ResourceManager::registerBitmap(shared_ptr<GameBitmap> bitmap, const std::string& name)
{
    if(m_bitmaps.find(name) != m_bitmaps.end())
    {
        deleteBitmap(name);
    }
    m_bitmaps[name] = registerForOpenGL(bitmap, name);
}

void ResourceManager::deleteBitmap(const std::string& name)
{
    BitmapsIter it = m_bitmaps.find(name);
    assert(it != m_bitmaps.end());
    glDeleteTextures(1, &(it->second.textureName));
    m_bitmaps.erase(it);
}

void ResourceManager::unregisterBitmap(const std::string& name)
{
    // In general (that is: in the future) this will have to check if the bitmap can be unregistered,
    // i.e. it was registered by user and therefore can be deleted. Need to think about it a little.
    deleteBitmap(name);
}

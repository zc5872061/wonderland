/*
 * ResourceManager.h
 *
 *  Created on: 2010-04-02
 *      Author: Artur
 */

#ifndef RESOURCEMANAGER_H_
#define RESOURCEMANAGER_H_

#include "pi.h"

#include <string>
#include <map>

#include "Engine/Material.h"
#include "GameBitmap.h"


struct BitmapInfo
{
	GLuint textureName;
	shared_ptr<GameBitmap> bitmap;
};

class ResourceManager
{
public:
	ResourceManager();
	virtual ~ResourceManager();

	void initialize();

	GLuint getBitmapId(const std::string& fileName);
	shared_ptr<GameBitmap> getBitmap(const std::string& fileName);
    void registerBitmap(shared_ptr<GameBitmap> bitmap, const std::string& name);
    void unregisterBitmap(const std::string& name);

private:
	BitmapInfo loadBitmap(const std::string& fileName);
    BitmapInfo registerForOpenGL(shared_ptr<GameBitmap> bitmap, const std::string& name);
    void deleteBitmap(const std::string& name);

	typedef std::map<std::string, BitmapInfo>::iterator BitmapsIter;
	std::map<std::string, BitmapInfo> m_bitmaps;

	typedef std::map<std::string, Material*> MaterialsContainer;
	typedef MaterialsContainer::iterator MaterialsIter;
	MaterialsContainer m_materials;
};

#endif /* RESOURCEMANAGER_H_ */

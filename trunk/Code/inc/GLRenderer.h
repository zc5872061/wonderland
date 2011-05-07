/*
 * GLRenderer.h
 *
 *  Created on: 2010-12-02
 *      Author: artur.m
 */

#ifndef GLRENDERER_H_
#define GLRENDERER_H_

#include <map>
#include <vector>
#include <string>
#include <utility>
#include <deque>

#include "pi.h"
#include "Camera.h"
#include "Shader.h"
#include "ShaderManager.h"
#include "HUD/HUD.h"
#include "Engine/BasicMesh.h"
#include "shared_ptr.h"

struct ProgramInfo
{
	std::string vertexShaderName;
	std::string fragmentShaderName;
};

class GLRenderer
{
public:
	GLRenderer();
	virtual ~GLRenderer();

#ifdef IOS
	bool initialize();
#else
    bool initialize(EGLNativeWindowType window);
#endif
	ShaderManager& getShaderManager();

	Camera& getCamera();

	void renderFrame();

	void draw(Actor* object);
	void drop(Actor* object);
private:
	void setProgram(Material* material);

#ifndef IOS
	bool InitEGL(EGLNativeWindowType window);
#endif
	bool InitGL();
	void DestroyGL();
	void Cleanup();
	void drawMesh(BasicMesh* mesh, bool updateMesh, Material* material);
	void updateTransformations(const Actor* actor, Material* material);
    void renderActor(Actor* actor);
    void drawObjects(); // draws all non-orthogonal objects
	void drawBackground(); // draws orthogonal background
    void drawForeground(); // and the foreground

private:
#ifndef IOS
	EGLDisplay  m_eglDisplay;
	EGLSurface  m_eglSurface;
	EGLConfig   m_eglConfig;
	EGLContext  m_eglContext;
#endif

	ShaderManager m_shaderManager;
    shared_ptr<Camera> m_camera;

    // to make rendering faster renderer keeps plain pointer
    typedef std::deque<Actor*> ActorsContainer;
	typedef ActorsContainer::iterator GameObjectsIter;
	ActorsContainer m_gameObjects;
    ActorsContainer m_orthoObjects;
    
    bool m_lock;
};

#endif /* GLRENDERER_H_ */

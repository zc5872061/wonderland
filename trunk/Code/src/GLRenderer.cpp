/*
 * GLRenderer.cpp
 *
 *  Created on: 2010-12-02
 *      Author: artur.m
 */

#include "GLRenderer.h"

#include <memory>
#include <algorithm>
#include <unistd.h>

#include "pi.h"
#include "GameFile.h"
#include "Game.h"
#include "Engine/Material.h"

// Displays FPS, but as of now will work only for bada
//#define DISPLAY_FPS

//class MeshSorter
//{
//public:
//	bool operator()(Actor* left, Actor* right)
//	{
//		return left->getModel() < right->getModel().getMeshName();
//	}
//};

GLRenderer::GLRenderer()
{

}

GLRenderer::~GLRenderer()
{		
	DestroyGL();
}

#ifdef IOS
bool GLRenderer::initialize()
#else
bool GLRenderer::initialize(EGLNativeWindowType window)
#endif
{
#ifndef IOS
	if(!InitEGL(window))
	{
		Log("[GlesCube] GlesCube can run on systems which supports OpenGL ES(R) 2.0.");
		Log("[GlesCube] When GlesCube does not correctly execute, there are a few reasons.");
		Log("[GlesCube]    1. The current device(real-target or simulator) does not support OpenGL ES(R) 2.0. Check the Release Notes.");
		Log("[GlesCube]    2. The system running on simulator cannot support OpenGL(R) 2.1 or later. Try with other system.");
		Log("[GlesCube]    3. The system running on simulator does not maintain the latest graphics driver. Update the graphics driver.");
		DestroyGL();
		return false;
	}
#endif
	if(!InitGL())
	{
		return false;
	}

	return true;
}

Camera& GLRenderer::getCamera()
{
    if(m_camera.get() == null)
    {
        m_camera = Camera::spawn();
    }
	return *m_camera;
}

#if defined (SHP)
void _displayFPS()
{
    static float     fps = 0.0f;
    static float     updateInterval = 1000.0f;
    static float     timeSinceLastUpdate = 0.0f;
    static float     frameCount = 0;
    static long long currentTick;
    static long long lastTick;
    static bool      isFirst = true;

    if (isFirst)
    {
        getTicks(currentTick);
        lastTick = currentTick;
        isFirst = false;
    }

    frameCount++;
    getTicks(currentTick);

    float elapsed = currentTick - lastTick;

    lastTick = currentTick;
    timeSinceLastUpdate += elapsed;

    if (timeSinceLastUpdate > updateInterval)
    {
        if (timeSinceLastUpdate)
        {
            fps = (frameCount / timeSinceLastUpdate) * 1000.f;
            Log("FPS: %f frames/sec\n", fps);
            
            frameCount = 0;
            timeSinceLastUpdate -= updateInterval;
        }
    }
}
#endif

void GLRenderer::renderFrame()
{
#ifndef IOS
	if (GL_FALSE == eglMakeCurrent(m_eglDisplay, m_eglSurface, m_eglSurface, m_eglContext) ||
		EGL_SUCCESS != eglGetError())
	{
		return;
	}
#endif

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
    drawBackground();
    glDisable(GL_BLEND);

    glEnable(GL_DEPTH_TEST);
	glClear(GL_DEPTH_BUFFER_BIT);
	drawObjects();
    glDisable(GL_DEPTH_TEST);
    
    glEnable(GL_BLEND);
    glClear(GL_DEPTH_BUFFER_BIT);
    drawForeground();

#ifndef IOS
	eglSwapBuffers(m_eglDisplay, m_eglSurface);
#endif

#if defined( DISPLAY_FPS ) && defined( SHP )
    _displayFPS();
#endif
}

void GLRenderer::drawObjects()
{
	for(GameObjectsIter it = m_gameObjects.begin(); it != m_gameObjects.end(); ++it)
	{   
        renderActor(*it);
	}
}

void GLRenderer::drawBackground()
{
    for(GameObjectsIter it = m_orthoObjects.begin(); it != m_orthoObjects.end(); ++it)
    {
        if((*it)->getDrawLayer() == Common::DL_BACKGROUND)
        {
            renderActor(*it);
        }
    }
}

void GLRenderer::drawForeground()
{
    for(GameObjectsIter it = m_orthoObjects.begin(); it != m_orthoObjects.end(); ++it)
    {
        if((*it)->getDrawLayer() == Common::DL_FOREGROUND)
        {
            renderActor(*it);
        }
    }
}

void GLRenderer::renderActor(Actor* actor)
{
    if(actor->isHidden())
    {
        return;
    }
    for(Model::MeshesIterator it = actor->getModel().begin(); it != actor->getModel().end(); ++it)
    {
        std::string meshName = (*it)->getMeshName();
        if(meshName.size() == 0)
        {
            return; // ... this is to the lack of thread safety with finding the line. TODO fixme
        }
        BasicMesh* mesh = Game::getInstance().getMeshManager().getMesh(meshName);
        
        const std::string& materialName = (*it)->getMaterialInstance()->getMaterialName();
        Material* mi = Game::getInstance().getMaterialsManager().getMaterial(materialName);
        
        setProgram(mi);
        (*it)->getMaterialInstance()->fillMaterial();
        updateTransformations(actor, mi);
        drawMesh(mesh, true, mi);
    }
}

void GLRenderer::draw(Actor* object)
{
	assert(std::find(m_gameObjects.begin(), m_gameObjects.end(), object) == m_gameObjects.end());
    assert(std::find(m_orthoObjects.begin(), m_orthoObjects.end(), object) == m_orthoObjects.end());
    
    if(!object->isOrtho())
    {
        m_gameObjects.push_back(object);
    }
    else
    {
        m_orthoObjects.push_back(object);
    }
	//std::sort(m_gameObjects.begin(), m_gameObjects.end(), MeshSorter());
}

void GLRenderer::drop(Actor* object)
{
    GameObjectsIter gIt = std::find(m_gameObjects.begin(), m_gameObjects.end(), object);
    GameObjectsIter oIt = std::find(m_orthoObjects.begin(), m_orthoObjects.end(), object);
	if(gIt == m_gameObjects.end() && oIt == m_orthoObjects.end())
    {
        Log("GLRenderer - removing a non-existent '%s'. Double \"delete\"?", object->getType().c_str());
        return;
    }
    if(gIt != m_gameObjects.end())
    {
        m_gameObjects.erase(gIt);
        return;
    }
    else if(oIt != m_orthoObjects.end())
    {
        m_orthoObjects.erase(oIt);
        return;
    }
    assert(!"Ooops, something is wrong with iterators");
}

#ifndef IOS
bool GLRenderer::InitEGL(EGLNativeWindowType window)
{
	EGLint numConfigs = 1;
	EGLint eglConfigList[] = {
		EGL_RED_SIZE,	5,
		EGL_GREEN_SIZE,	6,
		EGL_BLUE_SIZE,	5,
		EGL_ALPHA_SIZE,	0,
		EGL_DEPTH_SIZE, 8,
		EGL_SURFACE_TYPE, EGL_WINDOW_BIT,
		EGL_RENDERABLE_TYPE, EGL_OPENGL_ES2_BIT,
		EGL_NONE
	};
	EGLint eglContextList[] = {
		EGL_CONTEXT_CLIENT_VERSION, 2,
		EGL_NONE
	};

	eglBindAPI(EGL_OPENGL_ES_API);

	if(m_eglDisplay)
	{
		DestroyGL();
	}

	m_eglDisplay = eglGetDisplay((EGLNativeDisplayType)EGL_DEFAULT_DISPLAY);
	if (EGL_NO_DISPLAY == m_eglDisplay)
	{
		Log("[GlesCube] eglGetDisplay() is failed. [0x%x]\n", eglGetError());
		DestroyGL();
		return false;
	}

	if (EGL_FALSE == eglInitialize(m_eglDisplay, null, null) ||
		EGL_SUCCESS != eglGetError())
	{
		Log("[GlesCube] eglInitialize() has been failed. [0x%x]\n", eglGetError());
		DestroyGL();
		return false;
	}

	if (EGL_FALSE == eglChooseConfig(m_eglDisplay, eglConfigList, &m_eglConfig, 1, &numConfigs) ||
		EGL_SUCCESS != eglGetError())
	{
		Log("[GlesCube] eglChooseConfig() has been failed. [0x%x]\n", eglGetError());
		DestroyGL();
		return false;
	}

	if (!numConfigs)
	{
		Log("[GlesCube] eglChooseConfig() has been failed. because of matching config doesn't exist \n");
		DestroyGL();
		return false;
	}

	m_eglSurface = eglCreateWindowSurface(m_eglDisplay, m_eglConfig, window, null);

	if (EGL_NO_SURFACE == m_eglSurface ||
		EGL_SUCCESS != eglGetError())
	{
		Log("[GlesCube] eglCreateWindowSurface() has been failed. EGL_NO_SURFACE [0x%x]\n", eglGetError());
		DestroyGL();
		return false;
	}

	m_eglContext = eglCreateContext(m_eglDisplay, m_eglConfig, EGL_NO_CONTEXT, eglContextList);
	if (EGL_NO_CONTEXT == m_eglContext ||
		EGL_SUCCESS != eglGetError())
	{
		Log("[GlesCube] eglCreateContext() has been failed. [0x%x]\n", eglGetError());
		DestroyGL();
		return false;
	}

	if (EGL_FALSE == eglMakeCurrent(m_eglDisplay, m_eglSurface, m_eglSurface, m_eglContext) ||
		EGL_SUCCESS != eglGetError())
	{
		Log("[GlesCube] eglMakeCurrent() has been failed. [0x%x]\n", eglGetError());
		DestroyGL();
		return false;
	}

	return true;
}
#endif

bool GLRenderer::InitGL()
{
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glEnable(GL_DEPTH_TEST);

	glClearColor(0, 0, 0, 1);
	glClear(GL_COLOR_BUFFER_BIT);

	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	return true;
}

void GLRenderer::DestroyGL()
{

}

void GLRenderer::setProgram(Material* material)
{
	glUseProgram(material->getProgram()->getId());
}

void GLRenderer::Cleanup()
{
	DestroyGL();
}

void GLRenderer::drawMesh(BasicMesh* mesh, bool updateMesh, Material* material)
{
	if(updateMesh)
	{
		material->setValue(Material::MV_POSITION, mesh->getVertices());

		if(mesh->getNormals() && material->isVariableValid(Material::MV_NORMAL))
		{
			material->setValue(Material::MV_NORMAL, mesh->getNormals());
		}
		else
		{
			material->disableAttribute(Material::MV_NORMAL);
		}

		if(mesh->getUVs() && material->isVariableValid(Material::MV_UV))
		{
			material->setValue(Material::MV_UV, mesh->getUVs());
		}
		else
		{
			material->disableAttribute(Material::MV_UV);
		}
	}

	if(mesh->getIndicesCount() != 0)
	{
		glDrawElements(GL_TRIANGLES, mesh->getIndicesCount(), GL_UNSIGNED_SHORT, mesh->getIndices());
	}
	else
	{
		glDrawArrays(GL_TRIANGLE_STRIP, 0, mesh->getVerticesCount());
	}
}

void GLRenderer::updateTransformations(const Actor* actor, Material* material)
{
    Matrix matModelViewProj;
    Matrix transformation = actor->getTransformation();
    
    if(!actor->isOrtho())
    {
        const Matrix& modelView = m_camera->getModelViewMatrix();
        const Matrix& projection = m_camera->getProjectionMatrix();

        Matrix mModel = MathHelper::Multiply(transformation, modelView);

        matModelViewProj = MathHelper::Multiply( mModel, projection);
    }
    else
    {
        matModelViewProj = m_camera->getOrthoMatrix();
    }

	material->setValue(Material::MV_MODEL_VIEW_PROJECTION, matModelViewProj);
	material->setValue(Material::MV_MODEL, transformation);

	material->setValue(Material::MV_CAMERA_POS, m_camera->getPosition());
	material->setValue(Material::MV_LIGHT_DIRECTION, Vector(1, 1.5, -1).getNormalized());
}

ShaderManager& GLRenderer::getShaderManager()
{
	return m_shaderManager;
}

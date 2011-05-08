#include "Wonderland.h"
#include "MathHelper.h"
#include "Actor.h"
#include "GLRenderer.h"
#include "Game.h"
#include "BallsGameController.h"
#include "BallsHUD.h"

#include <cmath>
#include <algorithm>
#include <functional>

using namespace Osp::Base;
using namespace Osp::Base::Runtime;
using namespace Osp::Graphics;
using namespace Osp::Locales;
using namespace Osp::System;
using namespace Osp::App;
using namespace Osp::System;
using namespace Osp::Ui;
using namespace Osp::Ui::Controls;
using namespace Osp::Graphics::Opengl;

class GlesForm :
	public Osp::Ui::Controls::Form
{
public:
	GlesForm(Wonderland* pApp)
	: __pApp(pApp)
	{
	}
	virtual ~GlesForm(void)
	{
	}

public:
	virtual result OnDraw(void)
	{
		if (__pApp)
		{
			Game::getInstance().getRenderer().renderFrame();
		}
		return E_SUCCESS;
	}

private:
	Wonderland* __pApp;
};


Wonderland::Wonderland() :
	__angle(0.0f),
	__pTimer(null),
	__pForm(null),
	m_lastFrameTime(0)
{
}


Wonderland::~Wonderland()
{
}


void
Wonderland::Cleanup()
{
	if (__pTimer)
	{
		__pTimer->Cancel();
		delete __pTimer;
		__pTimer = null;
	}
}


Application*
Wonderland::CreateInstance(void)
{
	return new Wonderland();
}


bool
Wonderland::OnAppInitializing(AppRegistry& appRegistry)
{
	result r = E_SUCCESS;
	IAppFrame* pAppFrame = GetAppFrame();

	__pForm = new GlesForm(this);
	if (null == __pForm)
	{
		AppLog("[Wonderland] Allocation of GlesForm has failed.\n");
		Cleanup();
		return false;
	}

	r = __pForm->Construct(FORM_STYLE_NORMAL);
	if (IsFailed(r))
	{
		AppLog("[Wonderland] __pForm->Construct(FORM_STYLE_NORMAL) has failed.\n");
		delete __pForm;
		__pForm = null;
		return false;
	}

	__pForm->SetOrientation(ORIENTATION_LANDSCAPE);

	r = GetAppFrame()->GetFrame()->AddControl(*__pForm);
	if (IsFailed(r))
	{
		AppLog("[Wonderland] GetAppFrame()->GetFrame()->AddControl(*__pForm) has failed.\n");
		delete __pForm;
		__pForm = null;
		return false;
	}

	if (null == pAppFrame)
	{
		Cleanup();
		return false;
	}

	r = pAppFrame->AddKeyEventListener(*this);
	if (IsFailed(r))
	{
		Cleanup();
		return false;
	}

//	if(!Game::getInstance().initializeGraphics((EGLNativeWindowType)__pForm))
//	{
//		Cleanup();
//		AppLog("Could not initializeGraphics");
//		return false;
//	}

	__pTimer = new Timer;
	if (null == __pTimer)
	{
		Cleanup();
		return false;
	}
	r = __pTimer->Construct(*this);
	if (IsFailed(r))
	{
		Cleanup();
		return false;
	}

	// Comment the following statement to stop listen to the screen on/off events.
	PowerManager::SetScreenEventListener(*this);


	BallsGameController* controller = new BallsGameController();
//	controller->setDifficulty(BallsGameController::GD_EASY);
//	Game::getInstance().initializeController(controller);
//	Log("Before set HUD");
//	Game::getInstance().setHUD(std::auto_ptr<HUD>(new BallsHUD(SCREEN_WIDTH, SCREEN_HEIGHT)));
	Game::getInstance().initialize(std::auto_ptr<GameController>(controller), std::auto_ptr<HUD>(new BallsHUD()));
	Game::getInstance().initializeGraphics((EGLNativeWindowType)__pForm);
//	Game::getInstance().initializeActors();
//	Game::getInstance().getRenderer().getCamera().initialize(SCREEN_WIDTH, SCREEN_HEIGHT, 27, 1, 100, Vector(0, 0, -20));
//	Game::getInstance().getHUD().initialize();
//	Game::getInstance().getResourceManager().initialize();
//	Game::getInstance().getMaterialsManager().initialize();


	__pForm->AddTouchEventListener(*this);

	return true;
}


bool
Wonderland::OnAppTerminating(AppRegistry& appRegistry, bool forcedTermination)
{
	Cleanup();
	Game::cleanup();

	return true;
}


void
Wonderland::OnForeground(void)
{
	if(__pTimer)
	{
		__pTimer->Start(DEFAULT_FRAME_TIME);
	}
}


void
Wonderland::OnBackground(void)
{
	if(__pTimer)
	{
		__pTimer->Cancel();
	}
}


void
Wonderland::OnBatteryLevelChanged(BatteryLevel batteryLevel)
{
}


void
Wonderland::OnLowMemory(void)
{
}

void
Wonderland::OnKeyPressed(const Control& source, KeyCode keyCode)
{
	Log("KeyPressed");
}


void
Wonderland::OnKeyReleased(const Control& source, KeyCode keyCode)
{
}


void
Wonderland::OnKeyLongPressed(const Control& source, KeyCode keyCode)
{
}

void
Wonderland::OnTimerExpired(Timer& timer)
{
	if (!__pTimer)
	{
		return;
	}


	long long ticks1 = 0;
	SystemTime::GetTicks(ticks1);



	Game::getInstance().getRenderer().getCamera().engineUpdate(DEFAULT_FRAME_TIME);
	Game::getInstance().update(DEFAULT_FRAME_TIME);

	Game::getInstance().getRenderer().renderFrame();

	long long ticks2 = 0;
	SystemTime::GetTicks(ticks2);

	int frameTime = static_cast<int>(ticks2 - ticks1);
	int newTimeOut = DEFAULT_FRAME_TIME - frameTime;
	if(newTimeOut < MINIMUM_FRAME_TIME)
	{
		newTimeOut = MINIMUM_FRAME_TIME;
	}

//	Log("New timeout - %d, frameTime - %d", newTimeOut, frameTime);

	__pTimer->Start(newTimeOut);
}

void
Wonderland::OnScreenOn (void)
{
	if(__pTimer)
	{
		__pTimer->Start(DEFAULT_FRAME_TIME);
	}
}

void
Wonderland::OnScreenOff (void)
{
	if(__pTimer)
	{
		__pTimer->Cancel();
	}
}

void Wonderland::OnTouchPressed(const Osp::Ui::Control &source, const Osp::Graphics::Point &currentPosition, const Osp::Ui::TouchEventInfo &touchInfo)
{
	Game::getInstance().touchPressed(currentPosition.x,SCREEN_HEIGHT - currentPosition.y);
}

void Wonderland::OnTouchReleased(const Osp::Ui::Control &source, const Osp::Graphics::Point &currentPosition, const Osp::Ui::TouchEventInfo &touchInfo)
{
	Game::getInstance().touchReleased(currentPosition.x,SCREEN_HEIGHT - currentPosition.y);
}

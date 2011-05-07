#ifndef _GLESCUBE_H_
#define _GLESCUBE_H_

#ifndef IOS

#include <FBase.h>
#include <FSystem.h>
#include <FGraphics.h>
#include <FUi.h>
#include <FApp.h>
#include <FGraphicsOpengl2.h>

#include <vector>

#include "Game.h"
#include "MathHelper.h"

class GlesCube :
	public Osp::App::Application,
	public Osp::System::IScreenEventListener,
	public Osp::Ui::IKeyEventListener,
	public Osp::Base::Runtime::ITimerEventListener,
	public Osp::Ui::ITouchEventListener
{
public:
	static Osp::App::Application* CreateInstance(void);

public:
	GlesCube();
	~GlesCube();


public:
	bool OnAppInitializing(Osp::App::AppRegistry& appRegistry);
	bool OnAppTerminating(Osp::App::AppRegistry& appRegistry, bool forcedTermination = false);
	void OnForeground(void);
	void OnBackground(void);
	void OnLowMemory(void);
	void OnBatteryLevelChanged(Osp::System::BatteryLevel batteryLevel);
	void OnKeyPressed(const Osp::Ui::Control& source, Osp::Ui::KeyCode keyCode);
	void OnKeyReleased(const Osp::Ui::Control& source, Osp::Ui::KeyCode keyCode);
	void OnKeyLongPressed(const Osp::Ui::Control& source, Osp::Ui::KeyCode keyCode);

	void OnScreenOn (void);
	void OnScreenOff (void);

	virtual void  OnActionPerformed (const Osp::Ui::Control &source, int actionId) {};
	virtual void  OnTouchDoublePressed (const Osp::Ui::Control &source,	const Osp::Graphics::Point &currentPosition, const Osp::Ui::TouchEventInfo &touchInfo) {};
	virtual void  OnTouchFocusIn (const Osp::Ui::Control &source, const Osp::Graphics::Point &currentPosition, const Osp::Ui::TouchEventInfo &touchInfo) {};
	virtual void  OnTouchFocusOut (const Osp::Ui::Control &source, const Osp::Graphics::Point &currentPosition, const Osp::Ui::TouchEventInfo &touchInfo) {};
	virtual void  OnTouchLongPressed (const Osp::Ui::Control &source, const Osp::Graphics::Point &currentPosition, const Osp::Ui::TouchEventInfo &touchInfo) {};
	virtual void  OnTouchMoved (const Osp::Ui::Control &source, const Osp::Graphics::Point &currentPosition, const Osp::Ui::TouchEventInfo &touchInfo) {};
	virtual void  OnTouchPressed (const Osp::Ui::Control &source, const Osp::Graphics::Point &currentPosition, const Osp::Ui::TouchEventInfo &touchInfo);
	virtual void  OnTouchReleased (const Osp::Ui::Control &source, const Osp::Graphics::Point &currentPosition, const Osp::Ui::TouchEventInfo &touchInfo);

public:
	void OnTimerExpired(Osp::Base::Runtime::Timer& timer);
	bool Draw();

private:
	void Cleanup();
	void getScreenDimensions(int& width, int &height) const;

private:
	static const int DEFAULT_FRAME_TIME = 30;
	static const int MINIMUM_FRAME_TIME = 5;

	static const int SCREEN_WIDTH = 800;
	static const int SCREEN_HEIGHT = 480;

	Osp::Graphics::Opengl::GLfloat     __angle;
	Osp::Base::Runtime::Timer*         __pTimer;

	Matrix m_matModelView;
	Matrix m_matProjection;

	Osp::Ui::Controls::Form*           __pForm;

	long long m_lastFrameTime;
};

#endif // IOS

#endif // __GLESCUBE_H__


/*
 * HUD.h
 *
 *  Created on: 2010-12-23
 *      Author: artur.m
 */

#ifndef HUD_H_
#define HUD_H_

#include <vector>
#include <string>
#include <memory>

#include "GameControl.h"
#include "Program.h"
#include "GameBitmap.h"
#include "HUDDataLoader.h"
#include "MathHelper.h"

class GamePanel;

class HUD
{
public:
	HUD();
	virtual ~HUD();

	// Override this one to add controls
	virtual void onInitializing() {};

	bool touchPressed(int x, int y);
	bool touchReleased(int x, int y);

	void initialize();

	void addControl(shared_ptr<GameControl> control);
	void removeControl(shared_ptr<GameControl> control);

	int getWidth() const;
	int getHeight() const;

	int getDefaultCharacterWidth() const;
	int getDefaultCharacterHeight() const;

	void setBackgroundImage(const std::string& fileName);

	bool flipUi();
	void setState(const std::string& stateName);

protected:
	void registerState(const std::string& stateName);
    //LoadDataFile and getRectangle are just wrappers
    //to identical methods in HUDDataLoader. They are here
    //to keep m_dataLoader private
    void loadDataFile(const std::string& fileName);
    Rectangle getRectangle(const std::string& id);

private:
	void drawPlane(BasicMesh* mesh, const std::string& textureName);
    void setCurrentStateHidden(bool visible);

private:
	static const std::string DEFAULT_STATE_NAME;

	int m_width;
	int m_height;

	typedef std::vector<shared_ptr<GameControl> > ControlsContainer;
	typedef ControlsContainer::iterator ControlsIter;

	class HUDState
	{
	public:
		HUDState(){}
		~HUDState() {
			for(ControlsIter it = controls.begin(); it != controls.end(); ++it) {
                Actor::destroy(*it);
			}
		}
		HUDState(const HUDState& rs) : controls(rs.controls), background(rs.background) {}
		HUDState& operator=(const HUDState& rs) {controls = rs.controls; background = rs.background; return *this;}

		ControlsContainer controls;
        shared_ptr<GamePanel> background;
    };

	typedef std::map<std::string, HUDState> StatesMap;
	typedef StatesMap::iterator StatesIter;
	StatesMap m_states;
	std::string m_currentState;
    HUDDataLoader m_dataLoader;

	Program* m_hudProgram;

	GameControl* m_pressedControl;

	std::string m_backgroundMesh;

	bool m_flipUI;
	bool m_valid; // keeps track if the object was already destroyed in case
					// something tries to remove controls
};

#endif /* HUD_H_ */

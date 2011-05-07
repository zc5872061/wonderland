/*
 * BallsHUD.h
 *
 *  Created on: 2011-01-03
 *      Author: artur.m
 */

#ifndef BALLSHUD_H_
#define BALLSHUD_H_

#include "HUD/HUD.h"

#include "HUD/GameButton.h"
#include "HUD/GamePanel.h"
#include "HUD/GameLabel.h"

#include <string>

class Board;

class BallsHUD : public HUD, public ActionListener
{
public:
	static const std::string ACCEPT_ACTION;
	static const std::string BACK_ACTION;
	static const std::string NEW_GAME_ACTION;

	static const std::string STATE_MAIN_NAME;
	static const std::string STATE_GAME_NAME;

	BallsHUD();
	virtual ~BallsHUD();

	virtual void onInitializing();

	void onActionPerformed(GameControl* source, const std::string& actionId);

	void enableAccept();
	void disableAccept();

	void updatePoints(unsigned int actualPoints);
private:

	Board* m_board;
//	GamePanel* m_panel;
	shared_ptr<GameLabel> m_pointsLabel;
	shared_ptr<GameButton> m_button;
};

#endif /* BALLSHUD_H_ */

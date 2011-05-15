/*
 * BallsHUD.cpp
 *
 *  Created on: 2011-01-03
 *      Author: artur.m
 */

#include "BallsHUD.h"

#include "MathHelper.h"
#include "Board.h"
#include "Game.h"
#include "BallsGameController.h"

#include <vector>
#include <sstream>

const std::string BallsHUD::ACCEPT_ACTION("ACCEPT");
const std::string BallsHUD::BACK_ACTION("BACK");
const std::string BallsHUD::NEW_GAME_ACTION("NEW_GAME");
const std::string BallsHUD::STATE_MAIN_NAME("STATE_MAIN");
const std::string BallsHUD::STATE_GAME_NAME("STATE_GAME");

BallsHUD::BallsHUD()
{

}

BallsHUD::~BallsHUD()
{

}

void BallsHUD::onInitializing()
{
	registerState(STATE_MAIN_NAME);
	setState(STATE_MAIN_NAME);
    
#if defined (IOS)
    loadDataFile("ui_iOS");
#elif defined (SHP)
    loadDataFile("ui_bada");
#else
    #error // load a data file here
#endif

	// Create a Button
	shared_ptr<GameButton> pButton = GameButton::spawn(getRectangle("NEW_GAME_BOUNDS"));
	pButton->setActionId(NEW_GAME_ACTION);
	pButton->addActionListener(this);
	pButton->setNormalBitmap("new_game_normal.png");
	pButton->setPressedBitmap("new_game_pressed.png");
    pButton->setText("New Game");
    pButton->setTextSize(24);
    pButton->setTextColor(80, 80, 100);
	addControl(pButton);

	pButton = GameButton::spawn(getRectangle("HIGH_SCORES_BOUNDS"));
	pButton->setNormalBitmap("high_scores_normal.png");
	pButton->setPressedBitmap("high_scores_pressed.png");
	pButton->setActionId("DRUGI");
	pButton->addActionListener(this);
    pButton->setText("High Scores");
	addControl(pButton);

	pButton = GameButton::spawn(getRectangle("HELP_BOUNDS"));
	pButton->setNormalBitmap("help_normal.png");
	pButton->setPressedBitmap("help_pressed.png");
	pButton->setActionId("trzeci");
	pButton->addActionListener(this);
    pButton->setText("aAbBcCdDeEfFgG");
	addControl(pButton);

	setBackgroundImage("main_menu_background.png");

	registerState(STATE_GAME_NAME);
	setState(STATE_GAME_NAME);

	m_button = GameButton::spawn(getRectangle("ACCEPT_BOUNDS"));
	addControl(m_button);
	m_button->addActionListener(this);
    m_button->setText("Accept");
	m_button->setActionId(ACCEPT_ACTION);
	m_button->setNormalBitmap("accept_normal.png");
	m_button->setPressedBitmap("accept_pressed.png");

	pButton = GameButton::spawn(getRectangle("BACK_BOUNDS"));
	addControl(pButton);
	pButton->addActionListener(this);
	pButton->setActionId(BACK_ACTION);
    pButton->setText("Back");
	pButton->setNormalBitmap("accept_normal.png");
	pButton->setPressedBitmap("accept_pressed.png");

	m_pointsLabel = GameLabel::spawn(getRectangle("POINTS_LABEL_BOUNDS"));
	m_pointsLabel->setText("Points: 0");
    m_pointsLabel->setTextColor(240, 13, 42);
	addControl(m_pointsLabel);

//	setBackgroundImage("main_menu_background.png");

	disableAccept();

	setState(STATE_MAIN_NAME);
}

void BallsHUD::onActionPerformed(GameControl* source, const std::string& actionId)
{
	Log("Onactionperformed - %s", actionId.c_str());
	if(actionId == ACCEPT_ACTION)
	{
		m_board->getController().acceptMove();
	}
	else if(actionId == NEW_GAME_ACTION)
	{
		static_cast<BallsGameController*>(Game::getInstance().getGameController())->startGame();

		setState(STATE_GAME_NAME);
		GameController::ActorsContainer boardContainer;
		Game::getInstance().getGameController()->getActors(Board::TYPE, boardContainer);
		assert(boardContainer.size() == 1);
		m_board = static_cast<Board*>(boardContainer[0].get());
	}
	else if(actionId == BACK_ACTION)
	{
		static_cast<BallsGameController*>(Game::getInstance().getGameController())->gameEnded();
	}
}

void BallsHUD::enableAccept()
{
	m_button->setEnabled(true);
}

void BallsHUD::disableAccept()
{
	m_button->setEnabled(false);
}

void BallsHUD::updatePoints(unsigned int actualPoints)
{
	std::string text;
	std::stringstream ss;
	ss << actualPoints;
	ss >> text;
	text = "POINTS: " + text;

	m_pointsLabel->setText(text);
}

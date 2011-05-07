/*
 * BlockButton.h
 *
 *  Created on: 2011-02-08
 *      Author: Artur
 */

#ifndef BLOCKBUTTON_H_
#define BLOCKBUTTON_H_

#include "StaticMesh.h"

#include <string>
#include <vector>

class BlockButton;
class BlockButtonListener
{
public:
	virtual void actionPerformed(BlockButton* source, const std::string& action) = 0;
};

class BlockButton : public StaticMesh
{
public:
    static shared_ptr<BlockButton> spawn(const Vector& position);
	virtual ~BlockButton();

	std::string getType() const { return "BlockButton"; }

	void setActionCommand(const std::string& action) { m_action = action; }
	const std::string& getActionCommand() const { return m_action; }

	void addListener(BlockButtonListener* listener);

	// inherited from BasicState
	virtual void update(int milis);
	virtual void touched(const Actor* target, const Vector& touchPoint);
	virtual void released(const Actor* target, const Vector& touchPoint);

private:
    BlockButton(const Vector& position);
	void fireListeners();

private:
	static const std::string MESH_NAME;

	std::string m_action;
	typedef std::vector<BlockButtonListener*> ListenersContainer;
	typedef ListenersContainer::const_iterator ListenersIter;
	ListenersContainer m_listeners;

	bool m_selected;
	Vector m_originalPos;
};

#endif /* BLOCKBUTTON_H_ */

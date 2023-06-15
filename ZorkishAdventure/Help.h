#pragma once

#include "State.h"
#include "StateManager.h"

class Help : public State
{
public:
	Help(StateManager* a_stateManager) : State(a_stateManager)
	{ }

	void enter();
	void update();
	void render();
	void exit();

};


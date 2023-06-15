#pragma once

#include "State.h"

class About : public State
{
public:
	About(StateManager* a_stateManager) : State(a_stateManager)
	{ }

	void enter();
	void update();
	void render();
	void exit();

};


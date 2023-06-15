#pragma once

#include "State.h"

class SelectAdventure : public State
{
public:
	SelectAdventure(StateManager* a_stateManager) : State(a_stateManager)
	{ }

	void enter();
	void update();
	void render();
	void exit();
};


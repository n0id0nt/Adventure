#pragma once

#include "State.h"

class HallOfFame : public State
{
public:
	HallOfFame(StateManager* a_stateManager) : State(a_stateManager)
	{ }

	void enter();
	void update();
	void render();
	void exit();
};


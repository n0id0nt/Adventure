#pragma once

#include "State.h"

class NewHighScore : public State
{
public:
	NewHighScore(StateManager* a_stateManager) : State(a_stateManager)
	{ }

	void enter();
	void update();
	void render();
	void exit();
};


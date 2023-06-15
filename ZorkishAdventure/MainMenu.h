#pragma once
#include "State.h"
#include "StateManager.h"

class MainMenu : public State
{
public:
	MainMenu(StateManager* a_stateManager) : State(a_stateManager) {}

	void enter();
	void update();
	void render();
	void exit();
};


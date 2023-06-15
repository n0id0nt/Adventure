#pragma once

#include "State.h"
#include "World.h"
#include "CommandManager.h"

class Gameplay : public State
{
public:
	Gameplay(StateManager* a_stateManager);
	
	void loadMap(std::string filename);

	void enter();
	void update();
	void render();
	void exit();

private:
	World* l_world;
	CommandManager* l_commandManager;
};


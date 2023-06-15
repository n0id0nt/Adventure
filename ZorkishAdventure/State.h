#pragma once

class StateManager;

class State
{
public:
	virtual void enter() = 0;
	virtual void update() = 0;
	virtual void render() = 0;
	virtual void exit() = 0;

protected:
	StateManager* l_stateManager;

	State(StateManager* a_stateManager)
	{
		l_stateManager = a_stateManager;
	}
};


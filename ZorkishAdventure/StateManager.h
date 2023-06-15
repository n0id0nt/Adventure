#pragma once

#include <string>
#include <map>
#include "IMessenger.h"
#include "Message.h"

class State;

class StateManager : IMessenger
{
public:
	StateManager();
	~StateManager();

	void Receive(Message message);

	void changeState(std::string a_newState);

	State& getCurState();

	void addState(std::string a_name, State* a_state);

private:
	std::map<std::string, State*> l_states;
	std::string l_curState;
};


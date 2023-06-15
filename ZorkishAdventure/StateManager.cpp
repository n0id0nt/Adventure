#include "StateManager.h"
#include "State.h"
#include "MessageBoard.h"

StateManager::StateManager()
{
	l_states = std::map<std::string, State*>();
	l_curState = "";
	MessageBoard::GetInstance()->Add("change state", this);
	MessageBoard::GetInstance()->Add("select adventure", this);
}

StateManager::~StateManager()
{
	for (auto state = l_states.begin(); state != l_states.end(); state++)
	{
		delete state->second;
	}
}

void StateManager::Receive(Message message)
{
	if (message.type == "change state")
	{
		std::string newState = message.data["new state"];
		changeState(newState);
	}
	if (message.type == "select adventure")
	{
		changeState("Gameplay");
	}
}

void StateManager::changeState(std::string a_newState)
{
	if (l_curState != "")
		l_states[l_curState]->exit();
	l_curState = a_newState;
	l_states[l_curState]->enter();
}

State& StateManager::getCurState()
{
	return *l_states[l_curState];
}

void StateManager::addState(std::string a_name, State* a_state)
{
	l_states.insert(std::pair<std::string, State*>(a_name, a_state));
}

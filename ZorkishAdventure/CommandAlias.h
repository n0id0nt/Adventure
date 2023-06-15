#pragma once
#include "Command.h"

class CommandManager;

class CommandAlias : public Command
{
public:
	CommandAlias(World* world, CommandManager* commandManager) : Command(world) {
		l_commandManger = commandManager;
	}

	std::string Process(std::vector<std::string> args);
private:
	CommandManager* l_commandManger;
};


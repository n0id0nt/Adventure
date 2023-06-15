#pragma once

#include "Command.h"

class CommandPut : public Command
{
public:
	CommandPut(World* world) : Command(world) {}

	std::string Process(std::vector<std::string> args);
};


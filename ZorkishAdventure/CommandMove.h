#pragma once

#include "Command.h"

class CommandMove : public Command
{
public:
	CommandMove(World* world) : Command(world) {}

	std::string Process(std::vector<std::string> args);
};


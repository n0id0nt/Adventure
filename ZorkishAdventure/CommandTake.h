#pragma once

#include "Command.h"

class CommandTake : public Command
{
public:
	CommandTake(World* world) : Command(world) {}

	std::string Process(std::vector<std::string> args);
};



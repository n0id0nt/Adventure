#pragma once

#include "Command.h"

class CommandLook: public Command
{
public:
	CommandLook(World* world) : Command(world) {}

	std::string Process(std::vector<std::string> args);
};


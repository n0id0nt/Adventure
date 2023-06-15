#pragma once

#include "Command.h"

class CommandInventory : public Command
{
public:
	CommandInventory(World* world) : Command(world) {}

	std::string Process(std::vector<std::string> args);
};


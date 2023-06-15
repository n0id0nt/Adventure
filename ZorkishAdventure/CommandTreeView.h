#pragma once

#include "Command.h"

class CommandTreeView : public Command
{
public:
	CommandTreeView(World* world) : Command(world) {}

	std::string Process(std::vector<std::string> args);
};


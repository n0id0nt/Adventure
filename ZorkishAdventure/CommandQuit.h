#pragma once
#include "Command.h"

class CommandQuit : public Command
{
public:
	CommandQuit(World* world) : Command(world) {}

	std::string Process(std::vector<std::string> args);
};


#pragma once

#include "Command.h"

class CommandAttack : public Command
{
public:
	CommandAttack(World* world) : Command(world) {}

	std::string Process(std::vector<std::string> args);
};


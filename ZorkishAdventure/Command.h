#pragma once

#include <vector>
#include <string>
#include "World.h"

class Command
{
public:
	virtual std::string Process(std::vector<std::string> args) = 0;

protected:
	Command(World* world)
	{
		l_world = world;
	}

	World* l_world;
};


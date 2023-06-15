#pragma once

#include "Component.h"
#include "World.h"

class ComponentMoveable : public Component
{
public:
	ComponentMoveable(Entity* parent, World* world);
	~ComponentMoveable();

	void Move(std::string newLocation);
	void Move(Entity* newLocation);

private:
	World* l_world;
};


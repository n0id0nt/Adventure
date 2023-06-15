#pragma once

#include "Component.h"

class ComponentHasInventory : public Component
{
public:
	ComponentHasInventory(Entity* parent, int capacity = -1);
	~ComponentHasInventory();

	std::string Look();

private:
	int l_capacity;
};


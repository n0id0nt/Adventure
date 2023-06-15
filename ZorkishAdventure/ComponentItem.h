#pragma once

#include "Component.h"
#include "ComponentHasInventory.h"

class ComponentItem : public Component
{
public:
	ComponentItem(Entity* parent);
	~ComponentItem();

	std::string Look();

	void MoveItem(ComponentHasInventory* destinationInventory);
};

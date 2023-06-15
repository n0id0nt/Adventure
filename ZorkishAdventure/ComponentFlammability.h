#pragma once
#include "Component.h"

class ComponentFlammability : public Component
{
public:
	ComponentFlammability(Entity* parent);
	~ComponentFlammability();

	std::string Look();

private:
	bool l_onFire;
};


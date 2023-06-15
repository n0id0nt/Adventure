#pragma once

#include "Component.h"

class ComponentDamage : public Component
{
public:
	ComponentDamage(Entity* parent, int damage);
	~ComponentDamage();

	std::string Look();

	int GetDamage();

private:
	int l_damage;
};


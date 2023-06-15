#pragma once

#include "Component.h"
#include "ComponentDamage.h"

class ComponentAttack : public Component
{
public:
	ComponentAttack(Entity* parent);
	~ComponentAttack();

	std::string Look();

	std::string Attack(ComponentAttack* target, ComponentDamage* damage, bool& isAlive);
	std::string Die();
};


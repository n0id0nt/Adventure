#pragma once

#include "Component.h"

class ComponentHealth : public Component
{
public:
	ComponentHealth(Entity* parent, int health);
	~ComponentHealth();

	std::string Look();
	int GetHealth();
	void Damage(int damage);

private:
	int l_health;
};


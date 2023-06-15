#include "ComponentHealth.h"

ComponentHealth::ComponentHealth(Entity* parent, int health) : Component(parent), l_health(health)
{
}

ComponentHealth::~ComponentHealth()
{
}

std::string ComponentHealth::Look()
{
	return "\n - HP: " + std::to_string(l_health);
}

int ComponentHealth::GetHealth()
{
	return l_health;
}

void ComponentHealth::Damage(int damage)
{
	l_health -= damage;
	if (l_health < 0) l_health = 0;
}

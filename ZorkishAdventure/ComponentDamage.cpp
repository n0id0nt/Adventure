#include "ComponentDamage.h"

ComponentDamage::ComponentDamage(Entity* parent, int damage): Component(parent), l_damage(damage)
{
}

ComponentDamage::~ComponentDamage()
{
}

std::string ComponentDamage::Look()
{
    return "\n - Damage: " + std::to_string(l_damage);
}

int ComponentDamage::GetDamage()
{
    return l_damage;
}

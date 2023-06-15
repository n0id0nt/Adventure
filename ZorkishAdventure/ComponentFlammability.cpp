#include "ComponentFlammability.h"

ComponentFlammability::ComponentFlammability(Entity* parent) : Component(parent), l_onFire(false)
{
}

ComponentFlammability::~ComponentFlammability()
{
}

std::string ComponentFlammability::Look()
{
	std::string string = "\n - Flammable: ";
	if (l_onFire) string += "on fire";
	else string += "not on fire";
	return string;
}

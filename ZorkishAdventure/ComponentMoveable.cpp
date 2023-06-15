#include "ComponentMoveable.h"
#include "Entity.h"
#include "World.h"

ComponentMoveable::ComponentMoveable(Entity* parent, World* world) : Component(parent), 
l_world(world)
{
}

ComponentMoveable::~ComponentMoveable()
{
}

void ComponentMoveable::Move(std::string newLocation)
{
	l_world->moveEntity(l_parent, l_world->GetEntity(newLocation));
}

void ComponentMoveable::Move(Entity* newLocation)
{
	l_world->moveEntity(l_parent, newLocation);
}
#include "ComponentHasInventory.h"
#include "Entity.h"

ComponentHasInventory::ComponentHasInventory(Entity* parent, int capacity) : Component(parent), l_capacity(capacity)
{
}

ComponentHasInventory::~ComponentHasInventory()
{
}

std::string ComponentHasInventory::Look()
{
    std::string string = "\n - Items:";
    // get the location through the parent of the player
    for (auto& item : l_parent->GetChildren())
    {
        if (item.second->GetName() != "Player")
            string += "\n\t - " + item.first;
    }
	return string;

}

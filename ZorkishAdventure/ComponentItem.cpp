#include "ComponentItem.h"
#include "Entity.h"
#include "ComponentMoveable.h"

ComponentItem::ComponentItem(Entity* parent) : Component(parent)
{
}

ComponentItem::~ComponentItem()
{
}

std::string ComponentItem::Look()
{
	return "\n - Is a carriable item";
}

void ComponentItem::MoveItem(ComponentHasInventory* destinationInventory)
{
	ComponentMoveable* moveable = l_parent->GetComponent<ComponentMoveable>("moveable");
	moveable->Move(destinationInventory->GetParent());
}

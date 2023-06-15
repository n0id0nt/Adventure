#include "CommandPut.h"
#include "World.h"
#include "ComponentItem.h"
#include "ComponentHasInventory.h"

std::string CommandPut::Process(std::vector<std::string> args)
{
	std::string item;
	std::string destination;
	bool addToItem = true;
	args.erase(args.begin());
	for (std::string word : args)
	{
		if (addToItem && word == "in")
		{
			addToItem = false;
		}
		else if (addToItem)
		{
			if (item != "")
				item += " ";
			item += word;
		}
		else
		{
			if (destination != "")
				destination += " ";
			destination += word;
		}
	}
	// check succefully got names from input
	if ((!addToItem && destination == "") || item == "")
	{
		return "Invalid put command: put [item] in [destination]";
	}

	// if no destination set make destination players location
	if (addToItem)
	{
		destination = l_world->GetEntity("Player")->GetParent()->GetName();
	}

	// check player has item
	if (!l_world->GetEntity("Player")->HasChild(item))
	{
		return "Player does not have " + item + " in inventory";
	}

	// check if location exists of if player has access to location
	if (l_world->GetEntity("Player")->GetParent()->GetName() != destination && !l_world->GetEntity("Player")->GetParent()->HasChild(destination))
	{
		return destination + " does not exist or player can not reach it";
	}

	// check if item is moveable
	if (!l_world->GetEntity(item)->HasComponent("moveable") && !l_world->GetEntity(item)->HasComponent("Item"))
	{
		return item + " is not an item or moveable";
	}

	// check if destination is inventory
	if (!l_world->GetEntity(destination)->HasComponent("inventory"))
	{
		return destination + " is not an inventory";
	}

	// move item
	ComponentItem* itemMoveable = l_world->GetEntity(item)->GetComponent<ComponentItem>("item");
	ComponentHasInventory* destinationInventory = l_world->GetEntity(destination)->GetComponent<ComponentHasInventory>("inventory");
	itemMoveable->MoveItem(destinationInventory);

	return "Successfully put " + item + " in " + destination;
}

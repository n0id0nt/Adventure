#include "CommandTake.h"
#include "ComponentItem.h"
#include "ComponentHasInventory.h"

std::string CommandTake::Process(std::vector<std::string> args)
{
	std::string item;
	std::string destination;
	bool addToItem = true;
	args.erase(args.begin());
	for (std::string word : args)
	{
		if (addToItem && word == "from")
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

	if ((!addToItem && destination == "") || item == "")
	{
		return "Invalid take command: take [item] from [destination]";
	}

	// if no destination set make destination players location
	if (addToItem)
	{
		destination = l_world->GetEntity("Player")->GetParent()->GetName();
	}

	// check if destination exist
	if (l_world->GetEntity("Player")->GetParent()->GetName() != destination && !l_world->GetEntity("Player")->GetParent()->HasChild(destination))
	{
		return destination + " does not exist or player can not reach it";
	}

	// check if the destination has item
	if (!l_world->GetEntity(destination)->HasChild(item))
	{
		return destination + " does not have " + item + " in inventory";
	}

	// check if item is moveable and is item
	if (!l_world->GetEntity(item)->HasComponent("moveable") && !l_world->GetEntity(item)->HasComponent("item"))
	{
		return item + " is not moveable";
	}

	// check if destination is inventory
	if (!l_world->GetEntity("Player")->HasComponent("inventory"))
	{
		return "Player is not an inventory";
	}

	// move item
	ComponentItem* itemMoveable = l_world->GetEntity(item)->GetComponent<ComponentItem>("item");
	ComponentHasInventory* destinationInventory = l_world->GetEntity("Player")->GetComponent<ComponentHasInventory>("inventory");
	itemMoveable->MoveItem(destinationInventory);

	return "Successfully put " + item + " in inventory";
}

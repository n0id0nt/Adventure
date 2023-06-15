#include "CommandInventory.h"

std::string CommandInventory::Process(std::vector<std::string> args)
{
    std::string string = "In your inventory you have:";
    // print items
    for (auto item : l_world->GetEntity("Player")->GetChildren())
    {
        string += "\n\t - " + item.first;
    }
    return string;
}



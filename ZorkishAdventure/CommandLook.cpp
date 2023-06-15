#include "CommandLook.h"
#include "ComponentLocation.h"

std::string CommandLook::Process(std::vector<std::string> args)
{
    Entity* player = l_world->GetEntity("Player");
    Entity* location = player->GetParent();
    // look
    if (args.size() == 1)
    {
        std::string string = "looking around the " + location->GetName() + " you see:";

        for (auto& component : location->GetComponents())
        {
            string += component.second->Look();
        }
        return string;
    }
    // look at
    if (args.size() > 2 && args[1] == "at")
    {
        std::string item = args[2];
        std::string destination;
        bool addToItem = true;
        for (int i = 3; i < args.size(); i++)
        {
            if (addToItem && args[i] == "in")
                addToItem = false;
            else if(addToItem)
                item += " " + args[i];
            else
            {
                if (destination != "")
                    destination += " ";
                destination += args[i];
            }
        }
        if (addToItem)
        {
            if (player->GetParent()->HasChild(item))
            {
                Entity* it = player->GetParent()->GetChild(item);
                std::string string;

                string = it->GetName() + " - " + it->GetDesc();
                for (auto& component : it->GetComponents())
                {
                    string += component.second->Look();
                }
                return string;
            }

            return item + " is not at the current location";
        }
        else
        {
            // check for location
            if (player->GetParent()->HasChild(destination))
            {
                Entity* location = player->GetParent()->GetChild(destination);
                if (location->HasChild(item))
                {
                    Entity* it = location->GetChild(item);
                    std::string string;

                    string = it->GetName() + " - " + it->GetDesc();
                    for (auto& component : it->GetComponents())
                    {
                        string += component.second->Look();
                    }
                    return string;
                }
                return item + " is not in the " + destination;
            }
            return destination + " is not at the current location";
        }
    }
    // look in
    if (args.size() > 2 && args[1] == "in")
    {
        std::string location = args[2];
        for (int i = 3; i < args.size(); i++)
        {
            location += " " + args[i];
        }
        if (player->GetParent()->HasChild(location))
        {
            std::string string = "looking in the " + location + " you see:";

            for (auto& component : player->GetParent()->GetChild(location)->GetComponents())
            {
                string += component.second->Look();
            }
            return string;
        }
        return location + " is not at the current location";
    }
    return "Invalid look command";
}

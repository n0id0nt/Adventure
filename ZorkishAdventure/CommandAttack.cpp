#include "CommandAttack.h"
#include "ComponentAttack.h"
#include "Entity.h"


std::string CommandAttack::Process(std::vector<std::string> args)
{
    if (args.size() < 2)
        return "invalid attack command: attack [target] with [weapon]";

    std::string target = args[1];
    for (int i = 2; i < args.size(); i++)
    {
        target += " " + args[i];
    }

    Entity* player = l_world->GetEntity("Player");

    // does the target exist
    if (!player->GetParent()->HasChild(target))
    {
        return "Can not find " + target + " to attack";
    }

    Entity* targetEntity = player->GetParent()->GetChild(target);

    // is target attackable
    if (!targetEntity->HasComponent("attack"))
    {
        return target + " is not attackable";
    }

    ComponentDamage* damage = NULL;
    // get the weapon
    for (auto& item : player->GetChildren())
    {
        if (item.second->HasComponent("damage"))
        {
            damage = item.second->GetComponent<ComponentDamage>("damage");
            break;
        }
    }

    if (damage == NULL)
    {
        return "You need a weapon to attack";
    }

    std::string string;
    bool isAlive;
    // attack the target
    string += player->GetComponent<ComponentAttack>("attack")->Attack(targetEntity->GetComponent<ComponentAttack>("attack"), damage, isAlive);

    // check if target is dead
    if (!isAlive) return string;

    // retaliate against the player
    string += "\n" + targetEntity->GetComponent<ComponentAttack>("attack")->Attack(player->GetComponent<ComponentAttack>("attack"), damage, isAlive);

    // check if the player is dead
    if (!isAlive) l_world->running = false;

    return string;
}


#include "World.h"
#include <string>
#include <fstream>
#include <iostream>
#include <map>
#include "ComponentLocation.h"
#include "ComponentMoveable.h"
#include "ComponentAttack.h"
#include "ComponentItem.h"
#include "ComponentDamage.h"
#include "ComponentFlammability.h"
#include "ComponentHasInventory.h"
#include "ComponentHealth.h"
#include "ComponentTalk.h"

World::World(std::string filename)
{
    running = true;
    // open file
    std::ifstream f(filename);
    nlohmann::json data = nlohmann::json::parse(f);
    f.close();

    nlohmann::json world = data["world"];
    l_world = new Entity("World", "Root Directory of the world", NULL, this);
    CreateEntity(world, l_world);
}

World::~World() 
{
    delete l_world;
}

Entity* World::GetEntity(std::string name)
{
    return GetEntityRecursive(name, l_world);
}

std::string World::DegubTreeView()
{
    std::string worldTree = "Showing world tree:";
    worldTree += l_world->Tree("\n");
    return worldTree;
}

void World::moveEntity(Entity* target, Entity* newParent)
{
    // remove target from current location
    target->GetParent()->RemoveChild(target->GetName());
    // add target to new location
    newParent->AddChild(target);
    // update the targets parents
    target->SetParent(newParent);
}

Entity* World::GetEntityRecursive(std::string name, Entity* entity)
{
    if (entity->GetName() == name) 
        return entity;
    
    for (auto& e : entity->GetChildren())
    {
        Entity* ne = GetEntityRecursive(name, e.second);
        if (ne != NULL)
            return ne;
    }

    return NULL;
}

void World::CreateEntity(nlohmann::json entities, Entity* entity)
{
    for (auto& item : entities)
    {
        Entity* newEntity = new Entity(item["name"], item["description"], entity, this);
        if (item.contains("components"))
        {
            for (auto& component : item["components"])
            {
                std::string value = component["type"];
                if (value == "location")
                {
                    ComponentLocation* location = new ComponentLocation(newEntity);
                    newEntity->AddComonent(value, location);
                    for (auto& dir : component["extra"].items())
                    {
                        location->AddConnection(dir.key(), dir.value());
                    }
                }
                else if (value == "moveable")
                {
                    newEntity->AddComonent(value, new ComponentMoveable(newEntity, this));
                }
                else if (value == "inventory")
                {
                    newEntity->AddComonent(value, new ComponentHasInventory(newEntity));
                }
                else if (value == "item")
                {
                    newEntity->AddComonent(value, new ComponentItem(newEntity));
                }
                else if (value == "damage")
                {
                    newEntity->AddComonent(value, new ComponentDamage(newEntity, component["extra"]["damage"]));
                }
                else if (value == "flammable")
                {
                    newEntity->AddComonent(value, new ComponentFlammability(newEntity));
                }
                else if (value == "health")
                {
                    newEntity->AddComonent(value, new ComponentHealth(newEntity, component["extra"]["hp"]));
                }
                else if (value == "attack")
                {
                    newEntity->AddComonent(value, new ComponentAttack(newEntity));
                }
                else if (value == "talk")
                {
                    newEntity->AddComonent(value, new ComponentTalk(newEntity));
                }
                else
                {
                    std::cout << value << " is not currently implemented" << std::endl;
                }
            }
        }
        if (item.contains("children"))
        {
            CreateEntity(item["children"], newEntity);
        }
        entity->AddChild(newEntity);
    }
}

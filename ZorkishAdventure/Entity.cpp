#include "Entity.h"
#include <set>
#include "World.h"

Entity::Entity(std::string name, std::string description, Entity* parent, World* world)
{
    l_name = name;
    l_desc = description;
    l_children = std::map<std::string, Entity*>();
    l_components = std::map<std::string, Component*>();
    l_world = world;
    l_parent = parent;
}

Entity::~Entity()
{
    std::set<Entity*> values;

    for (auto it = l_children.begin(); it != l_children.end(); it++)
    {
        if (values.find(it->second) == values.end())
            values.insert(it->second);  // value not yet encountered => remeber it
    }

    l_children.clear();

    for (auto value : values)
        delete value;

    for (auto value : l_components)
        delete value.second;
}

void Entity::AddChild(Entity* entity)
{
    l_children.insert({ entity->GetName(), entity });
}

Entity* Entity::RemoveChild(std::string entity)
{
    Entity* e = l_children[entity];
    l_children.erase(entity);
    return e;
}

void Entity::DeleteChild(std::string entity)
{
    delete l_children[entity];
    l_children.erase(entity);
}

std::map<std::string, Entity*> Entity::GetChildren()
{
    return l_children;
}

Entity* Entity::GetChild(std::string entity)
{
    return l_children[entity];
}

bool Entity::HasChild(std::string entity)
{
    return (l_children.count(entity) > 0);
}

void Entity::AddComonent(std::string name, Component* entity)
{
    l_components.insert({ name, entity });
}

std::map<std::string, Component*> Entity::GetComponents()
{
    return l_components;
}

bool Entity::HasComponent(std::string name)
{
    return (l_components.count(name) > 0);
}

std::string Entity::GetName()
{
    return l_name;
}

std::string Entity::GetDesc()
{
    return l_desc;
}

World* Entity::GetWorld()
{
    return l_world;
}

Entity* Entity::GetParent()
{
    return l_parent;
}

void Entity::SetParent(Entity* newParent)
{
    l_parent = newParent;
}

std::string Entity::Tree(std::string prefix)
{
    std::string string;
    string += prefix + " - " + l_name;
    for (auto& component : l_components)
    {
        string += " (" + component.first + ")";
    }
    for (auto& child : l_children)
    {
        string += child.second->Tree(prefix + '\t');
    }
    return string;
}

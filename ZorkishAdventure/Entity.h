#pragma once

#include <string>
#include <map>
#include "Component.h"

class World;

class Entity
{
public:
	Entity(std::string name, std::string description, Entity* parent, World* world);
	~Entity();

	// child mehtods
	void AddChild(Entity* entity);
	Entity* RemoveChild(std::string entity);
	void DeleteChild(std::string entity);
	std::map<std::string, Entity*> GetChildren();
	Entity* GetChild(std::string entity);
	bool HasChild(std::string entity);

	// component methods
	void AddComonent(std::string name, Component* entity);
	std::map<std::string, Component*> GetComponents();
	bool HasComponent(std::string name);
	template<class C> C* GetComponent(std::string name)
	{
		return dynamic_cast<C*>(l_components[name]);
	}

	// entity attributes
	std::string GetName();
	std::string GetDesc();
	World* GetWorld();
	Entity* GetParent();
	void SetParent(Entity* newParent);

	// Commands
	std::string Tree(std::string prefix);

private:
	std::string l_name;
	std::string l_desc;
	Entity* l_parent;
	World* l_world;
	std::map<std::string, Entity*> l_children;
	std::map<std::string, Component*> l_components;
};


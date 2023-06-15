#pragma once
#include <string>

class Entity;

class Component
{
public:
	Component(Entity* parent) : l_parent(parent) {}

	virtual std::string Look();

	Entity* GetParent();

protected:
	Entity* l_parent;
};


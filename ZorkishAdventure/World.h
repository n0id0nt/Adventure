#pragma once

#include "json.hpp"
#include "Entity.h"
#include <queue>

class World
{
public:
	World(std::string filename);
	~World();

	Entity* GetEntity(std::string name);

	std::string DegubTreeView();
	void moveEntity(Entity* target, Entity* newParent);

	bool running;
private:
	Entity* l_world;

	Entity* GetEntityRecursive(std::string name, Entity* entity);

	void CreateEntity(nlohmann::json entities, Entity* entity);
};


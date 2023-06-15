#pragma once

#include "Component.h"
#include <map>
#include <string>

class ComponentLocation : public Component
{
public:
	ComponentLocation(Entity* parent);
	~ComponentLocation();
	
	std::string Look();

	void AddConnection(std::string direction, std::string location);
	bool HasConnection(std::string direction);
	std::string GetConnection(std::string direction);

private:
	std::map<std::string, std::string> l_connections;
};


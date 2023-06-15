#include "ComponentLocation.h"

ComponentLocation::ComponentLocation(Entity* parent) : Component(parent)
{
	l_connections = std::map<std::string, std::string>();
}

ComponentLocation::~ComponentLocation()
{
}

std::string ComponentLocation::Look()
{
	std::string string = "\n - Connections:";
	for (auto& connection : l_connections)
	{
		string += "\n\t - " + connection.second + " to the " + connection.first;
	}
	return string;
}

void ComponentLocation::AddConnection(std::string direction, std::string location)
{
	l_connections.insert({ direction, location });
}

bool ComponentLocation::HasConnection(std::string direction)
{
	return (l_connections.count(direction) > 0);
}

std::string ComponentLocation::GetConnection(std::string direction)
{
	return l_connections[direction];
}

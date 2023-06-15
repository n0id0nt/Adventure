#include "CommandMove.h"
#include "ComponentLocation.h"
#include "ComponentMoveable.h"

std::string CommandMove::Process(std::vector<std::string> args)
{
    if (args.size() == 1)
        return "Invalid move command enter the direction you wish to head";

    std::string location = args[1];
    ComponentLocation* locationComponent = l_world->GetEntity("Player")->GetParent()->GetComponent<ComponentLocation>("location");
    if (locationComponent->HasConnection(location))
    {
        Entity* newLocation = l_world->GetEntity(locationComponent->GetConnection(location));
        l_world->GetEntity("Player")->GetComponent<ComponentMoveable>("moveable")->Move(newLocation);
    
        return  "Entering " + newLocation->GetName() + "\n" + newLocation->GetDesc();
    }

    return "location in direction \"" + location + "\" does not exist or can't be reached";
  
}

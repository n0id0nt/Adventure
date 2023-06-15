#include "CommandQuit.h"

std::string CommandQuit::Process(std::vector<std::string> args)
{
    l_world->running = false;
    return "Your adventure has ended without fame or fortune.";
}

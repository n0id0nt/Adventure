#include "CommandAlias.h"
#include "CommandManager.h"

std::string CommandAlias::Process(std::vector<std::string> args)
{
    if (args.size() != 3)
        return "syntax: \"alias NEW_WORD COMMAND_WORD\"";

    return l_commandManger->CreateAlias(args[1], args[2]);
}

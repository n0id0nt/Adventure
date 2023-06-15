#include "CommandHelp.h"
#include "CommandManager.h"

std::string CommandHelp::Process(std::vector<std::string> args)
{
	std::string string = "Commands:";
	std::vector<std::string> commands = l_commandManger->GetCommands();
	for (auto& command : commands)
	{
		string += "\n\t- " + command;
	}
	return string;
}

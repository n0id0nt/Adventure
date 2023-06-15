#pragma once
#include <map>
#include <string>
#include "Command.h"
#include <vector>

class CommandManager
{
public:
	CommandManager(World* world);
	~CommandManager();

	std::string Process(std::string input);
	std::string CreateAlias(std::string new_word, std::string command_word);

	std::vector<std::string> GetCommands();

private:
	std::map<std::string, Command*> l_commands;

};


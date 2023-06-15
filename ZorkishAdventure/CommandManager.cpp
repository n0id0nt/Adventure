#include "CommandManager.h"
#include "Game.h"
#include <vector>
#include "CommandQuit.h"
#include "CommandLook.h"
#include "CommandMove.h"
#include "CommandInventory.h"
#include "CommandHelp.h"
#include "CommandAlias.h"
#include "CommandTreeView.h"
#include "CommandPut.h"
#include "CommandTake.h"
#include "CommandAttack.h"
#include "CommandTalk.h"
#include <set>

CommandManager::CommandManager(World* world)
{

    l_commands.insert({ "quit", new CommandQuit(world) });
    l_commands.insert({ "look", new CommandLook(world) });
    l_commands.insert({ "move", new CommandMove(world) });
    l_commands.insert({ "go", l_commands["move"] });
    l_commands.insert({ "inventory", new CommandInventory(world) });
    l_commands.insert({ "help", new CommandHelp(world, this) });
    l_commands.insert({ "alias", new CommandAlias(world, this) });
    l_commands.insert({ "tree", new CommandTreeView(world) });
    l_commands.insert({ "put", new CommandPut(world) });
    l_commands.insert({ "take", new CommandTake(world) });
    l_commands.insert({ "attack", new CommandAttack(world) });
    l_commands.insert({ "talk", new CommandTalk(world) });
}

CommandManager::~CommandManager()
{
    std::set<Command*> values;

    for (std::map<std::string, Command*>::iterator it = l_commands.begin(); it != l_commands.end(); it++)
    {
        if (values.find(it->second) == values.end())
            values.insert(it->second);  // value not yet encountered => remeber it
    }

    for (auto value : values)
        delete value;

    l_commands.clear();
}

std::string CommandManager::Process(std::string input)
{
	// split the input
    std::vector<std::string> splitInput = Game::SplitString(input, ' ');

    // process the input
    if (splitInput.size() != 0)
    {
        if (l_commands.count(splitInput[0]))
        {
            return l_commands[splitInput[0]]->Process(splitInput);
        }
        else
        {
            return "Invalid input '" + splitInput[0] + "' is not a valid command\ntype 'help' for more info";
        }
    }

    return "Please enter a command";
}

std::string CommandManager::CreateAlias(std::string new_word, std::string command_word)
{
    if (l_commands.count(new_word) > 0)
        return "Alias failed. New command word " + new_word + " already exists.";
    if (l_commands.count(command_word) == 0)
        return "Alias failed. New new word " + new_word + " does not exists.";

    l_commands.insert({ new_word, l_commands[command_word] });
    return "Command alias " + new_word +" for " + command_word +" created.";
}

std::vector<std::string> CommandManager::GetCommands()
{
    std::vector<std::string> commands;
    for (std::map<std::string, Command*>::iterator it = l_commands.begin(); it != l_commands.end(); it++)
    {
        commands.push_back(it->first);
    }
    return commands;
}

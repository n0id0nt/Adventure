#include "Gameplay.h"

#include <fstream>
#include <iostream>
#include <map>
#include <cctype>
#include "StateManager.h"
#include "json.hpp"
#include "Game.h"

Gameplay::Gameplay(StateManager* a_stateManager) : State(a_stateManager) 
{

}

void Gameplay::loadMap(std::string filename)
{
    l_world = new World(filename);
}

void Gameplay::enter()
{
	std::cout << "Welcome to Zorkish: " << "Void World" << std::endl;
    loadMap(Game::mapsFiles["map"]);

    l_commandManager = new CommandManager(l_world);
}

void Gameplay::update()
{
	std::cout << ":> ";
	std::string input;
    std::getline(std::cin, input);

    std::cout << l_commandManager->Process(input) << std::endl;

    if (!l_world->running)
        l_stateManager->changeState("Main Menu");
}

void Gameplay::render()
{
}

void Gameplay::exit()
{
    // clear the memory
    delete l_world;
}

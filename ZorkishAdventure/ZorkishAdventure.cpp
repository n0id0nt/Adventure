#include <iostream>
#include "StateManager.h"
#include "MainMenu.h"
#include "Game.h"
#include "SelectAdventure.h"
#include "About.h"
#include "Help.h"
#include "HallOfFame.h"
#include "NewHighScore.h"
#include "Gameplay.h"
#include "MessageBoard.h"

int main(int argc, char** argv)
{
    if (argc != 2)
    {
        std::cout << "ERROR: incorrect number of arguments, 1 argument expected " << argc - 1 << " arguments provided" << std::endl;
        return -1;
    }

    std::cout << "File name: " << argv[1] << std::endl;

    // save the map file name
    Game::mapsFiles.insert({ "map", argv[1] });

    // initialisation
    StateManager l_stateManager = StateManager();
    l_stateManager.addState("Main Menu", new MainMenu(&l_stateManager));
    l_stateManager.addState("About", new About(&l_stateManager));
    l_stateManager.addState("Help", new Help(&l_stateManager));
    l_stateManager.addState("Select Adventure", new SelectAdventure(&l_stateManager));
    l_stateManager.addState("Hall of Fame", new HallOfFame(&l_stateManager));
    l_stateManager.addState("New High Score", new NewHighScore(&l_stateManager));
    l_stateManager.addState("Gameplay", new Gameplay(&l_stateManager));

    Game::running = true;
    l_stateManager.changeState("Main Menu");

    // gameloop 
    while (Game::running)
    {
        // update 
        l_stateManager.getCurState().update();
        //send messages
        while (MessageBoard::GetInstance()->HasMessages())
        {
            MessageBoard::GetInstance()->Deliver();
        }

        // draw
        l_stateManager.getCurState().render();
    }
    // exit
    l_stateManager.getCurState().exit();

    return 0;
}


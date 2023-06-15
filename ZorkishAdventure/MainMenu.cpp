#include "MainMenu.h"
#include <iostream>
#include "Game.h"
#include "MessageBoard.h"

void MainMenu::enter()
{
	std::cout << "Zorkish :: Main Menu\n--------------------------------------------------------\n\n" <<
		"Welcome to Zorkish Adventures\n\n" <<
		"\t1. Select Adventure and Play\n" <<
		"\t2. Hall Of Fame\n" <<
		"\t3. Help\n" <<
		"\t4. About\n" <<
		"\t5. Quit\n" << std::endl;

}

void MainMenu::update()
{
	std::cout << "Select 1-5:> ";
	// get the input
	std::string input;
	std::cin >> input;
	// change state
	if (input == "1")
	{
		nlohmann::json newState;
		newState["new state"] = "Select Adventure";
		MessageBoard::GetInstance()->Send("change state", NULL, newState);
	}
	else if (input == "2")
	{
		l_stateManager->changeState("Hall of Fame");
	}
	else if (input == "3")
	{
		l_stateManager->changeState("Help");
	}
	else if (input == "4")
	{
		l_stateManager->changeState("About");
	}
	else if (input == "5")
	{
		Game::running = false;
		std::cout << "Thanks for Playing" << std::endl;
	}
	else
	{
		std::cout << "Invalid input" << std::endl;
	}
}

void MainMenu::render()
{

}

void MainMenu::exit()
{
}

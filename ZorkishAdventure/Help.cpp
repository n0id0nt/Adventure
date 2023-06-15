#include "Help.h"
#include <iostream>

void Help::enter()
{
	std::cout << "Zorkish :: Help\n--------------------------------------------------------\n\n" <<
		"The following commands are supported:\n" <<
		"\tquit,\n" <<
		"\thighscore\n\n" <<
		"Press Enter to return to Main Menu";
}

void Help::update()
{
	std::cin.ignore();
	std::cin.get();
	l_stateManager->changeState("Main Menu");
}

void Help::render()
{
}

void Help::exit()
{
}

#include "About.h"

#include <iostream>
#include "StateManager.h"

void About::enter()
{
	std::cout << "Zorkish :: About\n--------------------------------------------------------\n\n" <<
		"Written by: Herbert Henkel\n\n" <<
		"Press Enter to return to the Main Menu";
}

void About::update()
{
	std::cin.ignore();
	std::cin.get();
	l_stateManager->changeState("Main Menu");
}

void About::render()
{
}

void About::exit()
{
}

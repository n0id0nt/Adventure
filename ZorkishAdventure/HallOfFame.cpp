#include "HallOfFame.h"
#include <iostream>
#include "StateManager.h"

void HallOfFame::enter()
{
	std::cout << "Zorkish :: Hall Of Fame\n--------------------------------------------------------\n\n" <<
		"Top 10 Zorkish Adventure Champions\n\n" <<
		"\t1. Fred, Mountain World, 5000\n" <<
		"\t2. Mary, Water World, 3000\n\n" <<
		"Press Enter to return to Main Menu";
}

void HallOfFame::update()
{
	std::cin.ignore();
	std::cin.get();
	l_stateManager->changeState("Main Menu");
}

void HallOfFame::render()
{
}

void HallOfFame::exit()
{
}

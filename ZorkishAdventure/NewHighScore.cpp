#include "NewHighScore.h"

#include <iostream>
#include "StateManager.h"

void NewHighScore::enter()
{
	std::cout << "Zorkish :: New High Score\n--------------------------------------------------------\n\n" <<
		"Congratulaitions!\n\n" <<
		"You have made it to the Zorkish hall of Fame\n\n" <<
		"Adventure: " << "[adventure name]" << "\n" <<
		"Score: " << "[player score]" << "\n" <<
		"Moves: " << "[number of moves player made]" << "\n\n" <<
		"Please type your name and press enter:\n:> ";
}

void NewHighScore::update()
{
	std::string name;
	std::cin >> name;
	l_stateManager->changeState("Hall of Fame");
}

void NewHighScore::render()
{
}

void NewHighScore::exit()
{
}

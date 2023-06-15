#include "SelectAdventure.h"
#include <iostream>
#include "StateManager.h"
#include "MessageBoard.h"

void SelectAdventure::enter()
{
	std::cout << "Zorkish :: Select Adventrue\n--------------------------------------------------------\n\n" <<
		"Choose your adventure:\n" <<
		"\t1. Mountain World\n" <<
		"\t2. Water World\n" <<
		"\t3. Box World\n" << std::endl;

}

void SelectAdventure::update()
{
	std::cout << "Select 1-3:> ";
	std::string input;
	std::cin >> input;

	MessageBoard::GetInstance()->Send("select adventure");
}

void SelectAdventure::render()
{
}

void SelectAdventure::exit()
{
}

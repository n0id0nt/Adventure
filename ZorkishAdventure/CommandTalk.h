#pragma once
#include "Command.h"
#include "IMessenger.h"
#include "Message.h"

class CommandTalk : public Command, IMessenger
{
public:
	CommandTalk(World* world);

	std::string Process(std::vector<std::string> args);

	void Receive(Message message);
};


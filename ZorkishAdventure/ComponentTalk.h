#pragma once
#include "Component.h"
#include "IMessenger.h"
#include "Message.h"


class ComponentTalk : public Component, IMessenger
{
public:
	ComponentTalk(Entity* parent);
	~ComponentTalk() {}

	void Receive(Message message);

	std::string Resond(std::string message);

};


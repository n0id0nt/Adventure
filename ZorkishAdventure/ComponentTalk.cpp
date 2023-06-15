#include "ComponentTalk.h"
#include <iostream>
#include "MessageBoard.h"
#include "Entity.h"

ComponentTalk::ComponentTalk(Entity* parent) : Component(parent)
{
	MessageBoard::GetInstance()->Add("talk", this);
}

void ComponentTalk::Receive(Message message)
{
	if (message.type == "talk")
	{
		std::string data = message.data["message"];

		nlohmann::json messageJSON;
		messageJSON["message"] = Resond(message.data["message"]);

		MessageBoard::GetInstance()->Send("talk respond", this, messageJSON);
	}
}

std::string ComponentTalk::Resond(std::string message)
{
	if (message == "hi")
	{
		return l_parent->GetName() + ": Hello, i am talking to you";
	}
	if (message == "bye")
	{
		return l_parent->GetName() + ": see you later";
	}
	return l_parent->GetName() + ": i dont understand";
}

#include "CommandTalk.h"
#include <iostream>
#include "MessageBoard.h"
#include "ComponentTalk.h"


CommandTalk::CommandTalk(World* world) : Command(world) 
{
    MessageBoard::GetInstance()->Add("talk respond", this);
}

std::string CommandTalk::Process(std::vector<std::string> args)
{
    if (args.size() < 2)
        return "invalid attack command: say [message]";

    std::string message = args[1];
    for (int i = 2; i < args.size(); i++)
    {
        message += " " + args[i];
    }

    nlohmann::json messageJSON;
    messageJSON["message"] = message;

    MessageBoard::GetInstance()->Send("talk", this, messageJSON);

    return "Player: " + message;
}

void CommandTalk::Receive(Message message)
{
    if (message.type == "talk respond")
    {
        std::string data = message.data["message"];

        std::cout <<  data << std::endl;
    }
}
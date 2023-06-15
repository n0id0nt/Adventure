#include "MessageBoard.h"

MessageBoard* MessageBoard::_instance = nullptr;

MessageBoard* MessageBoard::GetInstance()
{
    if (!_instance)
        _instance = new MessageBoard();
    return _instance;
}

void MessageBoard::Add(std::string type, IMessenger* reciever)
{
    _listeners.insert({ type, reciever });
}

bool MessageBoard::HasMessages()
{
    return _messages.size() > 0;
}

void MessageBoard::Send(std::string type, IMessenger* sender, nlohmann::json data)
{
    Message message;
    message.sender = sender;
    message.type = type;
    message.data = data;
    _messages.push(message);
}

void MessageBoard::Deliver()
{
    // dequeue first element
    Message message = _messages.front();
    _messages.pop();

    for (auto receiver : _listeners)
    {
        if (receiver.first == message.type)
        {
            receiver.second->Receive(message);
        }
    }
}
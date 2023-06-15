#pragma once

#include <queue>
#include "Message.h"
#include <map>

class MessageBoard 
{
public:
    static MessageBoard* GetInstance();

    ~MessageBoard() {}

    void Add(std::string type, IMessenger* reciever);

    void Send(std::string type, IMessenger* sender = NULL, nlohmann::json data = NULL);

    void Deliver();

    bool HasMessages();

private:
    MessageBoard() {}
    static MessageBoard* _instance;

    std::queue<Message> _messages;
    std::multimap<std::string, IMessenger*> _listeners;
};


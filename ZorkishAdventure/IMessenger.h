#pragma once
#include <string>

struct Message;

class IMessenger
{
public:
	virtual void Receive(Message message) = 0;
};


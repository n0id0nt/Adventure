#pragma once

#include <string>
#include "IMessenger.h"
#include "json.hpp"

struct Message
{
	//sender
	IMessenger* sender;
	//type function pointer
	std::string type;
	//data
	nlohmann::json data;
};


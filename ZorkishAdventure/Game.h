#pragma once
#include <map>
#include <string>
#include <regex>
#include <vector>

class Game
{
public:
	static bool running;
	static std::map<std::string, std::string> mapsFiles;

	static std::vector<std::string> SplitString(std::string line, char seperatetion)
	{
        // remove leading and trailing blank spaces
        std::string lineNew = std::regex_replace(line, std::regex("^ +| +$|( ) +"), "$1");

        // ignore empty line
        if (lineNew.empty())
            return std::vector<std::string>();

        // split line
        std::vector<std::string> bitsString = std::vector<std::string>();
        std::string token;
        size_t pos = 0;
        do
        {
            pos = lineNew.find(seperatetion);
            // if (!check) pos = line.length();
            token = lineNew.substr(0, pos);
            bitsString.push_back(token);
            lineNew.erase(0, pos + 1);
        } while (pos != std::string::npos);

        return bitsString;
	}
};
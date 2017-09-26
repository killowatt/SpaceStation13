#include "Core.h"
#include <fstream>
#include <sstream>

std::string FileLoadLines(const std::string& filename) // TODO:  redo this garbage
{
	std::string file;
	std::ifstream fileStream(filename.c_str(), std::ios::in);
	if (fileStream.is_open())
	{
		std::string line = "";
		while (getline(fileStream, line))
			file += "\n" + line;
		fileStream.close();
		return file;
	}
	throw std::exception("stop"); // TODO: do this function properly; print couldnt find
}                                // return empty string!

std::vector<std::string> SplitString(const std::string& string, const char delimiter)
{
	std::stringstream stream(string);
	std::string item;
	std::vector<std::string> tokens;
	while (std::getline(stream, item, delimiter))
	{
		tokens.push_back(item);
	}
	return tokens;
}
std::set<std::string> SplitStringUnique(const std::string& string, const char delimiter)
{
	std::stringstream stream(string);
	std::string item;
	std::set<std::string> tokens;
	while (std::getline(stream, item, delimiter))
	{
		tokens.insert(item);
	}
	return tokens;
}
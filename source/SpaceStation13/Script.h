#pragma once
#include <string>

struct lua_State; // Forward declare.. wait does this still make it where outsiders can see (probably)
class Script
{
private:
	lua_State* L;
public:
	Script(const std::string& fileName);
};
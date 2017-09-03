#pragma once
#include "Core.h"
#include <string>

extern "C" // TODO: somehow somewway lets not pollute the god damned namespace (impl prob)
{
#include <lua/lua.h>
#include <lua/lauxlib.h>
#include <lua/lualib.h>
}

class Script
{
private:
	lua_State* L;

	bool GetFromStack(const std::string& variable, int32& level);

	template<typename T> T Get() { return 0; }
	template<typename T> T GetDefault() { return 0; }
public:

	template<typename T>
	T GetVariable(const std::string& name);

	Script(const std::string& fileName);
};

template<typename T>
T Script::GetVariable(const std::string& name)
{
	if (!L)
		return GetDefault<T>();

	T result;
	int32 level;
	if (GetFromStack(name, level))
		result = Get<T>();
	else
		result = GetDefault<T>();

	lua_pop(L, level + 1);
	return result;
}

// Template Functions
template<>
inline int32 Script::Get()
{
	if (!lua_isnumber(L, -1))
		return 0; // TODO: print not number
	return (int32)lua_tonumber(L, -1);
}
template<>
inline float Script::Get()
{
	if (!lua_isnumber(L, -1))
		return 0;
	return (float)lua_tonumber(L, -1);
}
template<>
inline std::string Script::Get()
{
	if (!lua_isstring(L, -1))
		return "";
	return std::string(lua_tostring(L, -1));
}

template<>
inline std::string Script::GetDefault() { return ""; }
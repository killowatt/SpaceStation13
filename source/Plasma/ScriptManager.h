#pragma once
extern "C"
{
#include <lua/lua.h>
#include <lua/lauxlib.h>
#include <lua/lualib.h>
}

class ScriptManager
{
private:
	lua_State* luaState;

public:
	void Initialize();
};
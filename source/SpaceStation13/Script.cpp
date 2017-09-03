#include "Script.h"

extern "C"
{
#include <lua/lua.h>
#include <lua/lauxlib.h>
#include <lua/lualib.h>
}

Script::Script(const std::string& fileName)
{
	L = luaL_newstate();
	if (luaL_loadfile(L, fileName.c_str()) || lua_pcall(L, 0, 0, 0))
		return; // TODO: log script failure
}
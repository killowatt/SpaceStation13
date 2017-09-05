#include "ScriptManager.h"

void ScriptManager::Initialize()
{
	luaState = luaL_newstate();
}
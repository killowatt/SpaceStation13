//#include "Script.h"
//
//Script::Script(const std::string& fileName)
//{
//	L = luaL_newstate();
//	if (luaL_loadfile(L, fileName.c_str()) || lua_pcall(L, 0, 0, 0))
//		return; // TODO: log script failure
//
//	//luaL_openlibs(L); // This opens up the lua-scripting standard libs (like io)
//}
//
//// Util
//bool Script::GetFromStack(const std::string& variable, int32& level)
//{
//	level = 0;
//	std::string luaVariable = "";
//	for (uint32 i = 0; i < variable.size(); i++)
//	{
//		if (variable.at(i) == '.')
//		{
//			if (level == 0)
//				lua_getglobal(L, luaVariable.c_str());
//			else
//				lua_getfield(L, -1, luaVariable.c_str());
//
//			if (lua_isnil(L, -1))
//				return false; // TOOD: print -- is not defined
//			else
//			{
//				luaVariable = "";
//				level++;
//			}
//		}
//		else
//			luaVariable += variable.at(i);
//	}
//	if (level == 0)
//		lua_getglobal(L, luaVariable.c_str());
//	else
//		lua_getfield(L, -1, luaVariable.c_str());
//
//	if (lua_isnil(L, -1))
//		return false; //  TODO: print is not defined
//	return true;
//}
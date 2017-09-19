#include "ScriptManager.h"
#include "ChakraCore.h"
#include "ErrorCode.h"

void ScriptManager::Initialize()
{
	JsErrorCode error = JsCreateRuntime(JsRuntimeAttributeNone, nullptr, &Runtime);
	if (error) Log::Print(LogCategory::Fatal, "Script Engine Runtime initialization failed (%s)",
			ErrorCodeToString(error).c_str());


}

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
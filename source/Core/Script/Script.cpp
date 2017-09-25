#include "Script.h"
#include "ChakraCore.h"
#include "ErrorCode.h"
#include <vector>

#include "NativeBindings.h"

// TODO: pass along error messages to scriptmanager for it to handle as script engine events?

Script::Script()
{
	Context = nullptr;
}
Script::Script(void* runtime, const std::string& source)
{
	JsErrorCode error;

	error = JsCreateContext(runtime, &Context);
	if (error) Log::Print(LogCategory::Error, "Script creation failed (%s)",
		ErrorCodeToString(error).c_str());

	error = JsSetCurrentContext(Context);
	if (error) Log::Print(LogCategory::Error, "Failed to set script context (%s)",
		ErrorCodeToString(error).c_str());

	JsValueRef sourceJS;
	error = JsCreateExternalArrayBuffer((void*)source.c_str(), source.size(),
		nullptr, nullptr, &sourceJS);
	if (error) Log::Print(LogCategory::Error, "Script creation failed (%s)",
		ErrorCodeToString(error).c_str());


	// temp
	RegisterFunction("plasmaLog", LogBinding);



	JsValueRef origin;
	JsCreateString("", strlen(""), &origin);

	error = JsRun(sourceJS, 0, origin, JsParseScriptAttributeNone, nullptr);
	if (error) Log::Print(LogCategory::Error, "Script evaluation failed (%s)",
		ErrorCodeToString(error).c_str());



	return;
}

void Script::CallFunction()
{
	//JsRun(
}
void Script::RegisterFunction(const std::string& name, JsNativeFunction function)
{
	JsErrorCode error;

	JsPropertyIdRef propertyId;
	error = JsCreatePropertyId(name.c_str(), name.size(), &propertyId);

	JsValueRef functionRef;
	error = JsCreateFunction(function, nullptr, &functionRef);

	JsValueRef global;
	error = JsGetGlobalObject(&global);
	error = JsSetProperty(global, propertyId, functionRef, true);
}

void* Script::GetPropertyRef(const std::string& name) // TODO: handle errors, return bool and use
{                                                   // out variable instead for ref
	JsValueRef last;
	JsGetGlobalObject(&last);
	
	std::string current;
	for (uint64 i = 0; i < name.size(); i++)
	{
		bool final = false;
		if (name.at(i) == '.' || (final = (name.find('.', i) == std::string::npos)))
		{
			if (final)
			{
				current = name.substr(i);
				i = name.size();
			}

			JsPropertyIdRef propertyId;
			JsCreatePropertyId(current.c_str(), current.size(), &propertyId);

			JsValueRef value;
			JsGetProperty(last, propertyId, &value); // See if we can merge these two lines by &last
			last = value;

			current = "";
		}
		else
			current += name.at(i);
	}

	return last;
	
	
	// TODO: Method below is potentially faster (not sure) please test

	//JsValueRef global;
	//JsGetGlobalObject(&global);

	//// Separate structure into individual pieces
	//std::vector<std::string> elements;

	//uint64 index = 0;
	//if (name.find('.') != std::string::npos)
	//{
	//	while (name.find('.', index) != std::string::npos)
	//	{
	//		std::string result = name.substr(index, name.find('.'));
	//		elements.push_back(result);
	//		index += result.size() + 1;
	//	}
	//}
	//elements.push_back(name.substr(index));

	// Get the property, recursively moving through the structure
	//JsValueRef last;
	//JsGetGlobalObject(&last);
	//for (int i = 0; i < elements.size(); i++)
	//{
	//	JsPropertyIdRef propertyId;
	//	JsCreatePropertyId(elements[i].c_str(), elements[i].size(), &propertyId);

	//	JsValueRef valueRef;
	//	JsGetProperty(last, propertyId, &valueRef);
	//	last = valueRef; // Try doing this directly in above func
	//}
	//return last;
}
int32 Script::GetInteger(void* value)
{
	int32 result = 0;
	JsErrorCode error = JsNumberToInt(value, &result);
	if (error) Log::Print(LogCategory::Warning, "Failed to get integer from script (%s)",
		ErrorCodeToString(error).c_str());

	return result;
}
double Script::GetDouble(void* value)
{
	double result = 0;
	JsErrorCode error = JsNumberToDouble(value, &result);
	if (error) Log::Print(LogCategory::Warning, "Failed to get double from script (%s)",
		ErrorCodeToString(error).c_str());

	return result;
}
std::string Script::GetString(void* value) // TODO: revamp to be faster? goes for everything
{
	JsValueRef stringRef;
	JsConvertValueToString(value, &stringRef);

	int32 length = 0;
	JsGetStringLength(stringRef, &length);

	char* buffer = new char[length + 1];
	JsCopyString(stringRef, buffer, length, nullptr);
	buffer[length] = '\0'; // TODO: do we need this? shouldnt there be a null term already?

	std::string result(buffer, length + 1);
	delete[] buffer;

	return result;
}



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
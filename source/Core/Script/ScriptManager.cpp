#include "ScriptManager.h"
#include "ChakraCore.h"
#include "ErrorCode.h"

uint64 ScriptManager::CreateScript(const std::string& source)
{
	uint64 index = Scripts.size();
	Scripts.push_back(Script(Runtime, source));
	return index;
}


void ScriptManager::Initialize()
{
	JsErrorCode error = JsCreateRuntime(JsRuntimeAttributeNone, nullptr, &Runtime);
	if (error) Log::Print(LogCategory::Fatal, "Script Engine Runtime initialization failed (%s)",
			ErrorCodeToString(error).c_str());
}


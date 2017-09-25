#include "ScriptManager.h"
#include "ChakraCore.h"
#include "ErrorCode.h"

//uint64 ScriptManager::CreateScript(const std::string& source)
//{
//	uint64 index = Scripts.size(); // TODO: set VAR in SCRIPT that states is valid, give errors
//	Scripts.push_back(Script(Runtime, source)); // at loadtime in script. Prevent addition from
//	return index; // Script indexer (manager) so that we dont have a bunch of references
//}                                   // to potentially broken script(s).


void ScriptManager::Initialize()
{
	JsErrorCode error = JsCreateRuntime(JsRuntimeAttributeNone, nullptr, &Runtime);
	if (error) Log::Print(LogCategory::Fatal, "Script Engine Runtime initialization failed (%s)",
			ErrorCodeToString(error).c_str());
}

Script& ScriptManager::GetScript(const std::string& name)
{
	if (Scripts.count(name) > 0)
		return Scripts[name];

	Script script(Runtime, FileLoadLines(name + ".js"));
	Scripts[name] = script;
}


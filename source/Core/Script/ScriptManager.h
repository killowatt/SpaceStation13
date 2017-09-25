#pragma once
#include "Core.h"
#include "Script.h"
#include <unordered_map>

class ScriptManager
{
private:
	void* Runtime;

	//std::vector<Script> Scripts;
	std::unordered_map<std::string, Script> Scripts;

public:
	//uint64 CreateScript(const std::string& source);

	Script& GetScript(const std::string& name);

	void Initialize();
};
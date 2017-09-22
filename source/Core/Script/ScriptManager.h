#pragma once
#include "Core.h"
#include "Script.h"
#include <vector>

class ScriptManager
{
private:
	void* Runtime;

	std::vector<Script> Scripts;

public:
	uint64 CreateScript(const std::string& source);

	void Initialize();
};
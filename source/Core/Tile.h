#pragma once
#include "Core.h"

class Tile
{
private:
	std::string ScriptName;

public:
	Tile();

	void SetScriptName(const std::string& name) { ScriptName = name; }
};
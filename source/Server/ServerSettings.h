#pragma once
#include "Core.h"

struct ServerSettings
{
	bool AllowContentHashMismatch = false; // not yet impl, example
	uint32 CullingDistance = 4;

	std::string PlayerScript = "player.js";
};
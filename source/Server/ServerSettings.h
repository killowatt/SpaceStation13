#pragma once
#include <string>

struct ServerSettings
{
	bool AllowContentHashMismatch = false; // not yet impl, example

	std::string PlayerScript = "player.js";
};
#pragma once
#include "Core.h"
#include <string>

class Tile : NonCopyable
{
private:
	std::string SpriteName; // /?
	bool SpriteEnabled;

public:
	Tile();
};
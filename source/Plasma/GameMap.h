#pragma once
#include "Engine.h"
#include "Tile.h"
#include <string>

class GameMap : NonCopyable
{
private:
	Tile* TileData;
	uint32 Width;
	uint32 Height;

public:
	void SaveFile() { };

	GameMap(const std::string& filename);
};
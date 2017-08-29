#pragma once
#include "Core.h"
#include "Tile.h"
#include <string>

class GameMap : NonCopyable
{
private:
	Tile* TileData;
	uint32 Width;
	uint32 Height;

public:
	uint32 GetWidth() const { return Width; }
	uint32 GetHeight() const { return Height; }

	void SaveFile() { };

	GameMap(uint32 width, uint32 height);

	GameMap(const std::string& filename);
};
#pragma once
#include "Core.h"
#include "Tile.h"

class GameMap : NonCopyable
{
private:
	Tile* TileData;
	uint32 Width;
	uint32 Height;

	uint32 IndexFromVector2D(uint32 x, uint32 y) { return Width * y + x; }
public:
	std::string Name;

	GameMap(uint32 width, uint32 height);
	GameMap(const std::string& filename);

	void Serialize(); // To standard file
	//void Compile(); // TODO: JSON data for map-editor files?

	Tile& GetTile(uint32 index) { return TileData[index]; }
	Tile& GetTile(uint32 x, uint32 y) { return TileData[IndexFromVector2D(x, y)]; }

	uint32 GetWidth() const { return Width; }
	uint32 GetHeight() const { return Height; }
};
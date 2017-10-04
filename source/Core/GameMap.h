#pragma once
#include "Core.h"
#include "Tile.h"

constexpr uint32 SECTION_SIZE = 16; // Squared
									// TODO: ADD TO CONFIG
class MapSection
{
	std::vector<Tile> Tiles;
	// YA DONT NEED LAYERS

	uint32 Width; // Volume size
	uint32 Height; // These are for literal edge cases

public:
	MapSection();
	MapSection(uint32 width, uint32 height);

	uint32 IndexFromVector2D(uint32 x, uint32 y) { return Width * y + x; }

	Tile& GetTile(uint32 x, uint32 y);
	Tile& GetTile(uint32 index);
};
class GameMap : NonCopyable
{
private:
	std::vector<MapSection*> Sections;

	uint32 Width;
	uint32 Height;

	uint32 IndexFromVector2D(uint32 x, uint32 y) 
	{ 
		uint32 width = (uint32)std::floor(Width / SECTION_SIZE);
		return width * y + x; 
	}
public:
	std::string Name;

	GameMap(uint32 width, uint32 height);
	GameMap(const std::string& filename);
	~GameMap();

	void Serialize(); // To standard file
	//void Compile(); // TODO: JSON data for map-editor files?

	Tile& GetTile(uint32 x, uint32 y);

	MapSection* GetSection(uint32 x, uint32 y);

	uint32 GetWidth() const { return Width; }
	uint32 GetHeight() const { return Height; }
};
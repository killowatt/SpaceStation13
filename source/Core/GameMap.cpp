#include "GameMap.h"

GameMap::GameMap(uint32 width, uint32 height)
{
	TileData = new Tile[width * height];
	Width = width;
	Height = height;

	Name = "DefaultMapName";
}
GameMap::GameMap(const std::string& filename)
{

}

void GameMap::Serialize()
{

}
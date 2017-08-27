#include "GameMap.h"

GameMap::GameMap(uint32 width, uint32 height)
{
	TileData = new Tile[width * height];
	Width = width;
	Height = height;
}
GameMap::GameMap(const std::string& filename)
{

}
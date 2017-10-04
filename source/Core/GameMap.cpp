#include "GameMap.h"
#include <cmath>

MapSection::MapSection()
{
	Width = 0;
	Height = 0;
}
MapSection::MapSection(uint32 width, uint32 height)
{
	Tiles.resize(width * height);
	Width = width;
	Height = height;
}

Tile& MapSection::GetTile(uint32 x, uint32 y)
{
	AssertRT(x < Width && y < Height, "Section coordinates were out of bounds.");
	return GetTile(IndexFromVector2D(x, y));
}
Tile& MapSection::GetTile(uint32 index)
{
	AssertRT(index < Tiles.size(), "Section index was out of bounds.");
	return Tiles[index];
}

GameMap::GameMap(uint32 width, uint32 height)
{
	Width = width;
	Height = height;

	Name = "DefaultMapName";

	uint32 remainderX = width % SECTION_SIZE;
	uint32 remainderY = height % SECTION_SIZE;

	uint32 completeSectionsX = (width - remainderX) / SECTION_SIZE;
	uint32 completeSectionsY = (height - remainderY) / SECTION_SIZE;

	uint32 totalSectionsX = completeSectionsX + (remainderX > 0);
	uint32 totalSectionsY = completeSectionsY + (remainderY > 0);

	Sections.resize(totalSectionsX * totalSectionsY);

	for (uint32 x = 0; x < totalSectionsX; x++)
	{
		for (uint32 y = 0; y < totalSectionsY; y++)
		{
			uint32 sectionWidth = SECTION_SIZE;
			uint32 sectionHeight = SECTION_SIZE;
			if (x > totalSectionsX)
				sectionWidth = remainderX;
			if (y > totalSectionsY)
				sectionHeight = remainderY;

			Sections[totalSectionsX * y + x] = new MapSection(sectionWidth, sectionHeight);
		}
	}
}
GameMap::GameMap(const std::string& filename)
{

}
GameMap::~GameMap()
{
	for (uint32 i = 0; i < Sections.size(); i++)
	{
		if (Sections[i])
			delete Sections[i];
	}
}

Tile& GameMap::GetTile(uint32 x, uint32 y)
{
	uint32 localX = x % SECTION_SIZE;
	uint32 localY = y % SECTION_SIZE;
	return GetSection(x, y)->GetTile(localX, localY);
}

MapSection* GameMap::GetSection(uint32 x, uint32 y)
{
	uint32 sectionX = (uint32)std::floor(x / SECTION_SIZE); // TODO: maybe we use a betr int floor
	uint32 sectionY = (uint32)std::floor(y / SECTION_SIZE); // func

	uint32 index = IndexFromVector2D(sectionX, sectionY);
	AssertRT(index < Sections.size(), "Section index was out of bounds");
	
	if (Sections[index])
		return Sections[index];

	return nullptr;
}

void GameMap::Serialize()
{

}
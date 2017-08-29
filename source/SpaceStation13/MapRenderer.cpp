#include "MapRenderer.h"

void MapRenderer::TestRender()
{
	for (int x = 0; x < Map->GetWidth(); x++)
	{
		for (int y = 0; y < Map->GetHeight(); y++)
		{
		}
	}
}

MapRenderer::MapRenderer(const GameMap& gameMap, RendererGL* renderer) // TODO: unrelated, code guidelines please!!
{
	Renderer = renderer;
	Map = &gameMap;

	//Sprites = std::vector<Sprite>(gameMap.GetWidth() * gameMap.GetHeight(),
	//	Sprite(renderer, new Texture(renderer)));
}
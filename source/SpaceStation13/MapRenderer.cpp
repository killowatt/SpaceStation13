#include "MapRenderer.h"

void MapRenderer::TestRender()
{
	for (int x = 0; x < Map->GetWidth(); x++)
	{
		for (int y = 0; y < Map->GetHeight(); y++)
		{
			uint32 index = Map->GetWidth() * y + x;
			Sprites[index]->SetPosition(glm::ivec2(x * 64, y * 64));
			Renderer->Render(Sprites[index]);
		}
	}
}

MapRenderer::MapRenderer(const GameMap& gameMap, RendererGL* renderer) // TODO: unrelated, code guidelines please!!
{
	Renderer = renderer;
	Map = &gameMap;

	Texture* tex = Renderer->CreateTexture();
	tex->LoadFromFile("test.png");
	Sprites = std::vector<Sprite*>(gameMap.GetWidth() * gameMap.GetHeight(),
		new Sprite(renderer, tex));
}
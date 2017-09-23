#include "MapRenderer.h"
#include "GL/glew.h"

void MapRenderer::TestRender()
{
//
//
//	//for (int x = 0; x < Map->GetWidth(); x++)
//	//{
//	//	for (int y = 0; y < Map->GetHeight(); y++)
//	//	{
//	//		uint32 index = Map->GetWidth() * y + x;
//	//		Sprites[index]->SetPosition(glm::ivec2(x * 32, y * 32));
//	//		Renderer->Render(Sprites[index]);
//	//	}
//	//}
}



MapRenderer::MapRenderer(const GameMap* map, RendererGL* renderer) // TODO: unrelated, code guidelines please!!
{
	Renderer = renderer;
	Map = map;
}
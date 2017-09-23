#pragma once
#include "Core.h"
#include "GameMap.h"
#include "Sprite.h"
#include <vector>
#include <map>

class MapRenderer : NonCopyable
{
	RendererGL* Renderer;
	//std::map<std::string, Texture*> TextureMap; // (future reference, not real)

	const GameMap* Map;

	std::vector<Texture*> Textures;
	std::vector<Sprite*> Sprites;

public:


	void TestRender();

	MapRenderer(const GameMap* map, RendererGL* renderer);
};
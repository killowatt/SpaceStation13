#pragma once
#include "Core.h"
#include "GameMap.h"
#include "Sprite.h"
#include <vector>

class MapRenderer : NonCopyable
{
	RendererGL* Renderer;

	const GameMap* Map;
	std::vector<Sprite*> Sprites;

public:
	void TestRender();

	MapRenderer(const GameMap& gameMap, RendererGL* renderer);
};
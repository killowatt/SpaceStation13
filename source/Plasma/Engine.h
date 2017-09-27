#pragma once
#include "Core.h"
#include "Client.h"
#include "RendererGL.h"

// External Dependencies
#include "SDL/SDL.h"
#include <map>

class GameMap;
class Engine
{
private:
	Client Client;

	RendererGL* Renderer;

	GameMap* CurrentMap;

public:

	void ChangeLevel(GameMap* map);

	void Initialize();
	void Update();
	void Render();

	Engine();
};
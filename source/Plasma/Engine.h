#pragma once
#include "Core.h"
#include "Client.h"

class GameMap;
class Engine
{
private:
	Client Client;

	GameMap* CurrentMap;

public:

	void ChangeLevel(GameMap* map);

	void Initialize();
	void Update();
	void Render();

	Engine();
};
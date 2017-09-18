#pragma once
#include "GameState.h"
#include "GameMap.h"

class EditorState : public GameState
{
	GameMap* TargetMap;

	void Initialize();
	
	void Update();
	void Render();

	EditorState();
};
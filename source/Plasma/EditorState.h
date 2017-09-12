#pragma once
#include "GameState.h"

class EditorState : public GameState
{
	void Initialize();
	
	void Update();
	void Render();

	EditorState();
};
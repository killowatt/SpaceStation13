#pragma once
#include "Core.h"
#include "SDL/SDL.h"

class InputManager
{
public:
	void Update(SDL_Event& event) { }

	bool KeyPressed(int32 key) { return false; }
};
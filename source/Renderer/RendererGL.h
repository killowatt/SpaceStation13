#pragma once
#include "SDL/SDL.h"

class RendererGL
{
private:
	SDL_Window* window;

public:

	void Initialize();

	RendererGL();
	~RendererGL();
};
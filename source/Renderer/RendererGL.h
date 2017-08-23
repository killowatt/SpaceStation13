#pragma once
#include "Engine.h"
#include "Texture.h"
#include "SDL/SDL.h"

class Texture;
class RendererGL : NonCopyable
{
private:
	SDL_Window* window;

public:
	Texture* CreateTexture();

	void Initialize();

	RendererGL();
	~RendererGL();
};
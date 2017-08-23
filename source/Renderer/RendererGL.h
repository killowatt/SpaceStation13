#pragma once
#include "Engine.h"
#include "Texture.h"
#include "Sprite.h"
#include "SDL/SDL.h"

class Texture;
class Sprite;
class RendererGL : NonCopyable
{
private:
	SDL_Window* window;

public:
	Texture* CreateTexture();

	void Render(Sprite* sprite);

	void Initialize();

	RendererGL();
	~RendererGL();
};
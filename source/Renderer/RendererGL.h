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
	SDL_Window* Window;
	SDL_GLContext Context;

public:
	Texture* CreateTexture();

	void Render(Sprite* sprite);

	void Clear() {}
	void SwapBuffers() { SDL_GL_SwapWindow(Window); }

	void Initialize();

	RendererGL();
	~RendererGL();
};
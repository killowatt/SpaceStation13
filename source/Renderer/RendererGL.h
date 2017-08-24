#pragma once
#include "Engine.h"
#include "Shader.h"
#include "Texture.h"
#include "Sprite.h"
#include "SDL/SDL.h"

class Shader;
class Texture;
class Sprite;
class RendererGL : NonCopyable
{
private:
	SDL_Window* Window;
	SDL_GLContext Context;

	Shader* CurrentShader;

public:
	Texture* CreateTexture();
	Sprite* CreateSprite(Texture* texture);

	void Render(Sprite* sprite);

	void SetShader(Shader* shader) { CurrentShader = shader; }

	void Clear() {}
	void SwapBuffers() { SDL_GL_SwapWindow(Window); }

	void Initialize();

	RendererGL();
	~RendererGL();
};
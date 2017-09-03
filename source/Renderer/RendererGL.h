#pragma once
#include "Core.h"
#include "Shader.h"
#include "Texture.h"
#include "Sprite.h"
#include "Camera.h"
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
	Camera* CurrentCamera;

public:
	Texture* CreateTexture();
	Sprite* CreateSprite(Texture* texture);

	void Render(Sprite* sprite);

	void Clear() {}
	void SwapBuffers() { SDL_GL_SwapWindow(Window); }

	void Initialize();

	void SetShader(Shader* shader) { CurrentShader = shader; }
	void SetCamera(Camera* camera) { CurrentCamera = camera; }

	Camera& GetCamera() { return *CurrentCamera; }

	RendererGL();
	~RendererGL();
};
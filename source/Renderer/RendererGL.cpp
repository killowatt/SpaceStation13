#include "RendererGL.h"

#include "GL/glew.h"

Texture* RendererGL::CreateTexture()
{
	Texture* texture = new Texture(this);
	glBindTexture(GL_TEXTURE_2D, texture->GetTextureID()); // We know we just binded it
	// but y not bind it again :^)

	GLubyte image[] = {
		240, 0, 150, 255,
		15, 0, 150, 255,
		15, 0, 150, 255,
		240, 0, 150, 255,
	};
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB8, 2, 2, 0, GL_RGBA, GL_UNSIGNED_BYTE, image);

	return texture;
}

void RendererGL::Render(Sprite* sprite)
{
	glBindTexture(GL_TEXTURE_2D, sprite->GetTexture()->GetTextureID());
}

void RendererGL::Initialize()
{
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 1);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);

	window = SDL_CreateWindow("Space Station 13", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
		1280, 720, SDL_WINDOW_OPENGL);
	if (window == nullptr)
		return; // TODO: error

	if (glewInit() != GLEW_OK)
		return; // TODO: error

	if (SDL_GL_SetSwapInterval(1) != 0)
		return; // TODO: error
}

RendererGL::RendererGL()
{
	window = nullptr;
}
RendererGL::~RendererGL()
{
	if (window)
		SDL_DestroyWindow(window);
}
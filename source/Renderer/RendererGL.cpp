#include "RendererGL.h"

#include "GL/glew.h"

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
}
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
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, 2, 2, 0, GL_RGBA, GL_UNSIGNED_BYTE, image);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST); // TODO: use set in tex
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

	return texture;
}

void RendererGL::Render(Sprite* sprite)
{
	glBindTexture(GL_TEXTURE_2D, sprite->GetTexture()->GetTextureID());
}

void RendererGL::Initialize()
{
	Window = SDL_CreateWindow("Space Station 13", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
		512, 512, SDL_WINDOW_OPENGL);
	if (Window == nullptr)
		return; // TODO: error

	Context = SDL_GL_CreateContext(Window);
	SDL_GL_MakeCurrent(Window, Context);

	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3); // TODO: is this good dad
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);

	glewExperimental = true;
	if (glewInit() != GLEW_OK)
		return; // TODO: error

	if (SDL_GL_SetSwapInterval(1) != 0)
		return; // TODO: error
}

RendererGL::RendererGL()
{
	Window = nullptr;
}
RendererGL::~RendererGL()
{
	if (Window)
		SDL_DestroyWindow(Window);
}
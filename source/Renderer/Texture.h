#pragma once
#include "RendererGL.h"

class Texture
{
private:
	RendererGL* Renderer;
	int TextureID;


public:
	Texture(RendererGL* renderer);
};
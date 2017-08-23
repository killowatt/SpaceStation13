#pragma once
#include "Engine.h"
#include "RendererGL.h"
#include "Texture.h"

class Sprite : NonCopyable
{
private:
	RendererGL* Renderer;
	Texture* Image;

public:

	

	Sprite(RendererGL* renderer, Texture* texture);
	~Sprite();
};
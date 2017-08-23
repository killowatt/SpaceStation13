#pragma once
#include "Engine.h"
#include "RendererGL.h"
#include "Texture.h"

class RendererGL;
class Texture;
class Sprite : NonCopyable
{
private:
	RendererGL* Renderer;
	Texture* Image;

public:
	Texture* GetTexture() { return Image; }

	Sprite(RendererGL* renderer, Texture* texture);
	~Sprite();
};
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

	uint32 VertexArray;
	uint32 VertexBuffer;
	uint32 TexCoordBuffer;

public:
	Texture* GetTexture() { return Image; }

	uint32 GetVertexArrayObject() { return VertexArray; }
	uint32 GetBufferSize();

	Sprite(RendererGL* renderer, Texture* texture);
	~Sprite();
};
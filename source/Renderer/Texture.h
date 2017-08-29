#pragma once
#include "Core.h"
#include "RendererGL.h"

class RendererGL;
class Texture : NonCopyable
{
private:
	RendererGL* Renderer;
	uint32 TextureID;

	uint32 Width;
	uint32 Height;

public:
	uint32 GetTextureID() const { return TextureID; }
	uint32 GetWidth() { return Width; }
	uint32 GetHeight() { return Height; }

	void LoadFromFile(const char* fileName);

	Texture(RendererGL* renderer);
};
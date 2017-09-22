#pragma once
#include "Core.h"
#include "RendererGL.h"

enum class PixelType
{
	RGB,
	Grayscale
};

class RendererGL;
class Texture : NonCopyable
{
private:
	RendererGL* Renderer;
	uint32 TextureID;

	uint32 Width;
	uint32 Height;

	PixelType Type;

public:
	uint32 GetTextureID() const { return TextureID; }
	uint32 GetWidth() { return Width; }
	uint32 GetHeight() { return Height; }

	void SetImage(uint8* pixels, uint32 width, uint32 height, PixelType type);
	//void BlitSubImage(uint8* pixels, uint32 width, uint32 height, uint32 x, uint32 y);
	void LoadFromFile(const char* fileName); // TODO: remove, assign to resource manager class

	Texture(RendererGL* renderer);
};
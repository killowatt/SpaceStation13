#pragma once
#include "Engine.h"
#include "RendererGL.h"

class RendererGL;
class Texture : NonCopyable
{
private:
	RendererGL* Renderer;
	uint32 TextureID;

public:
	uint32 GetTextureID() const { return TextureID; }

	void LoadFromFile(const char* fileName);

	Texture(RendererGL* renderer);
};
#pragma once
#include "Core.h"
#include "RendererGL.h"

class TextRenderer
{
	RendererGL* Renderer;

	std::string Text;

	struct FreeTypeLib;
	FreeTypeLib* FT;

	Texture* TextImage;
	Sprite* TextSprite;

	bool IsValid;
	bool Rendered;

public:
	std::string GetText() const { return Text; }
	void SetText(const std::string& text);

	Texture* GetTexture() { return TextImage; }
	Sprite* GetSprite() { return TextSprite; }

	TextRenderer(RendererGL* renderer, const char* fontPath, uint32 fontSize);
	~TextRenderer();
};
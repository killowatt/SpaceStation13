#pragma once
#include "Core.h"
#include "RendererGL.h"

class Text
{
	RendererGL* Renderer;

	std::string ext;

	struct FreeTypeLib;
	FreeTypeLib* FT;

	Texture* TextImage;
	Sprite* TextSprite;

	bool IsValid;
	bool Rendered;

public:
	void GetText() const;
	void SetText(const std::string& text);

	Texture* GetTexture() { return TextImage; }
	Sprite* GetSprite() { return TextSprite; }

	Text(RendererGL* renderer, const char* fontPath, uint32 fontSize);
	~Text();
};
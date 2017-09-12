#pragma once
#include "Core.h"
#include "RendererGL.h"

class Text
{
	std::string txt;

public:
	void GetText() const;
	void SetText(const std::string& text);

	Text(RendererGL* renderer);
};
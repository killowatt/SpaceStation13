#pragma once
#include "Entity.h"

class SpriteComponent : public Component
{
	std::string Icon;
	std::string IconState;

public:
	SpriteComponent()
	{
		Icon = "";
		IconState = "";
	}
	~SpriteComponent() {}

	void SetIcon(const std::string& filename) { Icon = filename; }

	void Update()
	{
	}
	void Render()
	{
		// Render InternalSprite
	}
};
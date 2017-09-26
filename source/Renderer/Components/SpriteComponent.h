#pragma once
#include "Entity.h"
#include "Sprite.h"

class SpriteComponent : public Component
{
	std::string Icon;
	Sprite* InternalSprite;

public:
	SpriteComponent()
	{

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
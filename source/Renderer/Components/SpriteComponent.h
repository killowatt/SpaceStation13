#pragma once
#include "Entity.h"
#include "Sprite.h"

class SpriteComponent : public Component
{
	Sprite* InternalSprite;

public:
	void Update()
	{
	}
	void Render()
	{
		// Render InternalSprite
	}

	SpriteComponent()
	{

	}
	~SpriteComponent() {}
};
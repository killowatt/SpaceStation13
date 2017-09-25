#pragma once
#include "Entity.h"
#include "Sprite.h"

class SpriteComponent : public Component
{
	Sprite* InternalSprite;

public:
	SpriteComponent() {}
	~SpriteComponent() {}
};
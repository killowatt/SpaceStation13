#pragma once
#include "Entity.h"

struct ControlScheme
{
	// TODO:
};

// Class for player-input to entity
class PlayerController
{
	Entity* ControlledEntity;
	ControlScheme ControlMapping;

public:
	PlayerController();

	void Update();
};
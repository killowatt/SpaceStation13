#pragma once
#include "Core.h"

class GameState
{
public:
	virtual void Initialize() = 0;

	virtual void Update() = 0;
	virtual void Render() = 0;
};
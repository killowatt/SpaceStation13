#include "Engine.h"

#include "Script.h"

#include <iostream>

void Engine::Initialize()
{
	Script x("script.lua");
	
	std::cout << x.GetVariable<std::string>("tile.icon");


	std::getchar();
	// init all systems
	// begin game loop
}
#include <iostream>
#include "Game.h"

#include "Graphics/Shader.h"

void Game::Initialize()
{
	glClearColor(20.0f / 255, 20.0f / 255, 20.0f / 255, 1.0f);


}
void Game::Update()
{

}
void Game::Render()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}
Game::Game() // TODO: this is kinda ugly
{
	if (glfwInit())
	{
		window = glfwCreateWindow(1280, 720, "Space Station 13", nullptr, nullptr);

		if (window)
		{
			glfwMakeContextCurrent(window);
			if (glewInit() == GLEW_OK)
			{
				Initialize();
				while (!glfwWindowShouldClose(window))
				{
					Update();
					Render();
					glfwSwapBuffers(window);
					glfwPollEvents();
				}
			}
		}

		glfwTerminate();
	}
}
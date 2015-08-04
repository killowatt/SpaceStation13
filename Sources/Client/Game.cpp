#include <iostream>
#include "Game.h"

testshader::testshader() 
	: Graphics::Shader()
{
}
testshader::testshader(const char* vert, const char* frag) 
	: Graphics::Shader(vert, frag)
{

}

void Game::Initialize()
{
	glClearColor(20.0f / 255, 20.0f / 255, 20.0f / 255, 1.0f);

	std::ifstream filestream;
	char vertshdr[4096];
	filestream.open("vert.txt");
	if (filestream.is_open())
	{
		while (!filestream.eof())
		{
			filestream >> vertshdr;
			std::cout << vertshdr;
		}
	}
	filestream.close();

	filestream.open("frag.txt");
	char fragshdr[4096];
	if (filestream.is_open())
	{
		while (!filestream.eof())
		{
			filestream >> fragshdr;
			std::cout << fragshdr;
		}
	}
	filestream.close();

	char attr[][128] = { "vertex" };
	shader = testshader(vertshdr, fragshdr);

}
void Game::Update()
{

}
void Game::Render()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glBindVertexArray(vertexArray.VertexArrayObject);
}
Game::Game(GLFWwindow* window) // TODO: this is kinda ugly
{
	Window = window;

	Initialize();
	while (!glfwWindowShouldClose(window))
	{
		Update();
		Render();
		glfwSwapBuffers(window);
		glfwPollEvents();
	}
}
Game::Game()
{
}
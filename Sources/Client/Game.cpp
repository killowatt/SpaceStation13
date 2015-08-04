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

	shader = testshader(vertshdr, fragshdr);
	std::cout << "Vertex Shader Compile Status: " << shader.GetCompileStatus(Graphics::ShaderType::Vertex) << std::endl;
	std::cout << "Fragment Shader Compile Status: " << shader.GetCompileStatus(Graphics::ShaderType::Fragment) << std::endl;

	vertexBuffer = Graphics::VertexBuffer();
	float buff[] = { 0.0f, 1.0f, 1.0f, -1.0f, -1.0f, -1.0f };
	vertexBuffer.SetBufferData(buff, 6, 2);

	unsigned int ind[] = { 0, 1, 2 };
	vertexArray = Graphics::VertexArray();
	vertexArray.AttachBuffer(&vertexBuffer, 0);
	vertexArray.SetIndexBuffer(ind, 3);
}
void Game::Update()
{

}
void Game::Render()
{
	glClear(GL_COLOR_BUFFER_BIT);

	glBindVertexArray(vertexArray.VertexArrayObject);
	glUseProgram(shader.ShaderProgram);

	//glDrawArrays(GL_TRIANGLES, 0, 6);
	glDrawElements(GL_TRIANGLES, vertexArray.GetIndexBufferSize(), GL_UNSIGNED_INT, nullptr);
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
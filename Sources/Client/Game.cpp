#include <iostream>
#include <string>
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

	std::string line = "";
	std::ifstream filestream("vert.txt", std::ios::in);
	std::string vertshdr((std::istreambuf_iterator<char>(filestream)),
		std::istreambuf_iterator<char>());
	filestream.close();

	filestream = std::ifstream("frag.txt", std::ios::in);
	std::string fragshdr((std::istreambuf_iterator<char>(filestream)),
		std::istreambuf_iterator<char>());
	filestream.close();

	char const* vs = vertshdr.c_str();
	char const* fs = fragshdr.c_str();

	shader = testshader(vs, fs);

	std::cout << "GL Error State: " << glGetError() << std::endl;
	std::cout << "Vertex Shader Compile Status: " << shader.GetCompileStatus(Graphics::ShaderType::Vertex) << std::endl;
	std::cout << "Fragment Shader Compile Status: " << shader.GetCompileStatus(Graphics::ShaderType::Fragment) << std::endl;
	std::cout << "Vertex Shader Compile Log:" << std::endl << shader.GetCompileLog(Graphics::ShaderType::Vertex) << std::endl;
	std::cout << "GL Error State: " << glGetError() << std::endl;
	std::cout << "Fragment Shader Compile Log:" << std::endl << shader.GetCompileLog(Graphics::ShaderType::Fragment) << std::endl;

	vertexBuffer = Graphics::VertexBuffer();
	float buff[] = { 0.0f, 1.0f, 1.0f, -1.0f, -1.0f, -1.0f };
	vertexBuffer.SetBufferData(buff, 6, 2);

	//std::cout << "GL Error State: " << glGetError() << std::endl;

	unsigned int ind[] = { 0, 1, 2 };
	vertexArray = Graphics::VertexArray();
	vertexArray.AttachBuffer(&vertexBuffer, 0);
	vertexArray.SetIndexBuffer(ind, 3);

	std::cout << "GL Error State: " << glGetError() << std::endl;
	std::cout << "GL Error State: " << glGetError() << std::endl;
	std::cout << "GL Error State: " << glGetError() << std::endl;
	std::cout << "GL Error State: " << glGetError() << std::endl;
	std::cout << "GL Error State: " << glGetError() << std::endl;
	std::cout << "GL Error State: " << glGetError() << std::endl;
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
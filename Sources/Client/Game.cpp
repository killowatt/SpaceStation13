#include <iostream>
#include <string>
#include "Game.h"

void testshader::Initialize()
{
	modelLocation = glGetUniformLocation(ShaderProgram, "Model");
	projectionLocation = glGetUniformLocation(ShaderProgram, "Projection");
	viewLocation = glGetUniformLocation(ShaderProgram, "View");

	glUniformMatrix4fv(modelLocation, 1, false, &Model[0][0]);
	glUniformMatrix4fv(projectionLocation, 1, false, &Projection[0][0]);
	glUniformMatrix4fv(viewLocation, 1, false, &View[0][0]);

	TextureLocation = glGetUniformLocation(ShaderProgram, "Texture");
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, Texture->TextureID);
	glUniform1i(TextureLocation, 0);
}
void testshader::Update()
{
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, Texture->TextureID);
	glUniform1i(TextureLocation, 0);
}
testshader::testshader() 
	: Graphics::Shader()
{
}
testshader::testshader(const char* vert, const char* frag, Graphics::Texture* texture) 
	: Graphics::Shader(vert, frag)
{
	Texture = texture;
	glm::mat4 m1 = glm::translate(glm::mat4(1.0), glm::vec3(640.0f, 360.0f, 0.0f));
	Model = glm::scale(m1, glm::vec3(150.0f, 150.0f, 150.0f));
	View = glm::translate(glm::mat4(1.0), glm::vec3(0.0f, 0.0f, 0.0f));
	Projection = glm::ortho(0.0f, 1280.0f, 720.0f, 0.0f);
}

void Game::Initialize()
{
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
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

	std::vector<unsigned char> image;
	unsigned int width, height;
	lodepng::decode(image, width, height, "texture.png");

	unsigned char* pixlz = &image[0];

	texture = new Graphics::Texture();
	texture->SetTexture(pixlz, image.size(), width, height, true);

	shader = testshader(vs, fs, texture);
	

	std::cout << "GL Error State: " << glGetError() << std::endl;
	std::cout << "Vertex Shader Compile Status: " << shader.GetCompileStatus(Graphics::ShaderType::Vertex) << std::endl;
	std::cout << "Fragment Shader Compile Status: " << shader.GetCompileStatus(Graphics::ShaderType::Fragment) << std::endl;
	std::cout << "Vertex Shader Compile Log:" << std::endl << shader.GetCompileLog(Graphics::ShaderType::Vertex) << std::endl;
	std::cout << "GL Error State: " << glGetError() << std::endl;
	std::cout << "Fragment Shader Compile Log:" << std::endl << shader.GetCompileLog(Graphics::ShaderType::Fragment) << std::endl;

	vertexBuffer = Graphics::VertexBuffer();
	float buff[] = { -1, 1, 1, 1, -1, -1, 1, -1 };
	vertexBuffer.SetBufferData(buff, 8, 2);

	vertexBufferTexCoord = new Graphics::VertexBuffer();
	float txcbuff[] = { 0, 1, 1, 1, 0, 0, 1, 0 };
	vertexBufferTexCoord->SetBufferData(txcbuff, 8, 2);

	//std::cout << "GL Error State: " << glGetError() << std::endl;

	unsigned int ind[] = { 0, 1, 2, 2, 1, 3 };
	vertexArray = Graphics::VertexArray();
	vertexArray.AttachBuffer(&vertexBuffer, 0);
	vertexArray.AttachBuffer(vertexBufferTexCoord, 1);
	vertexArray.SetIndexBuffer(ind, 6);

	std::cout << "GL Error State: " << glGetError() << std::endl;
	std::cout << "GL Error State: " << glGetError() << std::endl;
	std::cout << "GL Error State: " << glGetError() << std::endl;
	std::cout << "GL Error State: " << glGetError() << std::endl;
	std::cout << "GL Error State: " << glGetError() << std::endl;
	std::cout << "GL Error State: " << glGetError() << std::endl;

	glUseProgram(shader.ShaderProgram);
	shader.Initialize();
}
void Game::Update()
{

}
void Game::Render()
{
	glClear(GL_COLOR_BUFFER_BIT);

	glBindVertexArray(vertexArray.VertexArrayObject);
	glUseProgram(shader.ShaderProgram);

	//shader.Update();
	
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
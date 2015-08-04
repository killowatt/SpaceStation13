#ifndef GAME_HEADER
#define GAME_HEADER

#include <GLFW/glfw3.h>
#include <GL/glew.h>

// temp
#include <fstream>
#include "Graphics/Shader.h"
#include "Graphics/VertexArray.h"
#include "Graphics/VertexBuffer.h"


class testshader : public Graphics::Shader
{
public:
	testshader();
	testshader(const char* vert, const char* frag);
};

class Game
{
public:
	GLFWwindow* Window;

	testshader shader;
	Graphics::VertexArray vertexArray;
	Graphics::VertexBuffer vertexBuffer;

	Game(GLFWwindow* window);
	Game();

private:
	void Initialize();
	void Update();
	void Render();
};

#endif
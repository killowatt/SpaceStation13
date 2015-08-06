#ifndef GAME_HEADER
#define GAME_HEADER

#include <GLFW/glfw3.h>
#include <GL/glew.h>

// temp
#include <fstream>
#include "Graphics/Shader.h"
#include "Graphics/VertexArray.h"
#include "Graphics/VertexBuffer.h"
#include "Graphics/Texture.h" // TODO: make one big header B)

#include <iostream>
#include "TempPNG/lodepng.h"

#include "glm/mat4x4.hpp"
#include "glm/gtc/matrix_transform.hpp"

class testshader : public Graphics::Shader
{
public:
	int TextureLocation;
	Graphics::Texture* Texture;

	int modelLocation;
	int projectionLocation;
	int viewLocation;

	void Initialize();
	void Update();

	testshader();
	testshader(const char* vert, const char* frag, Graphics::Texture* texture);
};

class Game
{
public:
	GLFWwindow* Window;

	testshader shader;
	Graphics::VertexBuffer vertexBuffer;
	Graphics::VertexBuffer* vertexBufferTexCoord;
	Graphics::VertexArray vertexArray;
	Graphics::Texture* texture;

	Game(GLFWwindow* window);
	Game();

private:
	void Initialize();
	void Update();
	void Render();
};

#endif
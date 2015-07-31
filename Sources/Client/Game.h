#ifndef GAME_HEADER
#define GAME_HEADER

#include <GLFW/glfw3.h>
#include <GL/glew.h>

class Game
{
public:
	GLFWwindow* window;

	Game();

private:
	void Initialize();
	void Update();
	void Render();
};

#endif
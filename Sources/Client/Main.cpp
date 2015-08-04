#include <GLFW/glfw3.h>
#include <GL/glew.h>

#include "Game.h"

int main()
{
	glfwInit();
	GLFWwindow* window = glfwCreateWindow(1280, 720, "Space Station 13", nullptr, nullptr);

	if (window)
	{
		glfwMakeContextCurrent(window);
		if (glewInit() == GLEW_OK)
		{
			Game game = Game(window);
		}
	}

	glfwTerminate();
	return 0;
}
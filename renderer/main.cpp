#include<iostream>
#include<glad/glad.h>
#include<GLFW/glfw3.h>

int main() 
{
	int WINDOW_WIDTH;
	int WINDOW_HEIGHT;
	float CLEAR_RED;
	float CLEAR_GREEN;
	float CLEAR_BLUE;
	float CLEAR_ALPHA;

	WINDOW_WIDTH = 800;
	WINDOW_HEIGHT = 800;
	CLEAR_RED = 0.07f;
	CLEAR_GREEN = 0.13f;
	CLEAR_BLUE = 0.17f;
	CLEAR_ALPHA = 1.0f;

	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	GLFWwindow* window = glfwCreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "sombrosa", NULL, NULL);
	
	if (window == NULL)
	{
		std::cout << " Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}

	glfwMakeContextCurrent(window);
	gladLoadGL();	
	glViewport(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT);
	glClearColor(CLEAR_RED, CLEAR_GREEN, CLEAR_BLUE, CLEAR_ALPHA);
	
	while (!glfwWindowShouldClose(window))
	{
		glfwPollEvents();
	}

	glfwTerminate();
	return 0;
};
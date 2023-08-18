//  MATHCODED.com 
//		est 2021
// Sombrosa Renderer
//		began on 8-18-2023
// 
// 
//  Author: Jonathan P. Wolfe 
//


#include<iostream>
#include<glad/glad.h>
#include<GLFW/glfw3.h>


int main()
{	
	// OpenGL specs
	int OPENGL_VERSION_MAJOR=3;
	int OPENGL_VERSION_MINOR=3;

	// Variables
	const char* WINDOW_NAME;
	int WINDOW_WIDTH;
	int WINDOW_HEIGHT;
	float CLEAR_RED;
	float CLEAR_GREEN;
	float CLEAR_BLUE;
	float CLEAR_ALPHA;

	// Initializoing variabled to defaults.
	// (need to make these accessible and modifiable, etc)
	WINDOW_NAME = "Sombrosa";
	WINDOW_WIDTH = 800;
	WINDOW_HEIGHT = 800;
	CLEAR_RED = 0.07f;
	CLEAR_GREEN = 0.13f;
	CLEAR_BLUE = 0.17f;
	CLEAR_ALPHA = 1.0f;
	
		
	// Initialize GLFW
	glfwInit();

	// Set OpenGL version.
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, OPENGL_VERSION_MAJOR);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, OPENGL_VERSION_MINOR
	);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	// Create <window> Window object.
	// return -1 and exit if fails (need to fix later so that it throws an error. also handle error)
	//
	GLFWwindow* window = glfwCreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_NAME, NULL, NULL);
	if (window == NULL)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}

	// set <window> to active Window
	glfwMakeContextCurrent(window);
	gladLoadGL();

	//set pixel viewport (0,0),(WINDOW_WIDTH,0),(WINDOW_HEIGHT,0),(WINDOW_WIDTH,WINDOW_HEIGHT)
	glViewport(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT);

	// Clear color creation and then swap buffer back to paint color.
	glClearColor(CLEAR_RED, CLEAR_GREEN, CLEAR_BLUE, CLEAR_ALPHA);
	glClear(GL_COLOR_BUFFER_BIT);
	glfwSwapBuffers(window);

	// Keep Window open, polling.
	// poll should know when to Exit, redraw, resize, etc.
	while (!glfwWindowShouldClose(window))
	{
		glfwPollEvents();
	}


	
	//Somehow exit here.

	// Terminate GLFW before closing
	glfwTerminate();

	//return from Main()
	return 1;
};

//  MATHCODED.com 
//		est 2021
// Sombrosa Renderer
//		began on 8-18-2023
// 
// 
//  Author: Jonathan P. Wolfe 
//          
//


#include<iostream>
#include "../Libraries/include/glad/gl.h"
#include "../Libraries/include/GLFW/glfw3.h"

#include"./Headers/shaderClass.h"
#include"./Headers/VAO.h"
#include"./Headers/VBO.h"
#include"./Headers/EBO.h"

;

// Opens a GFLW Window until terminated.  
//	defaults used:
// OpenGL Version: 4.6
// Name:           Sombrosa
// Resolution:     800x800
// Clear:		   r:0.07, g:0.13, b:0.17, a:1.00
// 
//
//
int main()
{
	// OpenGL specs
	int OPENGL_VERSION_MAJOR = 4;
	int OPENGL_VERSION_MINOR = 6;

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

	//Create Vertices.
	GLfloat vertices[] =
	{
		-0.4f,-0.5f * float(sqrt(3)) / 3, 0.0f,
		0.4f,-0.5f * float(sqrt(3)) / 3, 0.0f,
		0.0f,0.5f * float(sqrt(3)) * 2 / 3, 0.0f,
		0.0f, 0.1f * float(sqrt(3))*2 / 3, 0.0f,
	};

	GLuint indices[] = {
		0,2,3,
		1,2,3
	};

	// Create <window> Window object.
	// terminal output of if window is created.  if not, terminates and
	// return -1 and exit if fails (need to fix later so that it throws an error. also handle error)
	//
	GLFWwindow* window = glfwCreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_NAME, NULL, NULL);
	if (window)
	{
		std::cout << "Created GLFW window" << std::endl;
	}
	else {
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}

	// set <window> to active Window
	glfwMakeContextCurrent(window);
	gladLoadGL(glfwGetProcAddress);

	//set pixel viewport (0,0),(WINDOW_WIDTH,0),(0,WINDOW_HEIGHT),(WINDOW_WIDTH,WINDOW_HEIGHT)
	glViewport(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT);

	

	// Generates Shader object using shaders defualt.vert and default.frag
	Shader shaderProgram("../Shaders/default.vert", "../Shaders/default.frag");



	// Generates Vertex Array Object and binds it
	VAO VAO1;
	VAO1.Bind();

	// Generates Vertex Buffer Object and links it to vertices
	VBO VBO1(vertices, sizeof(vertices));
	// Generates Element Buffer Object and links it to indices
	EBO EBO1(indices, sizeof(indices));

	// Links VBO to VAO
	VAO1.LinkVBO(VBO1, 0);
	// Unbind all to prevent accidentally modifying them
	VAO1.Unbind();
	VBO1.Unbind();
	EBO1.Unbind();



	// Main while loop
	while (!glfwWindowShouldClose(window))
	{
		// Specify the color of the background
		glClearColor(CLEAR_RED, CLEAR_GREEN, CLEAR_BLUE, CLEAR_ALPHA);
		// Clean the back buffer and assign the new color to it
		glClear(GL_COLOR_BUFFER_BIT);
		// Tell OpenGL which Shader Program we want to use
		shaderProgram.Activate();
		// Bind the VAO so OpenGL knows to use it
		VAO1.Bind();
		// Draw primitives, number of indices, datatype of indices, index of indices
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
		// Swap the back buffer with the front buffer
		glfwSwapBuffers(window);
		// Take care of all GLFW events
		glfwPollEvents();
	}



	// Delete all the objects we've created
	VAO1.Delete();
	VBO1.Delete();
	EBO1.Delete();
	shaderProgram.Delete();

	//Somehow exit here.

	// Delete window before ending the program
	glfwDestroyWindow(window);
	// Terminate GLFW before ending the program
	glfwTerminate();
	return 0;
};

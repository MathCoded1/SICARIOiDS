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
#include"./Headers/ship.h"
#include"./Headers/asteroid.h"

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
	WINDOW_NAME = "SICARIOiDS";
	WINDOW_WIDTH = 800;
	WINDOW_HEIGHT = 800;
	CLEAR_RED = 0.00f;
	CLEAR_GREEN = 0.00f;
	CLEAR_BLUE = 0.00f;
	CLEAR_ALPHA = 1.0f;


	// Initialize GLFW
	glfwInit();

	// Set OpenGL version.
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, OPENGL_VERSION_MAJOR);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, OPENGL_VERSION_MINOR
	);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);




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
	Ship ship;
	// Generates Vertex Array Object and binds it
	VAO VAO1;
	VAO1.Bind();

	// Generates Vertex Buffer Object and links it to vertices
	VBO VBO1(ship.vertices, sizeof(ship.vertices));
	// Generates Element Buffer Object and links it to indices
	EBO EBO1(ship.indices, sizeof(ship.indices));

	// Links VBO attributes such as coordinates and colors to VAO
	VAO1.LinkAttrib(VBO1, 0, 3, GL_FLOAT, 6 * sizeof(float), (void*)0);
	VAO1.LinkAttrib(VBO1, 1, 3, GL_FLOAT, 6 * sizeof(float), (void*)(3 * sizeof(float)));
	// Unbind all to prevent accidentally modifying them
	VAO1.Unbind();
	VBO1.Unbind();
	EBO1.Unbind();

	// Gets ID of uniform called "scale"
	GLuint uniID = glGetUniformLocation(shaderProgram.ID, "scale");
	Asteroid asteroid(0.75f,0.75f,0.15);
	VAO VAO2;
	VAO2.Bind();

	Shader AProgram("../Shaders/circle.vert", "../Shaders/circle.frag");

	// Generates Vertex Buffer Object and links it to vertices
	VBO VBO2(asteroid.vertices, sizeof(asteroid.vertices));
	// Generates Element Buffer Object and links it to indices
	;

	// Links VBO attributes such as coordinates and colors to VAO
	VAO2.LinkAttrib(VBO2, 0, 2, GL_FLOAT, 5 * sizeof(float), (void*)0);
	VAO2.LinkAttrib(VBO2, 1, 2, GL_FLOAT, 5 * sizeof(float), (void*)(2 * sizeof(float)));
	// Unbind all to prevent accidentally modifying them
	VAO2.Unbind();
	VBO2.Unbind();
	;
	GLuint uniID2 = glGetUniformLocation(AProgram.ID, "scale");
	// Main while loop
	while (!glfwWindowShouldClose(window))
	{
		// Specify the color of the background
		glClearColor(CLEAR_RED, CLEAR_GREEN, CLEAR_BLUE, CLEAR_ALPHA);
		// Clean the back buffer and assign the new color to it
		glClear(GL_COLOR_BUFFER_BIT);
		// Tell OpenGL which Shader Program we want to use
		shaderProgram.Activate();
		// Assigns a value to the uniform; NOTE: Must always be done after activating the Shader Program
		glUniform1f(uniID, 0.5f);
		// Bind the VAO so OpenGL knows to use it
		VAO1.Bind();
		// Draw primitives, number of indices, datatype of indices, index of indices
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
		shaderProgram.Deactivate();
		AProgram.Activate();
		glUniform1f(uniID2, 0.5f);
		VAO2.Bind();
		glDrawElements(GL_TRIANGLE_FAN, 8, GL_UNSIGNED_INT, asteroid.indices);
		AProgram.Deactivate();
		// Swap the back buffer with the front buffer
		glfwSwapBuffers(window);
		// Take care of all GLFW events
		glfwPollEvents();
	}



	// Delete all the objects we've created
	VAO1.Delete();
	VBO1.Delete();
	EBO1.Delete();
	VAO2.Delete();
	VBO2.Delete();

	shaderProgram.Delete();
	AProgram.Delete();
	// Delete window before ending the program
	glfwDestroyWindow(window);
	// Terminate GLFW before ending the program
	glfwTerminate();
	return 0;
};

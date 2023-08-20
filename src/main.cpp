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

//Vertex Shader.
const char* vertexShaderSource = "#version 330 core\n"

"layout (location = 0) in vec3 iPos;\n"

"void main()\n"
"{\n"
"   gl_Position = vec4(iPos.x, iPos.y, iPos.z, 1.0);\n"
"}\0";

//Fragment Shader
const char* fragmentShaderSource = "#version 330 core\n"
"out vec4 FragColor;\n"
"void main()\n"
"{\n"
"  FragColor = vec4( 0.8f, 0.8f ,0.02f, 1.0f);\n"
"}\n\0";

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
	int OPENGL_VERSION_MAJOR = 3;
	int OPENGL_VERSION_MINOR = 3;

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
		-0.5f,-0.5f *float(sqrt(3))/3, 0.0f,
		0.5f,-0.5f*float(sqrt(3))/3, 0.0f,
		0.0f,0.5f*float(sqrt(3))*2/3, 0.0f,
		
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

	//Compile Vertex Shader
	GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
	glCompileShader(vertexShader);
	
	//Compile Fragment Shader
	GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
	glCompileShader(fragmentShader);
	
	//Load Shaders into Shader Program
	GLuint shaderProgram = glCreateProgram();
	glAttachShader(shaderProgram, vertexShader);
	glAttachShader(shaderProgram, fragmentShader);
	glLinkProgram(shaderProgram);

	//Delete Shaders
	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);
	
	//Create Vertex Bindings.
	GLuint VAO, VBO;
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	glBindVertexArray(VAO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);



	// Clear color creation and then swap buffer back to paint color.
	glClearColor(CLEAR_RED, CLEAR_GREEN, CLEAR_BLUE, CLEAR_ALPHA);
	glClear(GL_COLOR_BUFFER_BIT);
	glfwSwapBuffers(window);
	glUseProgram(0);
	// Keep Window open, polling.
	// poll should know when to Exit, redraw, resize, etc.
	while (!glfwWindowShouldClose(window))
	{
		glClearColor(CLEAR_RED, CLEAR_GREEN, CLEAR_BLUE, CLEAR_ALPHA);
		glClear(GL_COLOR_BUFFER_BIT);
		//Draw

		glUseProgram(shaderProgram);
		glBindVertexArray(VAO);
		glDrawArrays(GL_TRIANGLES, 0, 3);
		//Flip to Back Buffer.
		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	//Delete Vertex arrays and Buffers.
	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);
	glDeleteProgram(shaderProgram);
	
	//Somehow exit here.

	// Terminate GLFW before closing
	glfwTerminate();

	//return from Main()
	return 0;
};


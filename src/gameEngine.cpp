#include "Headers/gameEngine.h"
#include "Headers/asteroid.h"
#include "Headers/ship.h"



GameEngine::GameEngine() 

{
	// Initialize GLFW
	glfwInit();

	// Set OpenGL version.
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, OPENGL_VERSION_MAJOR);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, OPENGL_VERSION_MINOR);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);


	// Create <window> Window object.
	// terminal output of if window is created.  if not, terminates and
	// return -1 and exit if fails (need to fix later so that it throws an error. also handle error)
	//
GLFWwindow* w = glfwCreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_NAME, NULL, NULL);
	if (w)
	{
		std::cout << "Created GLFW window" << std::endl;
	}
	else {
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
	}
	// set <window> to active Window
	window = w;
	glfwMakeContextCurrent(window);
	gladLoadGL(glfwGetProcAddress);
	//set pixel viewport (0,0),(WINDOW_WIDTH,0),(0,WINDOW_HEIGHT),(WINDOW_WIDTH,WINDOW_HEIGHT)
	glViewport(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT);

	Asteroid a(0.75f, 0.75f, 0.1f);
	asteroids.push_back(a);



	// Generates Shader object using shaders defualt.vert and default.frag
	Ship s;
	ship = s;
}
void GameEngine::initializeGraphics() {



	Shader shipShader("../Shaders/ship.vert", "../Shaders/ship.frag");
	Shader asteroidShader("../Shaders/asteroid.vert", "../Shaders/asteroid.frag");
	rendererItems.shaders.push_back(shipShader);
	rendererItems.shaders.push_back(asteroidShader);
	// Generates Vertex Array Object and binds it
}
	void GameEngine::render() {

	VAO VAO1;
	rendererItems.VAOs.push_back(VAO1);
	rendererItems.VAOs[0].Bind();

	// Generates Vertex Buffer Object and links it to vertices
	VBO VBO1(ship.vertices, sizeof(ship.vertices));
	// Generates Element Buffer Object and links it to indices
	EBO EBO1(ship.indices, sizeof(ship.indices));
	rendererItems.VBOs.push_back(VBO1);
	rendererItems.EBOs.push_back(EBO1);
	// Links VBO attributes such as coordinates and colors to VAO
	rendererItems.VAOs[0].LinkAttrib(rendererItems.VBOs[0], 0, 3, GL_FLOAT, 5 * sizeof(float), (void*)0);
	rendererItems.VAOs[0].LinkAttrib(rendererItems.VBOs[0], 1, 3, GL_FLOAT, 5 * sizeof(float), (void*)(2 * sizeof(float)));
	// Unbind all to prevent accidentally modifying them
	rendererItems.VAOs[0].Unbind();
	rendererItems.VBOs[0].Unbind();
	rendererItems.EBOs[0].Unbind();

	// Gets ID of uniform called "scale"
	GLuint uniID = glGetUniformLocation(rendererItems.shaders[0].ID, "scale");
	VAO VAO2;
	rendererItems.VAOs.push_back(VAO2);
	
	rendererItems.VAOs[1].Bind();

	// Generates Vertex Buffer Object and links it to vertices
	VBO VBO2(asteroids[0].vertices, sizeof(asteroids[0].vertices));
	// Generates Element Buffer Object and links it to indices
	
	rendererItems.VBOs.push_back(VBO2);
	// Links VBO attributes such as coordinates and colors to VAO
	rendererItems.VAOs[1].LinkAttrib(rendererItems.VBOs[1], 0, 2, GL_FLOAT, 5 * sizeof(float), (void*)0);
	rendererItems.VAOs[1].LinkAttrib(rendererItems.VBOs[1], 1, 2, GL_FLOAT, 5 * sizeof(float), (void*)(2 * sizeof(float)));
	// Unbind all to prevent accidentally modifying them
	rendererItems.VAOs[1].Unbind();
	rendererItems.VBOs[1].Unbind();
	
	GLuint uniID2 = glGetUniformLocation(rendererItems.shaders[1].ID, "scale");
}
void GameEngine::run() {
	
	// Main while loop
	while (!glfwWindowShouldClose(window))
	{
		getInput(window);
		render();
		// Specify the color of the background
		glClearColor(CLEAR_RED, CLEAR_GREEN, CLEAR_BLUE, CLEAR_ALPHA);
		// Clean the back buffer and assign the new color to it
		glClear(GL_COLOR_BUFFER_BIT);
		// Tell OpenGL which Shader Program we want to use
		rendererItems.shaders[0].Activate();
		// Assigns a value to the uniform; NOTE: Must always be done after activating the Shader Program
		glUniform1f(uniID, 0.5f);
		// Bind the VAO so OpenGL knows to use it
		rendererItems.VAOs[0].Bind();
		// Draw primitives, number of indices, datatype of indices, index of indices
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
		rendererItems.shaders[0].Deactivate();
		rendererItems.shaders[1].Activate();
		glUniform1f(uniID2, 0.5f);
		rendererItems.VAOs[1].Bind();
		glDrawElements(GL_TRIANGLE_FAN, 8, GL_UNSIGNED_INT, asteroids[0].indices);
		rendererItems.shaders[1].Deactivate();
		// Swap the back buffer with the front buffer
		glfwSwapBuffers(window);
		// Take care of all GLFW events
		glfwPollEvents();

		// Delete all the objects we've created
		for (VAO vao : rendererItems.VAOs)
			vao.Delete();
		for (VBO vbo : rendererItems.VBOs)
			vbo.Delete();
		for (EBO ebo : rendererItems.EBOs)
			ebo.Delete();
	}
}
void GameEngine::close() {
	for (Shader shader : rendererItems.shaders)
		shader.Delete();
	// Delete window before ending the program
	glfwDestroyWindow(window);
	// Terminate GLFW before ending the program
	glfwTerminate();
}

void GameEngine::getInput(GLFWwindow* window)
{
	Input input;
	// Check if the Escape key is pressed
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(window, true);
	if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
		input.W = true;
	if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
		input.A = true;
	if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
		input.S = true;
	if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
		input.D = true;
	if (glfwGetKey(window, GLFW_KEY_LEFT_CONTROL) == GLFW_PRESS || glfwGetKey(window, GLFW_KEY_RIGHT_CONTROL) == GLFW_PRESS)
		input.ctrl = true;
	if (glfwGetKey(window, GLFW_KEY_SPACE) == GLFW_PRESS)
		input.Space = true;

	processInput(input);
}
void GameEngine::processInput(Input input) {
	if (input.W == true)
		ship.centerY += .001f;
	if (input.S == true)
		ship.centerY -= .001f;
	if (input.A == true)
		ship.centerX -= .001f;
	if (input.D == true)
		ship.centerX += .001f;
	ship.getVertices();

}
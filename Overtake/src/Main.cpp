// Open GL
#include <GL/glew.h>
#include <GLFW/glfw3.h>

// Open GL specific math lib
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"

// Standard libs
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

// Abstraction classes for Open GL
#include "IndexBuffer.h"
#include "VertexBuffer.h"
#include "VertexArray.h"
#include "Shader.h"
#include "Renderer.h"

// Game Logic classes
#include "CarManager.h"
#include "Player.h"
#include "Background.h"
#include "LoseScreen.h"
#include "Texture.h"


// Global variables
GLFWwindow* window;
int monitorWidth, monitorHeight, windowWidth, windowHeight;

Background background;
CarManager* carManager = new CarManager();
Player player(carManager);
LoseScreen loseScreen;
bool alive = true;

int initWindow() {
	/* Initialize the library */
	if (!glfwInit())
		return -1;
	windowWidth = 1600;
	windowHeight = 900;

	glfwGetMonitorWorkarea(glfwGetPrimaryMonitor(), nullptr, nullptr, &monitorWidth, &monitorHeight);

	/* Create a windowed mode window and its OpenGL context */
	window = glfwCreateWindow(windowWidth, windowHeight, "Overtake", NULL, NULL);
	if (!window)
	{
		glfwTerminate();
		return -1;
	}
	
	glfwSetWindowPos(window, (monitorWidth - windowWidth)/2, (monitorHeight - windowHeight)/2);

	/* Make the window's context current */
	glfwMakeContextCurrent(window);


	return 0;
}

void update() {

	if (alive) {

	// Update all positions here!
	background.update();
	carManager->update();
	player.update();
	alive = player.isAlive();

	}
	else {
		loseScreen.update();
	}
	

	 
}

void render(Renderer renderer, Shader shader) {
	
	if (alive) {

		// Clear the screen
		renderer.clear();

		background.render(renderer, shader);
		carManager->render(renderer, shader);
		player.render(renderer, shader);

	}
	else {
		renderer.clear();
		loseScreen.render(renderer, shader);
	}

}

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
		
		glfwSetWindowShouldClose(window, GLFW_TRUE);
	}
	// Kill button
	if (key == GLFW_KEY_K && action == GLFW_PRESS) {
		alive = false;
	}
	// Player movement up
	if (key == GLFW_KEY_UP) {
		if (action == GLFW_PRESS) {
			player.setYMove(1);
		}
		else if (action == GLFW_RELEASE) {
			player.setYMove(0);
		}
	}
	
	// Player movement down
	if (key == GLFW_KEY_DOWN) {
		if (action == GLFW_PRESS) {
			player.setYMove(-1);
		}
		else if (action == GLFW_RELEASE) {
			player.setYMove(0);
		}
	}

	// Player movement left
	if (key == GLFW_KEY_LEFT) {
		if (action == GLFW_PRESS) {
			player.setXMove(-1);
		}
		else if (action == GLFW_RELEASE) {
			player.setXMove(0);
		}
	}

	// Player movement right
	if (key == GLFW_KEY_RIGHT) {
		if (action == GLFW_PRESS) {
			player.setXMove(1);
		}
		else if (action == GLFW_RELEASE) {
			player.setXMove(0);
		}
	}


}

int main(void)
{
	

	if (initWindow() == -1) {
		return -1;
	}

	if (glewInit() != GLEW_OK) {
		std::cout << "Error with glew" << std::endl;
		return -1;
	}

	std::cout << glGetString(GL_VERSION) << std::endl;

	glfwSetKeyCallback(window, key_callback );
	
	// Projection matrix
	glm::mat4 projMat = glm::ortho(-windowWidth / 2.0f, windowWidth / 2.0f, -windowHeight / 2.0f, windowHeight / 2.0f, -1.0f, 1.0f);

	// Shaders
	Shader shader("res/shaders/Basic.shader");
	shader.bind();
	
	// Texture
	
	/*	WIP
	Texture carTexture("res/PixelCar.png");
	carTexture.bind();
	shader.setUniform1i("u_Texture", 0);

	*/

	// Change projection matrix in shader
	shader.setUniformMat4f("mVP", projMat);

	//initGameValues();
	Renderer renderer;

	/* Loop until the user closes the window */
	while (!glfwWindowShouldClose(window))
	{
		
			/* Update here */
			update();

			/*//Buffer objects
			VertexBuffer vb(positions, 48 * sizeof(float));
			VertexBufferLayout layout;
			layout.Push<float>(2);
			va.addBuffer(vb, layout);
			*/

			render(renderer, shader);


			/* Swap front and back buffers */
			glfwSwapBuffers(window);


			/* Poll for and process events */
			glfwPollEvents();
			
	}

	std::cout << "You crashed." << std::endl;
	
	glfwTerminate();
	return 0;
}



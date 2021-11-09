#include "CarManager.h"
#include <iostream>
#include <stdlib.h>



CarManager::CarManager() {
	// Keeps track on which "lane" the current car is driving
	float laneYPosition = -400;
	float xStartPosition = 0;
	float speed = 0;
	for (int i = 0; i < 6; i++) {
		xStartPosition = 850 + rand() % 300;
		speed = rand() % 5 + 3;

		cars.push_back({ xStartPosition, laneYPosition, 200, 100, speed });

		/*std::cout << "Car " << i << ": " << std::endl << "	startPosition: " << xStartPosition << std::endl
			<< "	laneYPosition: " << laneYPosition << std::endl
			<< "	speed: " << speed << std::endl;
			*/
		laneYPosition += 140;
		
	}

	// Updating values in the array
	for (int i = 0; i < cars.size(); i++) {

		// Vertex one
		carPositions[i * 8 + 0] = cars[i].posX;
		carPositions[i * 8 + 1] = cars[i].posY;

		// Vertex two
		carPositions[i * 8 + 2] = cars[i].posX + cars[i].width;
		carPositions[i * 8 + 3] = cars[i].posY;

		// Vertex three
		carPositions[i * 8 + 4] = cars[i].posX + cars[i].width;
		carPositions[i * 8 + 5] = cars[i].posY + cars[i].height;
		
		// Vertex four
		carPositions[i * 8 + 6] = cars[i].posX;
		carPositions[i * 8 + 7] = cars[i].posY + cars[i].height;

	}
}

CarManager::~CarManager() {
	cars.clear();
	cars.shrink_to_fit();
}

void CarManager::update()
{
	// Loop through each car
	for (int i = 0; i < cars.size(); i++) {

		cars[i].update();
		

		// Updating values in the array
		// Vertex one
		carPositions[i * 16 + 0] = cars[i].posX;
		carPositions[i * 16 + 1] = cars[i].posY;
						 
		carPositions[i * 16 + 2] = 0.0f;
		carPositions[i * 16 + 3] = 0.0f;
						 
		// Vertex two	 
		carPositions[i * 16 + 4] = cars[i].posX + cars[i].width;
		carPositions[i * 16 + 5] = cars[i].posY;
						 
		carPositions[i * 16 + 6] = 1.0f;
		carPositions[i * 16 + 7] = 0.0f;
						 
		// Vertex three	 
		carPositions[i * 16 + 8] = cars[i].posX + cars[i].width;
		carPositions[i * 16 + 9] = cars[i].posY + cars[i].height;
						 
		carPositions[i * 16 + 10] = 1.0f;
		carPositions[i * 16 + 11] = 1.0f;
						 
		// Vertex four	 
		carPositions[i * 16 + 12] = cars[i].posX;
		carPositions[i * 16 + 13] = cars[i].posY + cars[i].height;

		carPositions[i * 16 + 14] = 0.0f;
		carPositions[i * 16 + 15] = 1.0f;
	}
}

void CarManager::render(Renderer renderer, Shader shader)
{

	// VAO
	VertexArray va;

	//Buffer objects
	VertexBuffer vb(carPositions, carVertexCount * sizeof(float));
	VertexBufferLayout layout;
	layout.Push<float>(2);
	layout.Push<float>(2);

	va.addBuffer(vb, layout);
	IndexBuffer ib(carIndices, carIndexCount);
	//shader.setUniform1i("u_colorType", 1);
	shader.setUniform4f("uColor", 0.0f, 0.7f, 0.3f, 1.0f);

	renderer.draw(va, ib, shader);
}


	


void car::update()
{

	if (posX + width < -800) {
		posX = 1000;
		speed = rand() % 5 + 3;
		
	}
	else {
		posX -= speed;
		
	}
}


bool CarManager::checkCollision(float playerPosX, float playerPosY, float playerWidth, float playerHeight) {

	bool collided = false;

	
	// Check for every car
	for (int i = 0; i < cars.size(); i++) {

		// If the x position is not colliding with the current cars x position, checking the y position is obsolete
		if (playerPosX + playerWidth > cars[i].posX
			&& playerPosX < cars[i].posX + cars[i].width) {

			// Checking for y position
			if (playerPosY + playerHeight > cars[i].posY
				&& playerPosY < cars[i].posY + cars[i].height) {
				
				collided = true;
			}

		}

	}
	
	return collided;
}
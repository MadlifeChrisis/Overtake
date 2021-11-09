#include "Player.h"
#include <iostream>

Player::Player(CarManager* carManager_) {
	posX = -700;
	posY =  000;
	width = 200;
	height = 100;
	xSpeed = 3;
	ySpeed = 3;
	carManager = carManager_;
	
	// Vertex one
	playerPositions[0] = posX;
	playerPositions[1] = posY;

	// Vertex two
	playerPositions[2] = posX + width;
	playerPositions[3] = posY;

	// Vertex three
	playerPositions[4] = posX + width;
	playerPositions[5] = posY + height;

	// Vertex four
	playerPositions[6] = posX;
	playerPositions[7] = posY + height;


}

Player::~Player() {

}

void Player::setXMove(int direction)
{
	
	xDirection = direction;
}
void Player::setYMove(int direction)
{
	
	yDirection = direction;
}



void Player::update()
{
	alive = !carManager->checkCollision(posX, posY, width, height);

	// Checking the position in order to stay on the road
	if ((xDirection == -1 && posX > -800) || (xDirection == 1 && posX + width < 800)) {
		posX += xSpeed * xDirection;
	}

	if ((yDirection == -1 && posY > -450) || (yDirection == 1 && posY + height < 450)) {
		posY += ySpeed * yDirection;
	}

	// Vertex one
	playerPositions[0] = posX;
	playerPositions[1] = posY;

	// Vertex two
	playerPositions[2] = posX + width;
	playerPositions[3] = posY;

	// Vertex three
	playerPositions[4] = posX + width;
	playerPositions[5] = posY + height;

	// Vertex four
	playerPositions[6] = posX;
	playerPositions[7] = posY + height;

}

void Player::render(Renderer renderer, Shader shader)
{
	// VAO
	VertexArray va;

	//Buffer objects
	VertexBuffer vb(playerPositions, playerVertexCount * sizeof(float));
	VertexBufferLayout layout;
	layout.Push<float>(2);

	va.addBuffer(vb, layout);
	IndexBuffer ib(playerIndices, playerIndexCount);


	shader.setUniform4f("uColor", 1.0f, 0.0f, 0.0f, 1.0f);

	renderer.draw(va, ib, shader);

}

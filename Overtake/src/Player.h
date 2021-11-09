#pragma once
#include "Renderer.h"
#include "Shader.h"
#include "CarManager.h"

class Player
{

private:
	float posX;
	float posY;
	float width;
	float height;
	float xSpeed;
	float ySpeed;
	int xDirection = 0;
	int yDirection = 0;
	
	bool alive = true;
	
	CarManager* carManager;

	float playerPositions[8]{ 0 };
	unsigned int playerIndices[6] = {
		
		0,1,2,
		2,3,0
	
	};

	unsigned int playerVertexCount = 8;
	unsigned int playerIndexCount = 6;


public:

	Player(CarManager* carManager);
	~Player();

	void setXMove(int direction);
	void setYMove(int direction);
	void update();
	void render(Renderer renderer, Shader shader);
	bool isAlive() { return alive; }
};


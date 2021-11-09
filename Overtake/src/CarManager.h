#pragma once
#include <vector>
#include "Renderer.h"
#include "Shader.h"

struct car {
	
	float posX;
	float posY;
	float width;
	float height;
	float speed;
	void update();
};

class CarManager
{
private:
	

	// 6 cars with 4 vertices, each vertex has 4 numbers
	unsigned int carVertexCount = 6 * 4 * 4;
	float carPositions[6 * 4 * 4]{ 0 };

	// 6 cars with 6 indices each
	unsigned int carIndexCount = 6 * 6;
	unsigned int carIndices[6 * 6] = {
		// Car one
		0,1,2,2,3,0,

		// Car two
		4,5,6,6,7,4,

		// Car three
		8,9,10,10,11,8,

		// Car four
		12,13,14,14,15,12,

		// Car five
		16,17,18,18,19,16,

		// Car six
		20,21,22,22,23,20
	};


public:
	CarManager();
	~CarManager();

	std::vector<car> cars;
	void update();
	void render(Renderer renderer, Shader shader);
	bool checkCollision(float playerPosX, float playerPosY, float playerWidth, float playerHeight);
};


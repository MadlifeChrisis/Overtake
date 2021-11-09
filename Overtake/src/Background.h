#pragma once
#include "Renderer.h"

struct line {
	float posX;
	float posY;
	float width;
	float height;
	float speed;
	void update();
};

class Background
{

private:
	std::vector<line> roadMarkings;
	
	// 22 lines with 4 vertices, each vertex has 2 numbers
	unsigned int roadMarkingsVertexCount = 22 * 4 * 2;
	float roadMarkingsPositions[22 * 4 * 2]{ 0 };

	// 22 lines with 6 indices each
	unsigned int roadMarkingsIndexCount = 22 * 6;
	unsigned int roadMarkingsIndices[22 * 6] = {
		0,1,2,2,3,0,
		4,5,6,6,7,4,
		8,9,10,10,11,8,
		12,13,14,14,15,12,
		16,17,18,18,19,16,
		20,21,22,22,23,20,
		24,25,26,26,27,24,
		28,29,30,30,31,28,
		32,33,34,34,35,32,
		36,37,38,38,39,36,
		40,41,42,42,43,40,
		44,45,46,46,47,44,
		48,49,50,50,51,48,
		52,53,54,54,55,52,
		56,57,58,58,59,56,
		60,61,62,62,63,60,
		64,65,66,66,67,64,
		68,69,70,70,71,68,
		72,73,74,74,75,72,
		76,77,78,78,79,76,
		80,81,82,82,83,80,
		84,85,86,86,87,84
	};

public:
	Background();
	~Background();

	void update();
	void render(Renderer renderer, Shader shader);
};


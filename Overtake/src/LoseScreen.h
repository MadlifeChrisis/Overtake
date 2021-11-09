#pragma once
#include "Renderer.h"
#include "Shader.h"

class LoseScreen
{
private:
	float alpha = 0.0f;
	float textPositions[68]{ 0 };
	unsigned int textIndices[78] = {

		// L //
		0,1,2,2,3,0,
		3,4,5,5,0,3,

		// O //
		6,7,10,
		6,9,13,
		6,10,13,

		7,10,11,
		7,8,11,

		8,11,12,
		8,9,12,
		
		9,12,13,

		// S //

		14,15,16,
		15,16,17,
		15,17,18,
		15,18,19,
		18,19,21,
		19,20,21,
		20,21,22,
		20,22,23,
		22,23,24,
		22,24,25,
		
		// T //
		26,27,28,
		26,28,33,
		29,30,32,
		30,31,32

		
	};

	unsigned int textVertexCount = 68;
	unsigned int textIndexCount = 78;

public:
	LoseScreen();
	~LoseScreen();
	void update();
	void render(Renderer renderer, Shader shader);

};


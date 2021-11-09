#include "Background.h"
#include <iostream>




Background::Background()
{
		
	// First two markings enclose the road with a continious line
	roadMarkings.push_back({ -800, -410, 1600, 5 , 0 });
	roadMarkings.push_back({ -800,  410, 1600, 5 , 0 });
	
	float xPosition = -800;
	
	for (int x = 0; x < 4; x++) {
		float yPosition = -280;

		for (int y = 0; y < 5; y++) {
			roadMarkings.push_back({xPosition, yPosition, 100, 3 , 10 });

			yPosition += 140;
		}

		xPosition += 425;
	}



	// Updating values in the array
	for (int i = 0; i < roadMarkings.size(); i++) {
		// Vertex one
		roadMarkingsPositions[i * 8 + 0] = roadMarkings[i].posX;
		roadMarkingsPositions[i * 8 + 1] = roadMarkings[i].posY;

		// Vertex two
		roadMarkingsPositions[i * 8 + 2] = roadMarkings[i].posX + roadMarkings[i].width;
		roadMarkingsPositions[i * 8 + 3] = roadMarkings[i].posY;

		// Vertex three
		roadMarkingsPositions[i * 8 + 4] = roadMarkings[i].posX + roadMarkings[i].width;
		roadMarkingsPositions[i * 8 + 5] = roadMarkings[i].posY + roadMarkings[i].height;

		// Vertex four
		roadMarkingsPositions[i * 8 + 6] = roadMarkings[i].posX;
		roadMarkingsPositions[i * 8 + 7] = roadMarkings[i].posY + roadMarkings[i].height;

	}

}

Background::~Background()
{
	roadMarkings.clear();
	roadMarkings.shrink_to_fit();
}

void Background::update()
{
	// Skip the first two markings because there is no movement
	for (unsigned int i = 0; i < roadMarkings.size(); i++) {

		// Updating values in the array
		roadMarkings[i].update();

		// Vertex one
		roadMarkingsPositions[i * 8 + 0] = roadMarkings[i].posX;
		roadMarkingsPositions[i * 8 + 1] = roadMarkings[i].posY;

		// Vertex two
		roadMarkingsPositions[i * 8 + 2] = roadMarkings[i].posX + roadMarkings[i].width;
		roadMarkingsPositions[i * 8 + 3] = roadMarkings[i].posY;

		// Vertex three
		roadMarkingsPositions[i * 8 + 4] = roadMarkings[i].posX + roadMarkings[i].width;
		roadMarkingsPositions[i * 8 + 5] = roadMarkings[i].posY + roadMarkings[i].height;

		// Vertex four
		roadMarkingsPositions[i * 8 + 6] = roadMarkings[i].posX;
		roadMarkingsPositions[i * 8 + 7] = roadMarkings[i].posY + roadMarkings[i].height;

	}
}

void Background::render(Renderer renderer, Shader shader)
{
	
	// VAO
	VertexArray va;

	//Buffer objects
	VertexBuffer vb(roadMarkingsPositions, roadMarkingsVertexCount * sizeof(float));
	VertexBufferLayout layout;
	layout.Push<float>(2);

	va.addBuffer(vb, layout);
	IndexBuffer ib(roadMarkingsIndices, roadMarkingsIndexCount);

	shader.setUniform4f("uColor", 1.0f, 1.0f, 1.0f, 1.0f);

	renderer.draw(va, ib, shader);
}

void line::update() 
{
	if (posX + width < -800) {
		posX = 800;
	}
	else {
		posX -= speed;
	}
}

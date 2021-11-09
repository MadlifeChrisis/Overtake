#include "LoseScreen.h"

LoseScreen::LoseScreen() {
	////	L	////
	
	// Vertex zero
	textPositions[0] =  -315;
	textPositions[1] =     0;

	// Vertex one
	textPositions[2] =  -165;
	textPositions[3] =     0;

	// Vertex two
	textPositions[4] =  -165;
	textPositions[5] =    50;

	// Vertex three
	textPositions[6] =  -265;
	textPositions[7] =    50;

	// Vertex four
	textPositions[8] =  -265;
	textPositions[9] =   200;

	// Vertex five
	textPositions[10] = -315;
	textPositions[11] =  200;

	////	O	////
	// Vertex six
	textPositions[12] = -155;
	textPositions[13] =    0;
				  
	// Vertex seven 
	textPositions[14] =   -5;
	textPositions[15] =    0;
				  
	// Vertex eight
	textPositions[16] =   -5;
	textPositions[17] =  200;
				  
	// Vertex nine
	textPositions[18] = -155;
	textPositions[19] =  200;
				  		 
	// Vertex 10		 
	textPositions[20] = -105;
	textPositions[21] =   50;
						 
	// Vertex 11		 
	textPositions[22] =  -55;
	textPositions[23] =   50;
						 
	// Vertex 12		 
	textPositions[24] =  -55;
	textPositions[25] =  150;

	// Vertex 13
	textPositions[26] = -105;
	textPositions[27] =  150;
	
	////	S	////
	// Vertex 14
	textPositions[28] =    5;
	textPositions[29] =    0;
						 
	// Vertex 15		 
	textPositions[30] =  155;
	textPositions[31] =    0;
						 
	// Vertex 16		 
	textPositions[32] =    5;
	textPositions[33] =   50;
						 
	// Vertex 17		 
	textPositions[34] =  105;
	textPositions[35] =   50;
						 
	// Vertex 18		 
	textPositions[36] =  105;
	textPositions[37] =   75;
						 
	// Vertex 19		 
	textPositions[38] =  155;
	textPositions[39] =  125;
						 
	// Vertex 20		 
	textPositions[40] =   55;
	textPositions[41] =  125;
						 
	// Vertex 21		 
	textPositions[42] =    5;
	textPositions[43] =   75;
						 
	// Vertex 22		 
	textPositions[44] =    5;
	textPositions[45] =  200;
						 
	// Vertex 23		 
	textPositions[46] =  55;
	textPositions[47] =  150;
						 
	// Vertex 24		 
	textPositions[48] =  155;
	textPositions[49] =  150;
						 
	// Vertex 25		 
	textPositions[50] =  155;
	textPositions[51] =  200;
	
	////	T	////
	// Vertex 26	 
	textPositions[52] = 215;
	textPositions[53] =   0;

	// Vertex 27		 
	textPositions[54] = 265;
	textPositions[55] =   0;

	// Vertex 28		 
	textPositions[56] = 265;
	textPositions[57] = 150;

	// Vertex 29		 
	textPositions[58] = 315;
	textPositions[59] = 150;

	// Vertex 30		 
	textPositions[60] = 315;
	textPositions[61] = 200;

	// Vertex 31		 
	textPositions[62] = 165;
	textPositions[63] = 200;
				  
	// Vertex 32		 
	textPositions[64] = 165;
	textPositions[65] = 150;

	// Vertex 33		 
	textPositions[66] = 215;
	textPositions[67] = 150;


}

LoseScreen::~LoseScreen()
{
}


void LoseScreen::update() {
	if (alpha < 1.0f) {
		alpha += 0.01f;
	}
}


void LoseScreen::render(Renderer renderer, Shader shader) {
	// VAO
	VertexArray va;

	//Buffer objects
	VertexBuffer vb(textPositions, textVertexCount * sizeof(float));
	VertexBufferLayout layout;
	layout.Push<float>(2);

	va.addBuffer(vb, layout);
	IndexBuffer ib(textIndices, textIndexCount);


	shader.setUniform4f("uColor", 1.0f, 1.0f, 1.0f, alpha);

	renderer.draw(va, ib, shader);
}

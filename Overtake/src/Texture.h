#pragma once
#include <string>

class Texture
{
private:
	unsigned int rendererID;
	std::string filepath;
	unsigned char* localBuffer;
	int width, height, bPP;


public:
	Texture(const std::string& path);
	~Texture();

	void bind(unsigned int slot = 0) const;
	void unbind() const;

};


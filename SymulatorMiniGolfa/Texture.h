#pragma once

#include <GL/glew.h>
#include "CommonValues.h"

class Texture
{
public:
	Texture();
	Texture(const char* fileLoc);
	Texture(const char* file1Loc, const char* file2Loc);

	void LoadTexture();
	void LoadTextures();
	void UseTexture();
	void UseTextures();
	void ClearTexture();

	~Texture();

private:
	GLuint textureID;
	GLuint texture2ID;
	int width, height, bitDepth;

	const char* fileLocation;
	const char* file2Location;
};


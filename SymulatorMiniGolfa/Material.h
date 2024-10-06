#pragma once

#include <GL/glew.h>

class Material
{
public:
	Material();
	Material(GLfloat sIntensity, GLfloat shine);

	void UseMaterial(GLuint specularIntensityLocation, GLuint shinessLocation);

	~Material();

	GLfloat specularIntensity = 1.0f;
	GLfloat shininess = 1.0f;
};


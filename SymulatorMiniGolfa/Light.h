#pragma once

#include <GL/glew.h>
#include <glm/glm.hpp>

class Light
{
public:
	Light();
	Light(GLfloat red, GLfloat green, GLfloat blue,
			GLfloat aIntensity, GLfloat dIntensity);

	void setColour(const glm::vec3& col);

	void setAmbientIntensity(float intensity);

	void setDiffuseIntensity(float intensity);

	~Light();

protected:
	glm::vec3 colour;
	GLfloat ambientIntensity;
	GLfloat diffuseIntensity;
};


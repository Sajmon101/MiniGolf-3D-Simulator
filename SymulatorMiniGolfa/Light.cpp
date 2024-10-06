#include "Light.h"

Light::Light()
{
	colour = glm::vec3(1.0f, 1.0f, 1.0f);
	ambientIntensity = 1.0f;
	diffuseIntensity = 0.0f;
}

Light::Light(GLfloat red, GLfloat green, GLfloat blue, GLfloat aIntensity,GLfloat dIntensity)
{
	colour = glm::vec3(red, green, blue);
	ambientIntensity = aIntensity;
	diffuseIntensity = dIntensity;
}

void Light::setColour(const glm::vec3& col) {
	colour = col;
}

void Light::setAmbientIntensity(float intensity) {
	ambientIntensity = intensity;
}

void Light::setDiffuseIntensity(float intensity) {
	diffuseIntensity = intensity;
}


Light::~Light()
{
}

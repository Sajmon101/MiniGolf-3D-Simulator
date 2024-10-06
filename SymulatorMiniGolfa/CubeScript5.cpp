#include "CubeScript5.h"

CubeScript5::CubeScript5(GameObject* gameObject) : Component(gameObject) {}

void CubeScript5::Start()
{
	gameObject->setTextureByPath("Textures/wood.png");
	gameObject->setPosition(glm::vec3(20.5f, 0.0f, -2.0f));
	gameObject->setScale(glm::vec3(26.0f, 1.0f, 1.0f));
}


void CubeScript5::Update(bool* keys)
{
}
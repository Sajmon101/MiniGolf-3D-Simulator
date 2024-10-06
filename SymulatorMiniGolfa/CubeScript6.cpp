#include "CubeScript6.h"

CubeScript6::CubeScript6(GameObject* gameObject) : Component(gameObject) {}

void CubeScript6::Start()
{
	gameObject->setTextureByPath("Textures/wood.png");
	gameObject->setPosition(glm::vec3(34.0f, 0.0f, -9.5f));
	gameObject->setScale(glm::vec3(1.0f, 1.0f, 16.0f));
}


void CubeScript6::Update(bool* keys)
{
}
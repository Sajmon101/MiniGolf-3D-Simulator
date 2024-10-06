#include "CubeScript4.h"

CubeScript4::CubeScript4(GameObject* gameObject) : Component(gameObject) {}

void CubeScript4::Start()
{
	gameObject->setTextureByPath("Textures/wood.png");
	gameObject->setPosition(glm::vec3(7.5f, 0.0f, 11.0f));
	gameObject->setScale(glm::vec3(1.0f, 1.0f, 27.0f));
}


void CubeScript4::Update(bool* keys)
{
}
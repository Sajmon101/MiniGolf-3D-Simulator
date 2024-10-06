#include "CubeScript2.h"

CubeScript2::CubeScript2(GameObject* gameObject) : Component(gameObject) {}

void CubeScript2::Start()
{
	gameObject->setTextureByPath("Textures/wood.png");
	gameObject->setPosition(glm::vec3(-8.0f, 0.0f, 3.0f));
	gameObject->setScale(glm::vec3(1.0f, 1.0f, 41.0f));
}


void CubeScript2::Update(bool* keys)
{
}
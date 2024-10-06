#include "CubeScript3.h"

CubeScript3::CubeScript3(GameObject* gameObject) : Component(gameObject) {}

void CubeScript3::Start()
{
	gameObject->setTextureByPath("Textures/wood.png");
	gameObject->setPosition(glm::vec3(-0.75f, 0.0f, 24.0f));
	gameObject->setScale(glm::vec3(15.5f, 1.0f, 1.0f));
}


void CubeScript3::Update(bool* keys)
{
}
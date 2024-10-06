#include "Hole.h"
Hole::Hole(GameObject* gameObject) : Component(gameObject) {}

void Hole::Start()
{
	gameObject->setPosition(glm::vec3(0.0f, -0.24f, 18.0f));
	gameObject->setScale(glm::vec3(2.0f, 2.0f, 2.0f));
	gameObject->setTextureByPath("Textures/hole.png");
	gameObject->setMaterial(2.0f, 16);
}


void Hole::Update(bool* keys)
{
}
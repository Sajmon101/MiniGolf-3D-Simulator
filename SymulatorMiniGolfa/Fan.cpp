#include "Fan.h"

Fan::Fan(GameObject* gameObject) : Component(gameObject) {}

void Fan::Start()
{
	gameObject->setPosition(glm::vec3(2.0f, 0.0f, -8.0f));
}


void Fan::Update(bool* keys)
{
	gameObject->rotateObject(0.2f, glm::vec3(0.0f, 0.0f, 1.0f), glm::vec3(0.0f, 5.0f,0.0f));
}
#include "WindMill.h"
#include "BoxCollider.h"

WindMill::WindMill(GameObject* gameObject) : Component(gameObject) {}

void WindMill::Start()
{
	gameObject->setPosition(glm::vec3(2.0f, 0.0f, -8.0f));
}


void WindMill::Update(bool* keys)
{
}
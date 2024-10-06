#include "PlaneScript.h"
PlaneScript::PlaneScript(GameObject* gameObject) : Component(gameObject) {}

void PlaneScript::Start()
{
	gameObject->setPosition(glm::vec3(0.0f, -0.25f, 0.0f));
	gameObject->setScale(glm::vec3(2.0f, 2.0f, 2.0f));
	gameObject->setTexturesByPath("Textures/grass.png", "Textures/dirt.png");
	gameObject->setMaterial(2.0f, 16);
}


void PlaneScript::Update(bool* keys)
{
}
#include "CubeScript.h"

CubeScript::CubeScript(GameObject* gameObject) : Component(gameObject) {}

void CubeScript::Start()
{
	gameObject->setTextureByPath("Textures/wood.png");
	gameObject->setPosition(glm::vec3(13.0f, 0.0f, -17.0f));
	gameObject->setScale(glm::vec3(42.0f, 1.0f, 1.0f));
}


void CubeScript::Update(bool* keys)
{
}
#include "ClubScript.h"
#include <GLFW/glfw3.h>

ClubScript::ClubScript(GameObject* gameObject) : Component(gameObject) {}

void ClubScript::Start()
{
	gameObject->setRotation(90.0f, glm::vec3(0.0f, 1.0f, 0.0f));
	gameObject->setPosition(glm::vec3(-0.3f, -0.4f, -9.0f));
	gameObject->setScale(glm::vec3(0.02f, 0.02f, 0.02f));
	gameObject->setTextureByPath("Textures/plain.png");
	gameObject->setMaterial(4.0f, 256);
	endAction = true;
	sumAngle = 0.0f;
	returnAngle = 0.0f;
}


void ClubScript::Update(bool* keys)
{
	float velocity = gameObject->getScene()->deltaTime;

	if (keys[GLFW_KEY_SPACE] && endAction) {
		spaceDown = true;
		angle = 40.0f * velocity;
		if (sumAngle >= 70.0f) 
		{
			angle = 0.0f;	
		}
		sumAngle += angle;
		returnAngle = sumAngle + 20.0f;
		gameObject->rotateObject(-angle, glm::vec3(1.0f, 0.0f, 0.0f), glm::vec3(0.0f, 4.0f, 0.0f));
	}
	if (!keys[GLFW_KEY_SPACE] && spaceDown)
	{
		float velocity = gameObject->getScene()->deltaTime;

		angle = 400.0f * velocity;
		endAction = false;
		gameObject->rotateObject(angle, glm::vec3(1.0f, 0.0f, 0.0f), glm::vec3(0.0f, 4.0f, 0.0f));
		returnAngle -= angle;
		if (returnAngle <= 0.0f)
		{
			ball->force = sumAngle;
			ball->endAction = false;
			gameObject->setRotation(90.0f, glm::vec3(0.0f, 1.0f, 0.0f));
			sumAngle = 0.0f;
			returnAngle = 0.0f;
			endAction = true;
			spaceDown = false;
		}
	}
	
}



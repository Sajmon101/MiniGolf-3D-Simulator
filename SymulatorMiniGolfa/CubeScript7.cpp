#include "CubeScript7.h"

CubeScript7::CubeScript7(GameObject* gameObject) : Component(gameObject) {}

void CubeScript7::Start()
{
	gameObject->setTextureByPath("Textures/wood.png");
	gameObject->setPosition(glm::vec3(0.0f, 0.0f, 8.0f));
	gameObject->setScale(glm::vec3(5.0f, 1.0f, 1.0f));

	ball = gameObject->getScene()->getGameObject("ball");

	BallScript* ballScript = ball->getComponent<BallScript>();
	BoxCollider* thiscollider = gameObject->getComponent<BoxCollider>();
}


void CubeScript7::Update(bool* keys)
{
	//gameObject->moveObject(moveDir);
	//counter++;

	//if (counter > 1000) {
	//	moveDir = -moveDir;
	//	counter = 0;
	//}

	
	//if (thiscollider != nullptr) {
	//	normal = thiscollider->checkCollision(ball->GetPosition(), ball->GetScale());
	//	if (normal != glm::vec3(0)) {
	//		ballScript->moveBall(0.01, 10.0f, normal);
	//		printf("%f %f %f \n", normal.x, normal.y, normal.z);
	//	}
	//}
}
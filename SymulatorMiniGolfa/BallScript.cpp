#include "BallScript.h"
#include <GLFW/glfw3.h>
#include "BoxCollider.h"

BallScript::BallScript(GameObject* gameObject) : Component(gameObject) {}


void BallScript::Start()
{
	gameObject->setScale(glm::vec3(0.25f, 0.25f, 0.25f));
	gameObject->setPosition(glm::vec3(28.0f, 0.0f, -9.5f));
	gameObject->setTextureByPath("Textures/ball.png");
	gameObject->setMaterial(4.0f, 256);
	lastTime = glfwGetTime();
	force = 0.0f;
	endAction = true;
	spaceDown = false;
	flag = false;
	startMovement = false;
}

void BallScript::Update(bool* keys)
{
	if (!endAction && startMovement == false)
	{
		glm::vec3 up(0.0f, 1.0f, 0.0f);
		direction = (moveDirection - (glm::dot(moveDirection, up) * up));
		startMovement = true;
	}
	if (!endAction && startMovement)
	{
		float deceleration = moveBall(gameObject->getScene()->deltaTime, 2.0f, force, direction);
		if (deceleration <= 0.01f)
		{
			endAction = true;
			startMovement = false;
			force = 0.0f;
			t = 0.0f;
		}
	}
	CheckCollisions();
	BallInHole(gameObject->position, glm::vec3(0.0f, 1.0f, 18.0f));
}

void BallScript::CheckCollisions()
{
	for (BoxCollider* collider : BoxCollider::getAllColliders()) {

		glm::vec3 normal = collider->checkCollision(gameObject->GetPosition(), gameObject->GetScale());
		
		if (normal != glm::vec3(0)) 
		{
			if (!endAction) //gdy pi³eczka siê rusza i dobije do obiektu
			{
				glm::vec3 incomingDirection = direction;
				glm::vec3 reflectionDirection = incomingDirection - 2 * glm::dot(incomingDirection, normal) * normal;
				direction = reflectionDirection;
			}
			else { //gdy pi³eczka siê nie rusza i obiekt do niej dobije
				direction = -normal;
				endAction = false;
			}
		}
	}
}



float BallScript::moveBall(GLfloat deltaTime, float totalTime, float force, const glm::vec3& direction) //totalTime - jak d³ugo ma lecieæ pi³ka, force - z jak¹ startow¹, potêga przy easeOut - jak szybko zwalnia
{
	if (t > totalTime)
	{
		t = 0.0f;
		return true; // Zakoñcz, gdy przemieszczenie siê zakoñczy
	}

	t += deltaTime;
	float normalizedTime = t / totalTime;

	float easeOut = 1 - pow(1 - normalizedTime, 2);

	float deceleration = force * (1 - easeOut);
	gameObject->moveObject(deceleration * deltaTime * glm::normalize(direction));


	///////Obrót//////
	float rotationEaseOut = 1 - pow(1 - normalizedTime, 2); // Zanikanie rotacji
	float speed = force*100.0f;
	float rotationDeceleration = speed * (1 - easeOut);
	float rotationAngle = rotationDeceleration * rotationEaseOut * deltaTime; // Obrót proporcjonalny do prêdkoœci, czasu i zanikania

	// Wyznaczenie osi obrotu który jest prostopad³y do wektora przemieszczenia i osi OY
	glm::vec3 upVector = glm::vec3(0.0f, 1.0f, 0.0f); // Wektor w kierunku "góry"
	glm::vec3 perpendicularVector = glm::cross(direction, upVector);

	// Normalizacja, aby uzyskaæ wektor jednostkowy
	gameObject->rotateObject(rotationAngle, glm::normalize(-perpendicularVector), glm::vec3(0.0f,0.0f,0.0f));

	return deceleration;
}

void BallScript::BallInHole(glm::vec3 ballPosition, glm::vec3 holePosition)
{
	if ((ballPosition.x <= holePosition.x + 0.2f && ballPosition.x >= holePosition.x - 0.2f) &&
		(ballPosition.z <= holePosition.z + 0.2f && ballPosition.z >= holePosition.z - 0.2f))
	{
		startMovement = false;
		force = 0.0f;
		endAction = false;
		gameObject->setPosition(glm::vec3(glm::vec3(28.0f, 0.0f, -9.5f)));
	}
}
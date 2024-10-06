#pragma once
#include <vector>





glm::vec3 ballPos = glm::vec3(0.0f, 0.0f, 0.0f); //declare global starting positon of ball
float rotationAngle;
glm::vec3 rotationAxis;

bool AnimateClub(float& force)
{

	return false;
}

bool moveBall(float deltaTime, float totalTime, float force, const glm::vec3& direction) //totalTime - jak d�ugo ma lecie� pi�ka, force - z jak� startow�, pot�ga przy easeOut - jak szybko zwalnia
{
	static float strengthOfSlowing = 2.0f;
	static float t = 0.0f;
	static float v = 0.0f;

	if (t > totalTime)
	{
		t = 0.0f;
		return true; // Zako�cz, gdy przemieszczenie si� zako�czy
	}

	t += deltaTime;
	float normalizedTime = t / totalTime;

	float easeOut = 1 - pow(1 - normalizedTime, 2);

	float deceleration = force * (1 - easeOut);
	ballPos += deceleration * deltaTime * glm::normalize(direction);


	/////Obr�t//////
	float speed = glm::length(direction); // Pr�dko�� jako d�ugo�� wektora kierunku
	float rotationAngle = speed * deltaTime; // Obr�t proporcjonalny do pr�dko�ci i czasu

	// Wyznaczenie osi obrotu kt�ry jest prostopad�y do wektora przemieszczenia i osi OY
	glm::vec3 upVector = glm::vec3(0.0f, 1.0f, 0.0f); // Wektor w kierunku "g�ry"
	glm::vec3 perpendicularVector = glm::cross(direction, upVector);

	// Normalizacja, aby uzyska� wektor jednostkowy
	rotationAxis = glm::normalize(perpendicularVector);

	return false;
}

bool endAction = true;
void BallUptade(bool* keys, float deltaTime, float force)
{

	if ((keys[GLFW_KEY_SPACE] && endAction) || !endAction)
	{
		endAction = false;
		glm::vec3 direction(1.0f, 0.0f, 0.0f); //TO DO: put here direction where camera is looking. 
		if (moveBall(deltaTime, 2.0f, force, direction)) endAction = true; //force threshold 2-150

	}
}
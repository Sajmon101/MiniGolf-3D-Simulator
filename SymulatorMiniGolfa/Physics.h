#pragma once
#include <vector>





glm::vec3 ballPos = glm::vec3(0.0f, 0.0f, 0.0f); //declare global starting positon of ball
float rotationAngle;
glm::vec3 rotationAxis;

bool AnimateClub(float& force)
{

	return false;
}

bool moveBall(float deltaTime, float totalTime, float force, const glm::vec3& direction) //totalTime - jak d³ugo ma lecieæ pi³ka, force - z jak¹ startow¹, potêga przy easeOut - jak szybko zwalnia
{
	static float strengthOfSlowing = 2.0f;
	static float t = 0.0f;
	static float v = 0.0f;

	if (t > totalTime)
	{
		t = 0.0f;
		return true; // Zakoñcz, gdy przemieszczenie siê zakoñczy
	}

	t += deltaTime;
	float normalizedTime = t / totalTime;

	float easeOut = 1 - pow(1 - normalizedTime, 2);

	float deceleration = force * (1 - easeOut);
	ballPos += deceleration * deltaTime * glm::normalize(direction);


	/////Obrót//////
	float speed = glm::length(direction); // Prêdkoœæ jako d³ugoœæ wektora kierunku
	float rotationAngle = speed * deltaTime; // Obrót proporcjonalny do prêdkoœci i czasu

	// Wyznaczenie osi obrotu który jest prostopad³y do wektora przemieszczenia i osi OY
	glm::vec3 upVector = glm::vec3(0.0f, 1.0f, 0.0f); // Wektor w kierunku "góry"
	glm::vec3 perpendicularVector = glm::cross(direction, upVector);

	// Normalizacja, aby uzyskaæ wektor jednostkowy
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
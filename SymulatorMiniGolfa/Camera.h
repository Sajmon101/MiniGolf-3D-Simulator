#pragma once

#include <GL/glew.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include <GLFW/glfw3.h>

class Camera
{
public:
	Camera(glm::vec3 startPosition, glm::vec3 startUp, GLfloat startYaw, GLfloat startPitch, GLfloat startMoveSpeed, GLfloat startTurnSpeed,
		glm::vec3 startLookAtPoint);
	Camera();

	void KeyControl(bool* keys, GLfloat deltaTime);
	void KeyControlFlying(bool* keys, GLfloat deltaTime);
	void MouseControl(GLfloat xChange, GLfloat yChange);

	glm::vec3 getCameraPosition();

	glm::mat4 CalculateViewMatrix();
	glm::mat4 CalculateViewMatrixFlying();

	glm::vec3 calculateCameraDirection();

	void SetLookAtPoint(glm::vec3 newLookAtPoint);
	void SetCameraPosition();

	void ChangeCameraMode(bool* keys);

	bool cameraMode;
	glm::vec3 front;

	~Camera();
private:
	glm::vec3 position;
	
	glm::vec3 up;
	glm::vec3 right;
	glm::vec3 worldUp;

	float camX;
	float camZ;
	float camY;
	float radius;

	bool cKeyPressed;

	glm::vec3 lookAtPoint;
	glm::vec3 cameraDirection;


	GLfloat cameraRotationAngle;
	GLfloat yaw;
	GLfloat pitch;

	GLfloat moveSpeed;
	GLfloat turnSpeed;

	void update();
};


#include "Camera.h"

Camera::Camera() {}

Camera::Camera(glm::vec3 startPosition, glm::vec3 startUp, GLfloat startYaw, GLfloat startPitch, GLfloat startMoveSpeed, GLfloat startTurnSpeed,
	glm::vec3 startLookAtPoint)
{
	position = startPosition;
	worldUp = startUp;
	yaw = startYaw;
	pitch = startPitch;

	radius = 15.0f;
	moveSpeed = startMoveSpeed;
	turnSpeed = startTurnSpeed;
	lookAtPoint = startLookAtPoint;
	front = -calculateCameraDirection();

	cameraRotationAngle = 1.5f;
	camX = 0;
	camZ = 0;
	camY = startPosition.y;
	cameraMode = false;
	cKeyPressed = false;
	update();
}

void Camera::KeyControl(bool* keys, GLfloat deltaTime)
{
	GLfloat velocity = moveSpeed * deltaTime;

	if (keys[GLFW_KEY_D])
	{
		cameraRotationAngle += 0.1f * velocity;
		camX = lookAtPoint.x + sin(cameraRotationAngle) * radius;
		camZ = lookAtPoint.z + cos(cameraRotationAngle) * radius;
		position = glm::vec3(camX, camY, camZ);
		yaw = -60.0f * cameraRotationAngle - 86.0f;
		
	}

	if (keys[GLFW_KEY_A])
	{
		cameraRotationAngle -= 0.1f * velocity;
		camX = lookAtPoint.x + sin(cameraRotationAngle) * radius;
		camZ = lookAtPoint.z + cos(cameraRotationAngle) * radius;
		position = glm::vec3(camX, camY, camZ);
		yaw = -60.0f * cameraRotationAngle - 86.0f;
	}
	pitch = -28;
	update();
}

void Camera::KeyControlFlying(bool* keys, GLfloat deltaTime)
{
	GLfloat velocity = moveSpeed * deltaTime;

	if (keys[GLFW_KEY_W])
	{
		position += front * velocity;
	}

	if (keys[GLFW_KEY_S])
	{
		position -= front * velocity;
	}

	if (keys[GLFW_KEY_A])
	{
		position -= right * velocity;
	}

	if (keys[GLFW_KEY_D])
	{
		position += right * velocity;
	}
}

void Camera::MouseControl(GLfloat xChange, GLfloat yChange)
{
	xChange *= turnSpeed;
	yChange *= turnSpeed;

	yaw += xChange;
	pitch += yChange;

	if (pitch > 89.0f)
	{
		pitch = 89.0f;
	}

	if (pitch < -89.0f)
	{
		pitch = -89.0f;
	}
	update();
}

glm::mat4 Camera::CalculateViewMatrix()
{
	return glm::lookAt(position, lookAtPoint, worldUp);
}

glm::mat4 Camera::CalculateViewMatrixFlying()
{
	return glm::lookAt(position, position + front, up);
}

glm::vec3 Camera::calculateCameraDirection()
{
	return glm::vec3(glm::normalize(position - lookAtPoint));
}

void Camera::SetLookAtPoint(glm::vec3 newLookAtPoint)
{
	lookAtPoint = newLookAtPoint;
}

void Camera::SetCameraPosition()
{
	camX = lookAtPoint.x + sin(cameraRotationAngle) * radius;
	camZ = lookAtPoint.z + cos(cameraRotationAngle) * radius;
	position = glm::vec3(camX, camY, camZ);
}

void Camera::ChangeCameraMode(bool* keys)
{
	if (keys[GLFW_KEY_C] && !cKeyPressed)
	{
		cKeyPressed = true;		
	}
	if (!keys[GLFW_KEY_C] && cKeyPressed)
	{
		cameraMode = !cameraMode;
		cKeyPressed = false;
		yaw = -60.0f * cameraRotationAngle - 86.0f;
	}
}


glm::vec3 Camera::getCameraPosition()
{
	return position;
}

void Camera::update()
{
	front.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
	front.y = sin(glm::radians(pitch));
	front.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
	front = glm::normalize(front);

	right = glm::normalize(glm::cross(front, worldUp));
	up = glm::normalize(glm::cross(right, front));
}

Camera::~Camera()
{
}

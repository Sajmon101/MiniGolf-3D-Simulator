#pragma once
#include <string>
#include <map>
#include <GL\glew.h>

class GameObject;

class Scene
{
public:
	Scene();

	void addGameObject(const std::string& name, const std::string& filePath);
	GameObject* getGameObject(const std::string& name);
	void addCube(const std::string& name);
	~Scene();

	GLfloat deltaTime = 0.0f;

private:
	std::map<std::string, GameObject*> gameObjects;
};


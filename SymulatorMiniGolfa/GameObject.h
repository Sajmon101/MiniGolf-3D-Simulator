#pragma once
#include "Mesh.h"
#include "ModelLoader.h"
#include <string>
#include "Shader.h"
#include "Texture.h"
#include "Component.h"
#include "Scene.h"

class Component;
class GameObject
{
public:
	GameObject(Scene* scene, const std::string& modelFilename);
	GameObject(Scene* scene, std::vector<glm::vec3> vertices, std::vector<glm::vec2> uvs, std::vector<glm::vec3> normals, std::vector<unsigned int> verticesIndices);
	~GameObject();

	virtual void update(float deltaTime);
	//void Render(Shader& shader, Texture& texture, glm::vec3 position, glm::vec3 scale);

	ModelLoader modelLoader;
	void setPosition(const glm::vec3& position);
	void moveObject(const glm::vec3& moveVector);
	glm::vec3 GetPosition() const;
	glm::vec3 GetScale() const;
	void setScale(const glm::vec3& scale);
	void setRotation(float angleDegrees, const glm::vec3& axis);
	void render(Shader& shader);
	void applyTransformation(const glm::mat4& transformation);
	void setTexture(Texture* texture);
	void setTexturesByPath(const char* fileLoc, const char* fileLoc2);
	void setTextureByPath(const char* fileLoc);
	void setMaterial(GLfloat sIntensity, GLfloat shine);
	void rotateObject(float angleDegrees, const glm::vec3& axis, const glm::vec3& centerPoint);
	//getRotation
	void AddComponent(Component* component);
	void Update(bool* keys);

	Scene* getScene() const;


//protected:
	Mesh* mesh;
	glm::vec3 position = glm::vec3(0.0f, 0.0f, 0.0f);
	glm::vec3 scale = glm::vec3(1.0f, 1.0f, 1.0f);
	glm::vec3 rotationAxis = glm::vec3(1.0f, 0.0f, 0.0f);
	float rotationAngle = 0.0f;
	glm::mat4 additionalTransformation = glm::mat4(1.0f);
	Texture* texture = nullptr;
	bool existTexture2 = false;
	Material* material = nullptr;

	std::vector<Component*> components;
	template <typename T>
	T* getComponent();

private:
	glm::mat4 totalRotationMatrix = glm::mat4(1.0f);
	Scene* m_scene;

};

#include "GameObject.tpp"
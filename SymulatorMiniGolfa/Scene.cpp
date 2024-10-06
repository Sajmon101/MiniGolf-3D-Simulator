#include "Scene.h"
#include "GameObject.h"

Scene::Scene()
{}

void Scene::addGameObject(const std::string& name, const std::string& filePath) {
    gameObjects[name] = new GameObject(this, filePath);
}

GameObject* Scene::getGameObject(const std::string& name) {
    return gameObjects[name];
}

void Scene::addCube(const std::string& name) {

    // Definicja wierzcho�k�w sze�cianu
    std::vector<glm::vec3> vertices = {
        // Prz�d
        glm::vec3(-0.5f, -0.5f,  0.5f),
        glm::vec3(0.5f, -0.5f,  0.5f),
        glm::vec3(0.5f,  0.5f,  0.5f),
        glm::vec3(-0.5f,  0.5f,  0.5f),
        // Ty�
        glm::vec3(-0.5f, -0.5f, -0.5f),
        glm::vec3(0.5f, -0.5f, -0.5f),
        glm::vec3(0.5f,  0.5f, -0.5f),
        glm::vec3(-0.5f,  0.5f, -0.5f)
    };

    // Definicja indeks�w wierzcho�k�w dla ka�dej �ciany sze�cianu (2 tr�jk�ty na �cian�)
    std::vector<unsigned int> verticesIndices = {
        // Prz�d
        0, 1, 2, 2, 3, 0,
        // Ty�
        4, 5, 6, 6, 7, 4,
        // Lewo
        4, 0, 3, 3, 7, 4,
        // Prawo
        1, 5, 6, 6, 2, 1,
        // D�
        4, 5, 1, 1, 0, 4,
        // G�ra
        3, 2, 6, 6, 7, 3
    };

    std::vector<glm::vec2> uvs = {
        // Prz�d
        glm::vec2(0.0f, 0.0f),
        glm::vec2(1.0f, 0.0f),
        glm::vec2(1.0f, 1.0f),
        glm::vec2(0.0f, 1.0f),
        // Ty�
        glm::vec2(0.0f, 0.0f),
        glm::vec2(1.0f, 0.0f),
        glm::vec2(1.0f, 1.0f),
        glm::vec2(0.0f, 1.0f),

        glm::vec2(0.0f, 0.0f),
        glm::vec2(1.0f, 0.0f),
        glm::vec2(1.0f, 1.0f),
        glm::vec2(0.0f, 1.0f),

        glm::vec2(0.0f, 0.0f),
        glm::vec2(1.0f, 0.0f),
        glm::vec2(1.0f, 1.0f),
        glm::vec2(0.0f, 1.0f),

        glm::vec2(0.0f, 0.0f),
        glm::vec2(1.0f, 0.0f),
        glm::vec2(1.0f, 1.0f),
        glm::vec2(0.0f, 1.0f),

        glm::vec2(0.0f, 0.0f),
        glm::vec2(1.0f, 0.0f),
        glm::vec2(1.0f, 1.0f),
        glm::vec2(0.0f, 1.0f),
    };

    std::vector<glm::vec3> normals = {
        // Prz�d
        glm::vec3(0.0f, 0.0f, 1.0f),
        glm::vec3(0.0f, 0.0f, 1.0f),
        glm::vec3(0.0f, 0.0f, 1.0f),
        glm::vec3(0.0f, 0.0f, 1.0f),

        // Ty�
        glm::vec3(0.0f, 0.0f, -1.0f),
        glm::vec3(0.0f, 0.0f, -1.0f),
        glm::vec3(0.0f, 0.0f, -1.0f),
        glm::vec3(0.0f, 0.0f, -1.0f),

        // Lewo
        glm::vec3(-1.0f, 0.0f, 0.0f),
        glm::vec3(-1.0f, 0.0f, 0.0f),
        glm::vec3(-1.0f, 0.0f, 0.0f),
        glm::vec3(-1.0f, 0.0f, 0.0f),

        // Prawo
        glm::vec3(1.0f, 0.0f, 0.0f),
        glm::vec3(1.0f, 0.0f, 0.0f),
        glm::vec3(1.0f, 0.0f, 0.0f),
        glm::vec3(1.0f, 0.0f, 0.0f),

        // D�
        glm::vec3(0.0f, -1.0f, 0.0f),
        glm::vec3(0.0f, -1.0f, 0.0f),
        glm::vec3(0.0f, -1.0f, 0.0f),
        glm::vec3(0.0f, -1.0f, 0.0f),

        // G�ra
        glm::vec3(0.0f, 1.0f, 0.0f),
        glm::vec3(0.0f, 1.0f, 0.0f),
        glm::vec3(0.0f, 1.0f, 0.0f),
        glm::vec3(0.0f, 1.0f, 0.0f)
    };

    gameObjects[name] = new GameObject(this, vertices, uvs, normals, verticesIndices);
}

// Mo�na tu doda� metody do zarz�dzania obiektami, takie jak usuni�cie itd.

Scene::~Scene() {

    for (auto& obj : gameObjects) {
        delete obj.second;
    }
}
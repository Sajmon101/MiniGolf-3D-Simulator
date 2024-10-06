#pragma once
#include "Mesh.h"
#include "objloader.h"
#include <string>

class ModelLoader
{
public:
	ModelLoader();
	Mesh* loadModel(const std::string& filename);

	Mesh* makeMesh(std::vector<glm::vec3> vertices, std::vector<glm::vec2> uvs, std::vector<glm::vec3> normals, std::vector<unsigned int> verticesIndices);

};


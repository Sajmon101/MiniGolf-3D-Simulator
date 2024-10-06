#pragma once

#include <GL\glew.h>
#include <glm\glm.hpp>
#include <glm\gtc\matrix_transform.hpp>
#include <glm\gtc\type_ptr.hpp>
#include <vector>

class Mesh
{
public:
	Mesh();

	void CreateMesh(const std::vector<glm::vec3>& verticesOBJ,
		const std::vector<glm::vec2>& uvsOBJ,
		const std::vector<glm::vec3>& normalsOBJ,
		const std::vector<unsigned int>& vertexIndicesOBJ);
	void RenderMesh();
	void ClearMesh();
	~Mesh();

private:
	GLuint VAO, vertexVBO, normalVBO, verticesOBJSize, uvVBO, IBO;
	int indexCount;
	struct VertexData {
		glm::vec3 vertex;
		glm::vec2 uv;
		glm::vec3 normal;
	};

};


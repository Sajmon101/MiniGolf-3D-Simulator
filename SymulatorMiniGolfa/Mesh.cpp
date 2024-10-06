#include "Mesh.h"
#include "CommonValues.h"


Mesh::Mesh()
{
	VAO = 0;
	vertexVBO = 0;
	normalVBO = 0;
	verticesOBJSize = 0;
	uvVBO = 0;
	indexCount = 0;
	IBO = 0;
}

void Mesh::CreateMesh(const std::vector<glm::vec3>& verticesOBJ,
	const std::vector<glm::vec2>& uvsOBJ,
	const std::vector<glm::vec3>& normalsOBJ,
	const std::vector<unsigned int>& vertexIndicesOBJ) {
	indexCount = vertexIndicesOBJ.size();

	// Interleave vertex, uv, and normal data
	std::vector<VertexData> interleavedData;
	interleavedData.reserve(verticesOBJ.size()); // Assuming all arrays are the same size

	for (size_t i = 0; i < verticesOBJ.size(); ++i) {
		interleavedData.push_back({ verticesOBJ[i], uvsOBJ[i], normalsOBJ[i] });
	}

	// Generate and bind the vertex array object
	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);

	// Generate and bind the index buffer object
	glGenBuffers(1, &IBO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, IBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, vertexIndicesOBJ.size() * sizeof(unsigned int), vertexIndicesOBJ.data(), GL_STATIC_DRAW);

	// Generate and bind the vertex buffer object for the interleaved data
	glGenBuffers(1, &vertexVBO);
	glBindBuffer(GL_ARRAY_BUFFER, vertexVBO);
	glBufferData(GL_ARRAY_BUFFER, interleavedData.size() * sizeof(VertexData), interleavedData.data(), GL_STATIC_DRAW);

	// Define vertex attribute layout
	glEnableVertexAttribArray(0); // Vertex position
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(VertexData), (void*)0);

	glEnableVertexAttribArray(1); // UV coordinates
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(VertexData), (void*)(sizeof(glm::vec3)));

	glEnableVertexAttribArray(2); // Normals
	glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, sizeof(VertexData), (void*)(sizeof(glm::vec3) + sizeof(glm::vec2)));

	// Unbind the VBO and VAO
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
}

void Mesh::RenderMesh()
{
	glBindVertexArray(VAO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, IBO);
	
	if (wireframeMode)
	{
		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	}
	else
	{
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	}
	glDrawElements(GL_TRIANGLES, indexCount, GL_UNSIGNED_INT, 0);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
}

void Mesh::ClearMesh()
{
	if (IBO != 0)
	{
		glDeleteBuffers(1, &IBO);
		IBO = 0;
	}

	if (vertexVBO != 0)
	{
		glDeleteBuffers(1, &vertexVBO);
		vertexVBO = 0;
	}

	if (uvVBO != 0)
	{
		glDeleteBuffers(1, &uvVBO);
		uvVBO = 0;
	}

	if (normalVBO != 0)
	{
		glDeleteBuffers(1, &normalVBO);
		normalVBO = 0;
	}

	if (VAO != 0)
	{
		glDeleteVertexArrays(1, &VAO);
		VAO = 0;
	}

	indexCount = 0;
}


Mesh::~Mesh()
{
	ClearMesh();
}

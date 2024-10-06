#pragma once

#include <GL\glew.h>

class skyboxMesh
{
public:
	skyboxMesh();

	void CreateMesh(GLfloat* vertices, unsigned int* indices, unsigned int numOfVertices, unsigned int numOfIndices);
	void RenderMesh();
	void ClearMesh();

	~skyboxMesh();

private:
	GLuint VAO, VBO, IBO;
	GLsizei indexCount;
};


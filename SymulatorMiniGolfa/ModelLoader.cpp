#include "ModelLoader.h"

ModelLoader::ModelLoader()
{
}

Mesh* ModelLoader::loadModel(const std::string& filename)
{
    std::vector<unsigned int> verticesIndices, uvsIndices, normalsIndices;
    std::vector<glm::vec3> vertices;
    std::vector<glm::vec2> uvs;
    std::vector<glm::vec3> normals;

    bool res = loadOBJ(filename.c_str(), vertices, uvs, normals, verticesIndices);
    if (!res) 
    {
        printf("Failed to load OBJ file: %s ", filename);
    }

    Mesh* mesh = new Mesh();
    mesh->CreateMesh(vertices, uvs, normals, verticesIndices);
    return mesh;
}

Mesh* ModelLoader::makeMesh(std::vector<glm::vec3> vertices, std::vector<glm::vec2> uvs, std::vector<glm::vec3> normals, std::vector<unsigned int> verticesIndices)
{
    Mesh* mesh = new Mesh();
    mesh->CreateMesh(vertices, uvs, normals, verticesIndices);
    return mesh;
}

#pragma warning(disable:4996)
#include <vector>
#include <stdio.h>
#include <string>
#include <cstring>

#include "glm/glm.hpp"
#include "objloader.h"


#include <cstdio>



bool getSimilarVertexIndex(
    PackedVertex& packed,
    std::map<PackedVertex, unsigned int>& VertexToOutIndex,
    unsigned int& result
) {
    auto it = VertexToOutIndex.find(packed);
    if (it == VertexToOutIndex.end()) {
        return false;
    }
    else {
        result = it->second;
        return true;
    }
}

void indexVBO(
    std::vector<glm::vec3>& in_vertices,
    std::vector<glm::vec2>& in_uvs,
    std::vector<glm::vec3>& in_normals,

    std::vector<unsigned int>& out_indices,
    std::vector<glm::vec3>& out_vertices,
    std::vector<glm::vec2>& out_uvs,
    std::vector<glm::vec3>& out_normals
) {
    std::map<PackedVertex, unsigned int> VertexToOutIndex;

    for (unsigned int i = 0; i < in_vertices.size(); i++) {

        PackedVertex packed = { in_vertices[i], in_uvs[i], in_normals[i] };

        unsigned int index;
        bool found = getSimilarVertexIndex(packed, VertexToOutIndex, index);

        if (found) { // A similar vertex is already in the VBO, use it instead !
            out_indices.push_back(index);
        }
        else { // If it's not, it needs to be added in the output data.
            out_vertices.push_back(in_vertices[i]);
            out_uvs.push_back(in_uvs[i]);
            out_normals.push_back(-1.0f*in_normals[i]);
            unsigned int newindex = (unsigned int)out_vertices.size() - 1;
            out_indices.push_back(newindex);
            VertexToOutIndex[packed] = newindex;
        }
    }
}

bool loadOBJ(
    const char* path,
    std::vector<glm::vec3>& out_vertices,
    std::vector<glm::vec2>& out_uvs,
    std::vector<glm::vec3>& out_normals,
    std::vector<unsigned int>& out_indices
) {
    printf("Loading OBJ file %s...\n", path);

    std::vector<unsigned int> vertexIndices, uvIndices, normalIndices;
    std::vector<glm::vec3> temp_vertices;
    std::vector<glm::vec2> temp_uvs;
    std::vector<glm::vec3> temp_normals;

    FILE* file = fopen(path, "r");
    if (file == NULL) {
        printf("Impossible to open the file ! Are you in the right path ?\n");
        getchar();
        return false;
    }

    while (1) {

        char lineHeader[128];
        // read the first word of the line
        int res = fscanf(file, "%s", lineHeader);
        if (res == EOF)
            break; // EOF = End Of File. Quit the loop.

        if (strcmp(lineHeader, "v") == 0) {
            glm::vec3 vertex;
            fscanf(file, "%f %f %f\n", &vertex.x, &vertex.y, &vertex.z);
            temp_vertices.push_back(vertex);
        }
        else if (strcmp(lineHeader, "vt") == 0) {
            glm::vec2 uv;
            fscanf(file, "%f %f\n", &uv.x, &uv.y);
            uv.y = -uv.y; // Invert V coordinate since we will only use DDS texture, which are inverted. Remove if you want to use TGA or BMP loaders.
            temp_uvs.push_back(uv);
        }
        else if (strcmp(lineHeader, "vn") == 0) {
            glm::vec3 normal;
            fscanf(file, "%f %f %f\n", &normal.x, &normal.y, &normal.z);
            temp_normals.push_back(normal);
        }
        else if (strcmp(lineHeader, "f") == 0) {
            std::string vertex1, vertex2, vertex3;
            unsigned int vertexIndex[3], uvIndex[3], normalIndex[3];
            int matches = fscanf(file, "%d/%d/%d %d/%d/%d %d/%d/%d\n", &vertexIndex[0], &uvIndex[0], &normalIndex[0], &vertexIndex[1], &uvIndex[1], &normalIndex[1], &vertexIndex[2], &uvIndex[2], &normalIndex[2]);
            if (matches != 9) {
                printf("File can't be read by our simple parser :-( Try exporting with other options\n");
                return false;
            }
            vertexIndices.push_back(vertexIndex[0]);
            vertexIndices.push_back(vertexIndex[1]);
            vertexIndices.push_back(vertexIndex[2]);

            uvIndices.push_back(uvIndex[0]);
            uvIndices.push_back(uvIndex[1]);
            uvIndices.push_back(uvIndex[2]);
            normalIndices.push_back(normalIndex[0]);
            normalIndices.push_back(normalIndex[1]);
            normalIndices.push_back(normalIndex[2]);
        }
        else {
            // Probably a comment, eat up the rest of the line
            char stupidBuffer[1000];
            fgets(stupidBuffer, 1000, file);
        }
    }

    // For each vertex of each triangle
    std::vector<glm::vec3> temp_out_vertices;
    std::vector<glm::vec2> temp_out_uvs;
    std::vector<glm::vec3> temp_out_normals;

    for (unsigned int i = 0; i < vertexIndices.size(); i++) {
        // Get the indices of its attributes
        unsigned int vertexIndex = vertexIndices[i];
        unsigned int uvIndex = uvIndices[i];
        unsigned int normalIndex = normalIndices[i];

        // Get the attributes thanks to the index
        glm::vec3 vertex = temp_vertices[vertexIndex - 1];
        glm::vec2 uv = temp_uvs[uvIndex - 1];
        glm::vec3 normal = temp_normals[normalIndex - 1];

        // Put the attributes in buffers
        temp_out_vertices.push_back(vertex);
        temp_out_uvs.push_back(uv);
        temp_out_normals.push_back(normal);
    }

    indexVBO(temp_out_vertices, temp_out_uvs, temp_out_normals, out_indices, out_vertices, out_uvs, out_normals);

    fclose(file);
    return true;
}
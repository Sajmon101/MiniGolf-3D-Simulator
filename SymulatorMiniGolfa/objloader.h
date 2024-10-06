#ifndef OBJLOADER_H
#define OBJLOADER_H
#include <map>

bool loadOBJ(
    const char* path,
    std::vector<glm::vec3>& out_vertices,
    std::vector<glm::vec2>& out_uvs,
    std::vector<glm::vec3>& out_normals,
    std::vector<unsigned int>& vertexIndices
);

struct PackedVertex {
    glm::vec3 position;
    glm::vec2 uv;
    glm::vec3 normal;
    bool operator<(const PackedVertex that) const {
        return memcmp((void*)this, (void*)&that, sizeof(PackedVertex)) > 0;
    }
};

bool getSimilarVertexIndex(
    PackedVertex& packed,
    std::map<PackedVertex, unsigned int>& VertexToOutIndex,
    unsigned int& result
);

void indexVBO(
    std::vector<glm::vec3>& in_vertices,
    std::vector<glm::vec2>& in_uvs,
    std::vector<glm::vec3>& in_normals,

    std::vector<unsigned int>& out_indices,
    std::vector<glm::vec3>& out_vertices,
    std::vector<glm::vec2>& out_uvs,
    std::vector<glm::vec3>& out_normals
);
#endif
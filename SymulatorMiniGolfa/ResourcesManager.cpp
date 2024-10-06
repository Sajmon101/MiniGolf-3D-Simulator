#include "ResourcesManager.h"

void ResourceManager::LoadTexture(const std::string& name, const char* filePath) {
    // Implementacja ³adowania tekstury
}

Texture* ResourceManager::GetTexture(const std::string& name) {
    auto it = textures.find(name);
    if (it != textures.end()) {
        return &it->second;
    }
    return nullptr;
}

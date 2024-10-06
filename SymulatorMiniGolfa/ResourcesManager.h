#pragma once
#include <string>
#include "Texture.h"
#include <unordered_map>
class ResourceManager {
public:
    void LoadTexture(const std::string& name, const char* filePath);
    Texture* GetTexture(const std::string& name);

    // ... (inne metody zarz¹dzania teksturami)

private:
    std::unordered_map<std::string, Texture> textures;
};

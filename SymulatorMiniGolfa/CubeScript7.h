#pragma once
#include "Component.h"
#include "BoxCollider.h"
#include "BallScript.h"

class CubeScript7 : public Component //nie zapomnieæ o tym dziedziczeniu
{
public:
    CubeScript7(GameObject* gameObject);
    void Start();
    void Update(bool* keys) override;

    //here variables and functions for your script

private:
    //here variables and functions for your script
    Texture texture;
    Material material;
    glm::vec3 moveDir = glm::vec3(0.005f, 0.0f, 0.0f);
    int counter = 0;
    BoxCollider* thiscollider = nullptr;
    BallScript* ballScript = nullptr;

    GameObject* ball = nullptr;
    glm::vec3 normal = glm::vec3(0);
};

#pragma once
#include "Component.h"

class CubeScript4 : public Component //nie zapomnie� o tym dziedziczeniu
{
public:
    CubeScript4(GameObject* gameObject);
    void Start();
    void Update(bool* keys) override;

    //here variables and functions for your script

private:
    //here variables and functions for your script
    Texture texture;
    Material material;
};


#pragma once
#pragma once
#include "Component.h"

class CubeScript3 : public Component //nie zapomnie� o tym dziedziczeniu
{
public:
    CubeScript3(GameObject* gameObject);
    void Start();
    void Update(bool* keys) override;

    //here variables and functions for your script

private:
    //here variables and functions for your script
    Texture texture;
    Material material;
};


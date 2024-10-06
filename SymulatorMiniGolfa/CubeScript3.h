#pragma once
#pragma once
#include "Component.h"

class CubeScript3 : public Component //nie zapomnieæ o tym dziedziczeniu
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


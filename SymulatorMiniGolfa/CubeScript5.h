#pragma once
#include "Component.h"

class CubeScript5 : public Component //nie zapomnieæ o tym dziedziczeniu
{
public:
    CubeScript5(GameObject* gameObject);
    void Start();
    void Update(bool* keys) override;

    //here variables and functions for your script

private:
    //here variables and functions for your script
    Texture texture;
    Material material;
};


#pragma once
#include "Component.h"

class WindMill : public Component //nie zapomnie� o tym dziedziczeniu
{
public:
    WindMill(GameObject* gameObject);
    void Start();
    void Update(bool* keys) override;

    //here variables and functions for your script

private:
    //here variables and functions for your script
    Texture texture;
    Material material;
};

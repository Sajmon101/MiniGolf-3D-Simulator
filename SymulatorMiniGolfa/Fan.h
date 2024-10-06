#pragma once
#include "Component.h"

class Fan : public Component //nie zapomnieæ o tym dziedziczeniu
{
public:
    Fan(GameObject* gameObject);
    void Start();
    void Update(bool* keys) override;

    //here variables and functions for your script

private:
    //here variables and functions for your script
    Texture texture;
    Material material;
};
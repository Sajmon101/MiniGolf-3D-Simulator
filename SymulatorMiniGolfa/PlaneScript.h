#pragma once
#include "Component.h"

class PlaneScript : public Component
{
public:
    PlaneScript(GameObject* gameObject);
    void Start();
    void Update(bool* keys) override;

    //here variables and functions for your script

private:
    //here variables and functions for your script

};


#pragma once
#include "Component.h"
#include "Texture.h"
#include "BallScript.h"

class ClubScript : public Component
{
public:
    ClubScript(GameObject* gameObject);
    void Start() override;
    void Update(bool* keys) override;

    //here variables and functions for your script

    bool endAction = true;
    float angle = 0.0f;
    float sumAngle;
    float returnAngle;
    BallScript* ball;
private:
    //here variables and functions for your script
    
    bool flag;
    bool spaceDown;
};


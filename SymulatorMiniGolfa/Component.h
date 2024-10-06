#pragma once
#include "GameObject.h"
#include "Texture.h"

class GameObject;
class Component {
public:
    Component(GameObject* gameObject);

    virtual void Start();
    virtual void Update(bool* keys);

protected:
    GameObject* gameObject;
};
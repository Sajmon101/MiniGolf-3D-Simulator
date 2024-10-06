#pragma once
#include "Component.h"

class BoxCollider : public Component //nie zapomnieæ o tym dziedziczeniu
{
public:
    BoxCollider(GameObject* gameObject);
    ~BoxCollider();
    void Start();
    void Update(bool* keys) override;

    static const std::vector<BoxCollider*>& getAllColliders();
    glm::vec3 checkCollision(glm::vec3 collPosition, glm::vec3 collSize);
    glm::vec3 getNormal(glm::vec3 ballPosition) const;


    glm::vec3 size; // rozmiar collidera
    glm::vec3 position; // Pozycja œrodka collidera
private:
   


    static std::vector<BoxCollider*> allColliders;
};

#include "BoxCollider.h"

BoxCollider::BoxCollider(GameObject* gameObject) : Component(gameObject) {

	allColliders.push_back(this);
}

BoxCollider::~BoxCollider() {
    allColliders.erase(std::remove(allColliders.begin(), allColliders.end(), this), allColliders.end());
}

void BoxCollider::Start()
{
	position = gameObject->GetPosition();
	size = gameObject->GetScale();
}


void BoxCollider::Update(bool* keys)
{
    position = gameObject->GetPosition();
}

const std::vector<BoxCollider*>& BoxCollider::getAllColliders() {
    return allColliders;
}

glm::vec3 BoxCollider::checkCollision(glm::vec3 collPosition, glm::vec3 collSize) {

    bool collisionX = collPosition.x + collSize.x / 2 >= position.x - size.x / 2 &&
        position.x + size.x / 2 >= collPosition.x - collSize.x / 2;
    bool collisionY = collPosition.y + collSize.y / 2 >= position.y - size.y / 2 &&
        position.y + size.y / 2 >= collPosition.y - collSize.y / 2;
    bool collisionZ = collPosition.z + collSize.z / 2 >= position.z - size.z / 2 &&
        position.z + size.z / 2 >= collPosition.z - collSize.z / 2;

    if (collisionX && collisionY && collisionZ)
    {
        glm::vec3 normal = getNormal(collPosition);
        return normal;
    }
    else return glm::vec3(0);

    
}

glm::vec3 BoxCollider::getNormal(glm::vec3 ballPosition) const {

    glm::vec3 normal = glm::vec3(0);
    glm::vec3 diff = ballPosition - this->position;

    if (diff.x > -this->size.x / 2 - 0.15f && diff.x < -this->size.x / 2 + 0.15f) {
        normal = glm::vec3(1.0f, 0.0f, 0.0f);
    }
    else if (diff.x < this->size.x / 2 + 0.15f && diff.x > this->size.x / 2 - 0.15f) {
        normal = glm::vec3(-1.0f, 0.0f, 0.0f);
    }

    if (diff.z > -this->size.z / 2 - 0.15f && diff.z < -this->size.z / 2 + 0.15f) {
        normal = glm::vec3(0.0f, 0.0f, 1.0f);
    }
    else if (diff.z < this->size.z / 2 + 0.15f && diff.z > this->size.z / 2 - 0.15f) {
        normal = glm::vec3(0.0f, 0.0f, -1.0f);
    }

    // Upewnij siê, ¿e normalna nie jest zerowa, jeœli dosz³o do kolizji
    return glm::length(normal) > 0.0f ? normal : glm::vec3(0.0f);
}
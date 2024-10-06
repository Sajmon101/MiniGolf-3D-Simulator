#pragma once
#include "Component.h"

class BallScript : public Component {
public:
    BallScript(GameObject* gameObject);
    void Update(bool *keys) override;
    void Start();

    float moveBall(GLfloat deltaTime, float totalTime, float force, const glm::vec3& direction);
    void CheckCollisions();
    void BallInHole(glm::vec3 ballPosition, glm::vec3 holePosition);
    
    glm::vec3 direction = glm::vec3(-1.0f, 0.0f, -1.0f);
    float force = 0.0f;
    glm::vec3 moveDirection;
    bool endAction = true;
    bool startMovement;

private:
    bool colliderHit = false;
    float currentTime = 0.0f;
    float deltaTime = 0.0f;
    float lastTime = 0.0f;
    float strengthOfSlowing = 2.0f;
    float t = 0.0f;
    float v = 0.0f;
    bool flag;
    bool spaceDown;
    
    
    
};

#pragma once
#include "Light.h"
class PointLight :
    public Light
{
public:
    PointLight();
    PointLight(GLfloat red, GLfloat green, GLfloat blue,
                GLfloat aIntensity, GLfloat dIntensity,
                GLfloat xPos, GLfloat yPos, GLfloat zPos,
                GLfloat con, GLfloat lin, GLfloat exp);

    void setPosition(const glm::vec3& pos);

    void setConstant(float constValue);

    void setLinear(float linearValue);

    void setExponent(float exponentValue);

    void UseLight(GLfloat ambientIntensityLocation, GLfloat ambientColourLocation,
        GLfloat diffuseIntensityLocation, GLfloat positionLocation,
        GLfloat constantLocation, GLfloat linearLocation, GLfloat exponentLocation);

    ~PointLight();

private:
    glm::vec3 position;

    GLfloat constant, linear, exponent;

};


#include "GameObject.h"

GameObject::GameObject(Scene* scene, const std::string& modelFilename) : m_scene(scene)
{
    mesh = modelLoader.loadModel(modelFilename);
}

GameObject::GameObject(Scene* scene, std::vector<glm::vec3> vertices, std::vector<glm::vec2> uvs, std::vector<glm::vec3> normals, std::vector<unsigned int> verticesIndices) : m_scene(scene)
{
    mesh = modelLoader.makeMesh(vertices, uvs, normals, verticesIndices);
}

void GameObject::update(float deltaTime)
{
}

void GameObject::setPosition(const glm::vec3& position) {
    this->position = position;
}

void GameObject::moveObject(const glm::vec3& moveVector)
{
    this->position += moveVector;
}

glm::vec3 GameObject::GetPosition() const{
    return position;
}

glm::vec3 GameObject::GetScale() const
{
    return scale;
}

void GameObject::setScale(const glm::vec3& scale) {
    this->scale = scale;
}

void GameObject::setRotation(float angleDegrees, const glm::vec3& axis) {
    totalRotationMatrix = glm::rotate(glm::mat4(1.0f), glm::radians(angleDegrees), axis);
}

void GameObject::applyTransformation(const glm::mat4& transformation) {
    this->additionalTransformation = transformation;
}

void GameObject::setTexture(Texture* texture) {
    this->texture = texture;
}

void GameObject::setTexturesByPath(const char* fileLoc, const char* fileLoc2)
{
    Texture* tempTexture = new Texture(fileLoc, fileLoc2); // Alokacja na stercie
    tempTexture->LoadTextures();
    setTexture(tempTexture);
    existTexture2 = true;
}

void GameObject::setTextureByPath(const char* fileLoc)
{
    Texture* tempTexture = new Texture(fileLoc); // Alokacja na stercie
    tempTexture->LoadTexture();
    setTexture(tempTexture);
    existTexture2 = false;
}

void GameObject::setMaterial(GLfloat sIntensity, GLfloat shine) {
    Material* material = new Material(sIntensity, shine);
    this->material = material;
}

void GameObject::rotateObject(float angleDegrees, const glm::vec3& axis, const glm::vec3& centerPoint)
{
    // Przesuñ obiekt do nowego œrodka obrotu
    glm::mat4 translateToCenter = glm::translate(glm::mat4(1.0f), centerPoint);

    // Wykonaj obrót wokó³ nowej osi
    glm::mat4 rotation = glm::rotate(glm::mat4(1.0f), glm::radians(angleDegrees), axis);

    // Przesuñ obiekt z powrotem
    glm::mat4 translateBack = glm::translate(glm::mat4(1.0f), -centerPoint);

    // Po³¹cz transformacje
    totalRotationMatrix = translateToCenter * rotation * translateBack * totalRotationMatrix;
}

void GameObject::render(Shader& shader)
{
    glm::mat4 model = glm::mat4(1.0f);
    model = glm::translate(model, position);
    model *= totalRotationMatrix; //dodaj rotacjê
    model = glm::scale(model, scale);
    model = additionalTransformation * model;
    shader.setModelMatrix(model);

    if (material) shader.UseMaterial(*material);
    if (texture && !existTexture2) texture->UseTexture();
    if (texture && existTexture2) texture->UseTextures();

    mesh->RenderMesh();
}

void GameObject::AddComponent(Component* component) {
    components.push_back(component);
    component->Start();
}

void GameObject::Update(bool* keys) {
    for (auto& comp : components) {
        comp->Update(keys);
    }
}

Scene* GameObject::getScene() const {
    return m_scene; 
}

GameObject::~GameObject() {
    delete material;
    material = nullptr;
}


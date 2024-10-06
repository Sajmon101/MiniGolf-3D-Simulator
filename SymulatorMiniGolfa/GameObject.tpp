template <typename T>
T* GameObject::getComponent() {
    for (Component* comp : components) {
        if (T* casted = dynamic_cast<T*>(comp)) {
            return casted;
        }
    }
    return nullptr;
}
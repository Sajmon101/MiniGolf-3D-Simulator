#include "KeyboardManager.h"

void KeyboardManager::updateKeyState(int key, bool isPressed) {
    keyStates[key] = isPressed;
}

bool KeyboardManager::isKeyPressed(int key) const {
    auto it = keyStates.find(key);
    if (it != keyStates.end()) {
        return it->second;
    }
    return false;
}
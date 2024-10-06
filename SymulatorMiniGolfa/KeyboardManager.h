#pragma once
#include <map>
class KeyboardManager
{
public:
	void updateKeyState(int key, bool isPressed);
	bool isKeyPressed(int key) const;

private:
	std::map<int, bool> keyStates;
};


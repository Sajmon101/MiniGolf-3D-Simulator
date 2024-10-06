#include "ComponentTemplate.h"

ComponentTemplate::ComponentTemplate(GameObject* gameObject) : Component(gameObject) {}

void ComponentTemplate::Start()
{
	//Przyk³adowe pobranie obiektu ze sceny na której jest równie¿ gameObject czyli obiekt do którego przypiêty jest skrypt
	//ball = gameObject->getScene()->getGameObject("ball");
}


void ComponentTemplate::Update(bool* keys)
{
}
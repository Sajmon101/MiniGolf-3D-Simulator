#include "ComponentTemplate.h"

ComponentTemplate::ComponentTemplate(GameObject* gameObject) : Component(gameObject) {}

void ComponentTemplate::Start()
{
	//Przyk�adowe pobranie obiektu ze sceny na kt�rej jest r�wnie� gameObject czyli obiekt do kt�rego przypi�ty jest skrypt
	//ball = gameObject->getScene()->getGameObject("ball");
}


void ComponentTemplate::Update(bool* keys)
{
}
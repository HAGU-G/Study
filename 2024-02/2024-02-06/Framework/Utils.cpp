#include "pch.h"
#include "Utils.h"


void Utils::SetOrigin(sf::Transformable& obj, Origins originPreset, const sf::FloatRect& rect)
{
	sf::Vector2f newOrigin(rect.width, rect.height);

	newOrigin.x *= (int)originPreset % 3 * 0.5f;
	newOrigin.y *= (int)originPreset / 3 * 0.5f;

	obj.setOrigin(newOrigin);
}

void Utils::SetOrigin(sf::Sprite& obj, Origins originPreset)
{
	SetOrigin(obj, originPreset, obj.getLocalBounds());
}


void Utils::SetOrigin(sf::Shape& obj, Origins originPreset)
{
	SetOrigin(obj, originPreset, obj.getLocalBounds());
}

void Utils::SetOrigin(sf::Text& obj, Origins originPreset)
{
	SetOrigin(obj, originPreset, obj.getLocalBounds());
}

float Utils::RandomValue()
{
	return (float)rand()/RAND_MAX;
}


float Utils::RandomRange(float min, float max)
{
	float value = RandomValue();
	value *= max - min;
	value += min;


	return value;
}

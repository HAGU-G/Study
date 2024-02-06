#pragma once
#include<SFML/Graphics.hpp>
#include "Defines.h"

class Utils
{
private:

public:
	static void SetOrigin(sf::Transformable& obj, Origins originPreset, const sf::FloatRect& rect);
	static void SetOrigin(sf::Sprite& obj, Origins originPreset);
	static void SetOrigin(sf::Shape& obj, Origins originPreset);
	static void SetOrigin(sf::Text& obj, Origins originPreset);

};
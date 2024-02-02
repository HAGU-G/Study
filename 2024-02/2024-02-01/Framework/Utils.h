#pragma once
#include<SFML/Graphics.hpp>
enum class Origins
{
	// T M B
	// L C R
	TL, TC, TR,
	ML, MC, MR,
	BL, BC, BR
};

class Utils
{
private:

public:
	static void SetOrigin(sf::Transformable& obj, Origins originPreset, const sf::FloatRect& rect);
	static void SetOrigin(sf::Sprite& obj, Origins originPreset);
	static void SetOrigin(sf::Shape& obj, Origins originPreset);
	static void SetOrigin(sf::Text& obj, Origins originPreset);

};
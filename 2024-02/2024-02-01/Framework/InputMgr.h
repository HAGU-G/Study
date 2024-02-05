#pragma once
#include <list>
#include <SFML/Graphics.hpp>

class InputMgr
{
private:
	static std::list<sf::Keyboard::Key> downList;
	static std::list<sf::Keyboard::Key> upList;
	static std::list<sf::Keyboard::Key> ingList;
public:
	static void UpdateEvent(const sf::Event& ev);
	static void Clear();

	static bool GetKeyDown(sf::Keyboard::Key key);
	static bool GetKeyUp(sf::Keyboard::Key key);
	static bool GetKey(sf::Keyboard::Key key);
};


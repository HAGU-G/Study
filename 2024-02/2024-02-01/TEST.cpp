
#include <SFML/Graphics.hpp>
#include <iostream>

int main()
{
	sf::VideoMode vm(500, 500);
	sf::RenderWindow window(vm, "SFML works!");

	sf::Texture texture1;
	texture1.loadFromFile("graphics/player.png");
	sf::Sprite sprite1;
	sprite1.setTexture(texture1);
	sprite1.setOrigin(texture1.getSize().x / 2, texture1.getSize().y);
	sprite1.setPosition(250, 500);

	sf::Texture texture2;
	texture2.loadFromFile("graphics/rip.png");
	sf::Sprite sprite2;
	sprite2.setTexture(texture2);
	sprite2.setOrigin(texture2.getSize().x / 2, texture2.getSize().y);
	sprite2.setPosition(250, 500);


	int a = 0;
	sf::Clock clock;
	while (window.isOpen())
	{
		float dt = sf::Time(clock.restart()).asSeconds();
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		if (event.type == sf::Event::KeyReleased)
		{
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
			{
				a = 1;
				sprite1.setPosition(sprite1.getPosition().x, sprite1.getPosition().y - 1);
			}
	}


		window.clear();
		window.draw(sprite1);
		if(a!=0)
			window.draw(sprite2);
		window.display();

	}


	return 0;
}

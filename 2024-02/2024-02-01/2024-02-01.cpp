// Timber
// 바로 게임 시작
// 시간은 계속 줄어든다.
// 나무를 패면 시간이 늘어난다.
#include <SFML/Graphics.hpp>
#include <iostream>

int main()
{
	sf::VideoMode vm(1920, 1080);
	sf::RenderWindow window(vm, "SFML works!");

	sf::Texture texBackground;
	texBackground.loadFromFile("graphics/background.png");
	sf::Sprite spriteBackground;
	spriteBackground.setTexture(texBackground);
	spriteBackground.setPosition(0, 0);

	sf::Texture texCloud;
	texCloud.loadFromFile("graphics/cloud.png");
	sf::Sprite spCloud;
	spCloud.setTexture(texCloud);
	spCloud.setPosition(0, 0);
	spCloud.setOrigin(texCloud.getSize().x/2, texCloud.getSize().y / 2);

	sf::Texture texBee;
	texBee.loadFromFile("graphics/bee.png");
	sf::Sprite spBee;
	spBee.setTexture(texBee);
	spBee.setPosition(960, 540);
	spBee.setOrigin(texBee.getSize().x/2, texBee.getSize().y / 2);

	sf::Texture texTree;
	texTree.loadFromFile("graphics/tree.png");
	sf::Sprite spTree;
	spTree.setTexture(texTree);
	spTree.setPosition(vm.width / 2, 0);
	spTree.setOrigin(texTree.getSize().x / 2, 0);



	srand(time(NULL));
	float beeSpeed = 100.f;
	sf::Vector2f beeDirection(1.f, 0.f);
	
	sf::Vector2f cloud1Postion(1920 / 2, 100);
	sf::Vector2f cloud2Postion(1920/2, 300);
	sf::Vector2f cloud3Postion(1920 / 2, 500);
	float cloudSpeed1 = 1000.f * rand() / RAND_MAX;
	float cloudSpeed2 = 1000.f * rand() / RAND_MAX;
	float cloudSpeed3 = 1000.f * rand() / RAND_MAX;
	sf::Vector2f cloudDirection1(rand() % 3 - 1, 0);
	sf::Vector2f cloudDirection2(rand() % 3 - 1, 0);
	sf::Vector2f cloudDirection3(rand() % 3 - 1, 0);


	sf::Vector2f ddd(1, 0);
	sf::Transform rotation;
	ddd = rotation.rotate(360.f * rand() / RAND_MAX) * ddd;



	sf::Clock clock;
	sf::Clock second1;

	while (window.isOpen())
	{
		//1초마다 시간 초기화
		if (sf::Time(second1.getElapsedTime()).asSeconds() >= 1)
		{
			second1.restart();
			beeDirection = rotation.rotate(360.f * rand() / RAND_MAX) * beeDirection;
			
		}

		
		//
		sf::Time dt = clock.restart();
		float deltaTime = dt.asSeconds();


		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		//Handle User Input
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		{
			window.close();
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			beeDirection = sf::Vector2f(-1.f, 0.f);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			beeDirection = sf::Vector2f(1.f, 0.f);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		{
			beeSpeed += 1.f;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		{
			beeSpeed -= 1.f;
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad0))
		{
			cloudDirection1 = sf::Vector2f(rand() % 3 - 1, 0);
			cloudDirection2 = sf::Vector2f(rand() % 3 - 1, 0);
			cloudDirection3 = sf::Vector2f(rand() % 3 - 1, 0);
			cloudSpeed1 = 1000.f * rand() / RAND_MAX;
			cloudSpeed2 = 1000.f * rand() / RAND_MAX;
			cloudSpeed3 = 1000.f * rand() / RAND_MAX;
			ddd = rotation.rotate(360.f * rand() / RAND_MAX) * ddd;
		}
	
		//Update

		spBee.setScale(beeDirection.x < 0 ? 1 : -1, 1);
		sf::Vector2f beePos = spBee.getPosition();
		beePos += beeDirection * beeSpeed * deltaTime;
		if (beePos.x > 1920)
			beePos.x -= 1920;
		if (beePos.x < 0)
			beePos.x += 1920;
		if (beePos.y > 1080)
			beePos.y -= 1080;
		if (beePos.y < 0)
			beePos.y += 1080;
		spBee.setPosition(beePos);

		cloud1Postion += cloudDirection1 * cloudSpeed1 * deltaTime;
		cloud2Postion += cloudDirection2 * cloudSpeed2 * deltaTime;
		cloud3Postion += cloudDirection3 * cloudSpeed3 * deltaTime;
		
		if (cloud1Postion.x > 1920)
			cloud1Postion.x -= 1920;
		if (cloud2Postion.x > 1920)
			cloud2Postion.x -= 1920;
		if (cloud3Postion.x > 1920)
			cloud3Postion.x -= 1920;

		if (cloud1Postion.x < 0)
			cloud1Postion.x += 1920;
		if (cloud2Postion.x < 0)
			cloud2Postion.x += 1920;
		if (cloud3Postion.x < 0)
			cloud3Postion.x += 1920;


			//draw
		{
			//background
			window.clear();
			window.draw(spriteBackground);


			//L1
			spCloud.setPosition(cloud1Postion);
			window.draw(spCloud);
			spCloud.setPosition(cloud2Postion);
			window.draw(spCloud);
			spCloud.setPosition(cloud3Postion);
			window.draw(spCloud);

			//L2
			window.draw(spTree);

			//L3
			window.draw(spBee);

		}
		window.display();

	}


	return 0;
}

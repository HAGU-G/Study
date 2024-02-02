// Timber
// 바로 게임 시작
// 시간은 계속 줄어든다.
// 나무를 패면 시간이 늘어난다.
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Framework/Defines.h"
#include <sstream>

int main()
{
	srand(time(NULL));
	sf::VideoMode vm(1920, 1080);
	sf::RenderWindow window(vm, "SFML works!",sf::Style::Fullscreen);

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
	spCloud.setOrigin(spCloud.getLocalBounds().width/2, 0);

	sf::Texture texBee;
	texBee.loadFromFile("graphics/bee.png");
	sf::Sprite spBee;
	spBee.setTexture(texBee);
	spBee.setPosition(1920 * rand() / RAND_MAX, 500 + 200 * rand() / RAND_MAX);
	Utils::SetOrigin(spBee, Origins::MC);

	sf::Texture texTree;
	texTree.loadFromFile("graphics/tree.png");
	sf::Sprite spTree;
	spTree.setTexture(texTree);
	spTree.setPosition(vm.width / 2, 0);
	spTree.setOrigin(texTree.getSize().x / 2, 0);



	float wind = 1 - (rand() % 2 * 2);
	float beeSpeed = 100.f + 30.f * rand() / RAND_MAX;
	sf::Vector2f beeDirection(-1, 0.f);
	spBee.setScale(1, 1);

	sf::Vector2f cloud1Postion(1920 / 2, 100);
	sf::Vector2f cloud2Postion(1920 / 2, 200);
	sf::Vector2f cloud3Postion(1920 / 2, 300);
	float cloudSpeed1 = 1000.f * rand() / RAND_MAX;
	float cloudSpeed2 = 1000.f * rand() / RAND_MAX;
	float cloudSpeed3 = 1000.f * rand() / RAND_MAX;

	sf::Vector2f cloudDirection1(wind, 0);
	sf::Vector2f cloudDirection2(wind, 0);
	sf::Vector2f cloudDirection3(wind, 0);
	spCloud.setScale(-wind, 1);


	sf::Vector2f ddd(1, 0);

	sf::Font font;
	font.loadFromFile("fonts/KOMIKAP_.ttf");

	sf::Text textMessage;
	textMessage.setFont(font);
	textMessage.setString("Press ENTER to start");
	textMessage.setCharacterSize(75);
	textMessage.setFillColor(sf::Color::White);
	Utils::SetOrigin(textMessage, Origins::MC, textMessage.getLocalBounds());
	textMessage.setPosition(960, 540);
	textMessage.setOutlineThickness(5);



	int score = 0;
	sf::Text scoreMessage;
	scoreMessage.setFont(font);
	scoreMessage.setCharacterSize(100);
	scoreMessage.setFillColor(sf::Color::White);
	scoreMessage.setPosition(0, 0);
	scoreMessage.setOutlineThickness(5);



	sf::Clock clock;
	sf::Clock second1;
	float deltaTime = 0.f;
	float timeScale = 0.f;
	bool isStop = true;
	float randR = 0.f;
	float testtest = 0.f;

	sf::Vector2f timeBarSize(400, 80);
	sf::RectangleShape timeBar(timeBarSize);
	timeBar.setFillColor(sf::Color::Red);
	Utils::SetOrigin(timeBar, Origins::MC);
	timeBar.setPosition(1920 / 2, 1080 - 80);

	float timeBarDuration = 3.f;
	float timeBarSpeed =  - timeBarSize.x / timeBarDuration;
	float timeBarTimer = 0.f;

	bool spaceDown = false;

	bool isGameOver = false;
	int beeAerobatics = 1;
	int beeAccel = 0;
	beeDirection = sf::Transform().rotate(180.f*wind) * beeDirection;
	spBee.setRotation(180.f * wind);
	while (window.isOpen())
	{
		//시간 보정 최상위에 두기
		sf::Time dt = clock.restart();
		deltaTime = dt.asSeconds() * timeScale;

		timeBarTimer += deltaTime;
		if (timeBar.getSize().x > 0.f)
			timeBar.setSize(sf::Vector2f(timeBar.getSize().x + timeBarSpeed * deltaTime, timeBarSize.y));
		if (timeBar.getSize().x <= 0.f)
			timeBar.setSize(sf::Vector2f(0.f, timeBarSize.y));
		if (timeBar.getSize().x == 0.f)
		{
			isStop = true;
			isGameOver = true;
			timeScale = isStop ? 0.f : 1.f;
		}

		if (sf::Time(second1.getElapsedTime()).asSeconds() >= 0.5f * rand() / RAND_MAX + 1.5f && timeScale > 0)
		{
			second1.restart();
			randR = deltaTime * 360.f * rand() / RAND_MAX - (deltaTime * 180.f);
			beeAccel = 50.f * rand() / RAND_MAX - 40.f;
		}

		//벌이 비행 구역을 나갈 때 복귀방향을 정한다.
		if (spBee.getPosition().y < 400 && spBee.getPosition().y>390 && beeDirection.y < 0)
		{
			if (beeDirection.x < 0)
				beeAerobatics = 1;
			else
				beeAerobatics = -1;
		}
		if (spBee.getPosition().y < 860 && spBee.getPosition().y > 850 && beeDirection.y > 0)
		{
			if (beeDirection.x < 0)
				beeAerobatics = -1;
			else
				beeAerobatics = 1;
		}


		if (spBee.getPosition().y < 400)
		{
			if (beeSpeed < 1000.f)
				beeSpeed += 100 * deltaTime;
			if ((spBee.getRotation() < 350 && beeAerobatics == 1) || ((spBee.getRotation() > 190 || spBee.getRotation() <= 180) && beeAerobatics == -1))
			{

				beeDirection = sf::Transform().rotate(180 * deltaTime * timeScale * beeAerobatics) * beeDirection;
				spBee.setRotation(spBee.getRotation() + 180 * deltaTime * timeScale * beeAerobatics);
				randR = 0;
			}
		}
		else if (spBee.getPosition().y > 850)
		{
			
			if ((spBee.getRotation() > 10 && beeAerobatics == -1) || ((spBee.getRotation() < 170 || spBee.getRotation() >= 180) && beeAerobatics == 1))
			{
				if (beeSpeed < 1000.f)
					beeSpeed += 100 * deltaTime;
				if (spBee.getRotation() < 45 || spBee.getRotation() > 135)
				{

					beeDirection = sf::Transform().rotate(180 * deltaTime * timeScale * beeAerobatics) * beeDirection;
					spBee.setRotation(spBee.getRotation() + 180 * deltaTime * timeScale * beeAerobatics);
					randR = 0;
				}
			}
		}
		else
		{
			if (beeSpeed > 200.f)
				beeSpeed -= 500 * deltaTime;
			else if (beeSpeed >= 50.f && beeSpeed <=200.f)
				beeSpeed += beeAccel * deltaTime;
			else
				beeSpeed += 50.f *deltaTime;

			beeAerobatics = 0;
			beeDirection = sf::Transform().rotate(randR * timeScale) * beeDirection;
			spBee.setRotation(spBee.getRotation() + randR * timeScale);
		}
		//
		
		sf::Event event;
		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				window.close();
				break;
			case sf::Event::KeyPressed:
				if (event.key.code == sf::Keyboard::Enter)
				{
					isStop = !isStop;
					timeScale = isStop ? 0.f : 1.f;
					if (isGameOver)
					{
						timeBar.setSize(timeBarSize);
						score = 0;
						isGameOver = false;
						int wind2 = 1 - (rand() % 2 * 2);
						cloudDirection1.x = wind2;
						cloudDirection2.x = wind2;
						cloudDirection3.x = wind2;
						spCloud.setScale(-wind2, 1);
					}
				}
				if (event.key.code == sf::Keyboard::Space && !spaceDown)
				{
					spaceDown = true;
					if (timeScale > 0.f)
					{
						score += 1;
						if (timeBar.getSize().x < timeBarSize.x)
						timeBar.setSize(sf::Vector2f(timeBar.getSize().x - timeBarSpeed, timeBarSize.y));
						if (timeBar.getSize().x > timeBarSize.x)
							timeBar.setSize(timeBarSize);
					}
				}
				break;
			case sf::Event::KeyReleased:
				if (event.key.code == sf::Keyboard::Space)
				{
					spaceDown = false;
				}
				break;
			}
		}





		//Handle User Input******************************************************
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		{
			window.close();
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		{
			beeSpeed += 1.f;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		{
			beeSpeed -= 1.f;
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num0))
		{
			timeScale = 0.f;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1))
		{
			timeScale = 1.f;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2))
		{
			timeScale = 2.f;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num3))
		{
			timeScale = 3.f;
		}

		//Update

		if (beeDirection.x < 0 && beeAerobatics == 0)
		{
			spBee.setScale(1, 1);
		}
		else if (beeDirection.x > 0 && beeAerobatics == 0)
		{
			spBee.setScale(1, -1);
		}



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

		if (cloud1Postion.x > 1920 + spCloud.getLocalBounds().width/2)
		{
			cloud1Postion.x -= 1920 + spCloud.getLocalBounds().width;
			cloud1Postion.y = spCloud.getLocalBounds().height * rand() / RAND_MAX;
			cloudSpeed1 = 100.f+500.f * rand() / RAND_MAX;
		}
		if (cloud2Postion.x > 1920 + spCloud.getLocalBounds().width / 2)
		{
			cloud2Postion.x -= 1920 + spCloud.getLocalBounds().width;
			cloud2Postion.y = spCloud.getLocalBounds().height * rand() / RAND_MAX;
			cloudSpeed2 = 100.f + 500.f * rand() / RAND_MAX;
		}
		if (cloud3Postion.x > 1920 + spCloud.getLocalBounds().width / 2)
		{
			cloud3Postion.x -= 1920 + spCloud.getLocalBounds().width;
			cloud3Postion.y = spCloud.getLocalBounds().height * rand() / RAND_MAX;
			cloudSpeed3 = 100.f + 500.f * rand() / RAND_MAX;
		}

		if (cloud1Postion.x < 0 - spCloud.getLocalBounds().width / 2)
		{
			cloud1Postion.x += 1920 + spCloud.getLocalBounds().width;
			cloud1Postion.y = spCloud.getLocalBounds().height * rand() / RAND_MAX;
			cloudSpeed1 = 100.f + 500.f * rand() / RAND_MAX;
		}
		if (cloud2Postion.x < 0 - spCloud.getLocalBounds().width / 2)
		{
			cloud2Postion.x += 1920 + spCloud.getLocalBounds().width;
			cloud2Postion.y = spCloud.getLocalBounds().height * rand() / RAND_MAX;
			cloudSpeed2 = 100.f + 500.f * rand() / RAND_MAX;
		}
		if (cloud3Postion.x < 0 - spCloud.getLocalBounds().width / 2)
		{
			cloud3Postion.x += 1920 + spCloud.getLocalBounds().width;
			cloud3Postion.y = spCloud.getLocalBounds().height * rand() / RAND_MAX;
			cloudSpeed3 = 100.f + 500.f * rand() / RAND_MAX;
		}

		//draw

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

		if (isStop)
		{
			if (!isGameOver)
			{
				textMessage.setString("Press ENTER to start");
				Utils::SetOrigin(textMessage, Origins::MC, textMessage.getLocalBounds());
				textMessage.setPosition(960, 540);
			}
			else
			{
				textMessage.setString("GameOver");
				Utils::SetOrigin(textMessage, Origins::MC, textMessage.getLocalBounds());
				textMessage.setPosition(960, 540);
			}
				window.draw(textMessage);
		}


		std::stringstream ss;
		ss << "Score : " << score << " "<<beeSpeed;
		scoreMessage.setString(ss.str());
		window.draw(scoreMessage);

		window.draw(timeBar);

		window.display();

	}

	return 0;
}

// Timber, 2024-02-01 ~ 2024-02-
// 메뉴 없이 바로 게임 시작
// 시간은 계속 줄어든다.
// 나무를 패면 시간이 늘어난다.
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Framework/Defines.h"
#include "Framework/Utils.h"
#include "Framework/InputMgr.h"
#include <sstream>

void UpdateBranches();
void ResetBranches();

const int NUM_OF_BRANCHES = 6;
sf::Sprite branches[NUM_OF_BRANCHES];
Sides brancheSides[NUM_OF_BRANCHES];
Sides playerSide = Sides::RIGHT;

int main()
{
	srand(time(NULL));
	float windowWidth = 1920;
	float windowHeight = 1080;
	sf::VideoMode vm(windowWidth, windowHeight);
	sf::RenderWindow window(vm, "Timber", sf::Style::Fullscreen);
	sf::View view1(sf::FloatRect(0.f, 0.f, windowWidth, windowHeight));
	sf::View view2(sf::FloatRect(0.f, 0.f, windowWidth * 0.1f, windowHeight * 0.1f));
	view2.setViewport(sf::FloatRect(0.9f, 0.0f, 0.1f, 0.1f));

	//텍스쳐 & 폰트 
	sf::Texture texBackground;
	texBackground.loadFromFile("graphics/background.png");

	sf::Texture texCloud;
	texCloud.loadFromFile("graphics/cloud.png");

	sf::Texture texBee;
	texBee.loadFromFile("graphics/bee.png");

	sf::Texture texTree;
	texTree.loadFromFile("graphics/tree2.png");

	sf::Texture texBranch;
	texBranch.loadFromFile("graphics/branch.png");

	sf::Texture texPlayer;
	texPlayer.loadFromFile("graphics/player.png");

	sf::Texture texAxe;
	texAxe.loadFromFile("graphics/axe.png");

	sf::Font font;
	font.loadFromFile("fonts/KOMIKAP_.ttf");

	//스프라이트
	sf::Sprite spriteBackground;
	spriteBackground.setTexture(texBackground);
	spriteBackground.setPosition(0, 0);

	sf::Sprite spCloud;
	spCloud.setTexture(texCloud);
	spCloud.setPosition(0, 0);
	spCloud.setOrigin(spCloud.getLocalBounds().width / 2, 0);

	sf::Sprite spBee;
	spBee.setTexture(texBee);
	Utils::SetOrigin(spBee, Origins::MC);
	spBee.setPosition(1920.f * rand() / RAND_MAX, 500.f + 200.f * rand() / RAND_MAX);

	sf::Sprite spTree;
	spTree.setTexture(texTree);
	spTree.setOrigin(texTree.getSize().x / 2.f, 0);
	spTree.setPosition(vm.width / 2.f, 0);
	spBee.setScale(1, 1);

	for (int i = 0; i < NUM_OF_BRANCHES; ++i)
	{
		branches[i].setTexture(texBranch);
		branches[i].setPosition(500, 500);
		Utils::SetOrigin(branches[i], Origins::ML);
	}
	ResetBranches();

	sf::Sprite spPlayer;
	spPlayer.setTexture(texPlayer);
	spPlayer.setOrigin(-spTree.getLocalBounds().width * 0.53f, spPlayer.getTexture()->getSize().y);
	spPlayer.setPosition(windowWidth * 0.5f, spTree.getLocalBounds().height);
	spPlayer.setScale(1, 1);

	sf::Sprite spAxe;
	spAxe.setTexture(texAxe);
	spAxe.setOrigin(spAxe.getTexture()->getSize().x * 0.5f, 0);
	spAxe.setPosition(spPlayer.getGlobalBounds().left + spPlayer.getLocalBounds().width * 0.58f, spPlayer.getGlobalBounds().top + spPlayer.getLocalBounds().height * 0.73f);
	spAxe.setScale(1, -1);



	//스프라이트 움직임 
	float wind = 1.f - (rand() % 2 * 2);
	float beeSpeed = 100.f + 30.f * rand() / RAND_MAX;

	sf::Vector2f beeDirection(-1, 0.f);
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
	scoreMessage.setPosition(10, 0);
	scoreMessage.setOutlineThickness(5);
	scoreMessage.setString("Score : 0");


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
	timeBar.setPosition(1920.f / 2, 1080 - 80);

	float timeBarDuration = 3.f;
	float timeBarSpeed = -timeBarSize.x / timeBarDuration;

	bool spaceDown = false;

	bool isGameOver = false;
	int beeAerobatics = 1;
	float beeAccel = 10.f;
	beeDirection = sf::Transform().rotate(180.f * wind) * beeDirection;
	spBee.setRotation(180.f * wind);



	//sssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssss
	//sssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssss
	//sssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssss
	//sssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssss
	while (window.isOpen())
	{
		//시간 보정 최상위에 두기
		sf::Time dt = clock.restart();
		deltaTime = dt.asSeconds() * timeScale;
		int fps = 1 / deltaTime;
		view2.setCenter(spBee.getPosition());

		InputMgr::Clear();

		if (timeBar.getSize().x > 0.f)
			timeBar.setSize(sf::Vector2f(timeBar.getSize().x + timeBarSpeed * deltaTime, timeBarSize.y));

		if (timeBar.getSize().x <= 0.f)
			timeBar.setSize(sf::Vector2f(0.f, timeBarSize.y));

		if (timeBar.getSize().x == 0.f)
		{
			isGameOver = true;
			isStop = true;
			timeScale = 0.f;
		}

		if (sf::Time(second1.getElapsedTime()).asSeconds() >= 0.5f * rand() / RAND_MAX + 1.5f && timeScale > 0)
		{
			second1.restart();
			randR = deltaTime * 360.f * rand() / RAND_MAX - (deltaTime * 180.f);
			beeAccel = 35.f * rand() / RAND_MAX - 20.f;
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
			else if (beeSpeed >= 50.f && beeSpeed <= 200.f)
				beeSpeed += beeAccel * deltaTime;
			else
				beeSpeed += 50.f * deltaTime;

			beeAerobatics = 0;
			beeDirection = sf::Transform().rotate(randR * timeScale) * beeDirection;
			spBee.setRotation(spBee.getRotation() + randR * timeScale);
		}
		//

		sf::Event event;
		while (window.pollEvent(event))
		{
			InputMgr::UpdateEvent(event);

			switch (event.type)
			{
			case sf::Event::Closed:
				window.close();
				break;
			}
		}

		bool isMove = false;
		//Handle User Input******************************************************
		if (InputMgr::GetKeyDown(sf::Keyboard::Space))
		{
			if (timeScale > 0.f)
			{
				UpdateBranches();
				isMove = true;
			}
		}
		if (InputMgr::GetKeyDown(sf::Keyboard::Enter))
		{
			isStop = !isStop;
			timeScale = isStop ? 0.f : 1.f;
			if (isGameOver)
			{
				timeBar.setSize(timeBarSize);
				score = 0;
				ResetBranches();
				timeBarSpeed = -timeBarSize.x / 3.f;
				isGameOver = false;
				float wind2 = 1.f - (rand() % 2 * 2);
				cloudDirection1.x = wind2;
				cloudDirection2.x = wind2;
				cloudDirection3.x = wind2;
				spCloud.setScale(-wind2, 1);
			}
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		{
			window.close();
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
		if (InputMgr::GetKeyDown(sf::Keyboard::Right) && !isStop)
		{
			UpdateBranches();
			spPlayer.setScale(1, 1);
			playerSide = Sides::RIGHT;
			spAxe.setPosition(spPlayer.getGlobalBounds().left + spPlayer.getLocalBounds().width * 0.58f, spPlayer.getGlobalBounds().top + spPlayer.getLocalBounds().height * 0.73f);
			spAxe.setScale(1, -1);
			isMove = true;

		}
		if (InputMgr::GetKeyDown(sf::Keyboard::Left) && !isStop)
		{
			UpdateBranches();
			spPlayer.setScale(-1, 1);
			playerSide = Sides::LEFT;
			spAxe.setPosition(spPlayer.getGlobalBounds().left + spPlayer.getLocalBounds().width * 0.42f, spPlayer.getGlobalBounds().top + spPlayer.getLocalBounds().height * 0.73f);
			spAxe.setScale(-1, -1);
			isMove = true;

		}

		//Update
		if (isMove)
		{
			isMove = false;
			if (playerSide != brancheSides[NUM_OF_BRANCHES - 1])
			{
				score += 10;
				if (timeBar.getSize().x < timeBarSize.x)
					timeBar.setSize(sf::Vector2f(timeBar.getSize().x - timeBarSpeed, timeBarSize.y));
				if (timeBar.getSize().x > timeBarSize.x)
					timeBar.setSize(timeBarSize);
				std::stringstream ss;
				ss << "Score : " << score;
				scoreMessage.setString(ss.str());

				timeBarDuration = 2.0f * exp(-score / 200.f + 10) / (exp(-score / 200.f + 10) + 1) + 7.f * exp(-score / 100.f + 7) / (exp(-score / 100.f + 7) + 1) + 0.3f;
				timeBarSpeed = -timeBarSize.x / timeBarDuration;
			}
			else
			{
				isGameOver = true;
				isStop = true;
				timeScale = 0.f;
			}


		}


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

		if (cloud1Postion.x > 1920 + spCloud.getLocalBounds().width / 2)
		{
			cloud1Postion.x -= 1920 + spCloud.getLocalBounds().width;
			cloud1Postion.y = spCloud.getLocalBounds().height * rand() / RAND_MAX;
			cloudSpeed1 = 100.f + 500.f * rand() / RAND_MAX;
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



		float treeHalfWidth = spTree.getLocalBounds().width * 0.5f;
		float centerX = windowWidth * 0.5f;

		for (int i = 0; i < NUM_OF_BRANCHES; ++i)
		{
			float y = i * 150.f;

			switch (brancheSides[i])
			{
			case Sides::LEFT:
				branches[i].setScale(-1.f, 1.f);
				branches[i].setPosition(centerX - treeHalfWidth + 4.f, y);
				break;
			case Sides::RIGHT:
				branches[i].setScale(1.f, 1.f);
				branches[i].setPosition(centerX + treeHalfWidth - 4.f, y);
				break;
			default:

				branches[i].setPosition(-2000, -2000);
				break;
			}
		}



		//************************ draw *********************************
		window.clear();
		sf::View* vv[2] = { &view1, &view2 };
		for (int i = 0; i < 2; i++)
		{
			window.setView(*vv[i]);

			//background
			window.draw(spriteBackground);

			//L1 구름
			spCloud.setPosition(cloud1Postion);
			window.draw(spCloud);
			spCloud.setPosition(cloud2Postion);
			window.draw(spCloud);
			spCloud.setPosition(cloud3Postion);
			window.draw(spCloud);

			//L2 나무, 플레이어, 벌
			window.draw(spTree);
			for (int i = 0; i < NUM_OF_BRANCHES; ++i)
			{
				window.draw(branches[i]);

			}

			window.draw(spPlayer);
			window.draw(spAxe);
			window.draw(spBee);
		}
		//L3 메세지
		window.setView(view1);
		if (isStop)
		{
			if (!isGameOver)
			{
				textMessage.setString("\t    - PAUSE -\n\nPress ENTER to start");
				Utils::SetOrigin(textMessage, Origins::MC, textMessage.getLocalBounds());
				textMessage.setPosition(960, 440);
			}
			else
			{
				textMessage.setString("\t    GameOver\n\nPress ENTER to restart");
				Utils::SetOrigin(textMessage, Origins::MC, textMessage.getLocalBounds());
				textMessage.setPosition(960, 440);
			}
			window.draw(textMessage);
		}


		window.draw(scoreMessage);

		window.draw(timeBar);


		window.display();



	}

	return 0;
}

//**************************
void UpdateBranches()
{

	for (int i = NUM_OF_BRANCHES - 1; i > 0; i--)
	{
		brancheSides[i] = brancheSides[i - 1];
	}

	int side = rand() % 4;
	switch (side)
	{
	case 0:
		brancheSides[0] = Sides::LEFT;
		break;
	case 1:
		brancheSides[0] = Sides::RIGHT;
		break;
	default:
		brancheSides[0] = Sides::NONE;
		break;
	}
	//while (brancheSides[1] != Sides::NONE && brancheSides[0] != Sides::NONE && brancheSides[1] != brancheSides[0])
	//{
	//	side = rand() % 3;
	//	switch (side)
	//	{
	//	case 0:
	//		brancheSides[0] = Sides::LEFT;
	//		break;
	//	case 1:
	//		brancheSides[0] = Sides::RIGHT;
	//		break;
	//	default:
	//		brancheSides[0] = Sides::NONE;
	//		break;
	//	}
	//}
}

void ResetBranches()
{
	for (int i = 0; i < NUM_OF_BRANCHES; i++)
	{
		UpdateBranches();
	}
	brancheSides[NUM_OF_BRANCHES - 1] = Sides::NONE;
}
#include "pch.h"
#include "ObjectMessage.h"

ObjectMessage::ObjectMessage(const std::string& name)
:GameObject(name)
{
}

void ObjectMessage::Init()
{
	textMessage.setFont(*ResourceMgr<sf::Font>::Instance().Get("fonts/KOMIKAP_.ttf"));
	textMessage.setString("Press ENTER to start");
	textMessage.setCharacterSize(75);
	textMessage.setFillColor(sf::Color::White);
	Utils::SetOrigin(textMessage, Origins::MC, textMessage.getLocalBounds());
	textMessage.setPosition(960, 540);
	textMessage.setOutlineThickness(5);

	scoreMessage.setFont(*ResourceMgr<sf::Font>::Instance().Get("fonts/KOMIKAP_.ttf"));
	scoreMessage.setCharacterSize(100);
	scoreMessage.setFillColor(sf::Color::White);
	scoreMessage.setPosition(10, 0);
	scoreMessage.setOutlineThickness(5);
	scoreMessage.setString(textFormat + "0");
}

void ObjectMessage::Update(float dt, float& timeScale)
{
}

void ObjectMessage::Draw(sf::RenderWindow& window)
{
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
}

#include "pch.h"
#include "ObjectPlayer.h"

ObjectPlayer::ObjectPlayer(const std::string& name)
	:GameObject(name)
{
}

void ObjectPlayer::Init()
{
	player.setTexture(*ResourceMgr<sf::Texture>::Instance().Get("graphics/player.png"));
	axe.setTexture(*ResourceMgr<sf::Texture>::Instance().Get("graphics/axe.png"));

	player.setOrigin(-300 * 0.53f, player.getLocalBounds().height);
	player.setPosition(960, 900);

	axe.setOrigin(axe.getTexture()->getSize().x * 0.5f, 0);
	axe.setPosition(player.getGlobalBounds().left + player.getLocalBounds().width * 0.58f, player.getGlobalBounds().top + player.getLocalBounds().height * 0.73f);
	axe.setScale(1, -1);
}

void ObjectPlayer::Update(float dt, float& timeScale)
{
}

void ObjectPlayer::Draw(sf::RenderWindow& window)
{
	window.draw(player);
	window.draw(axe);
}

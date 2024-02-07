#include "pch.h"
#include "ObjectCloud.h"

int ObjectCloud::wind = 1;

ObjectCloud::ObjectCloud(const std::string& name)
	:GameObject(name)
{
}

void ObjectCloud::Init()
{
	speed = 30 + 200.f * rand() / RAND_MAX;
	sprite.setTexture(*ResourceMgr<sf::Texture>::Instance().Get("graphics/cloud.png"));
	Utils::SetOrigin(sprite, Origins::TC);
	sprite.setPosition(1920.f*rand()/RAND_MAX, sprite.getLocalBounds().height * rand() / RAND_MAX);
	sprite.setScale(-wind*1.2* (2*sprite.getLocalBounds().height - sprite.getPosition().y) / (2 * sprite.getLocalBounds().height), 1.2*(2*sprite.getLocalBounds().height-sprite.getPosition().y)/(2*sprite.getLocalBounds().height));
}

void ObjectCloud::Update(float dt, float& timeScale)
{
	sprite.setPosition(sprite.getPosition().x + wind * speed * dt*timeScale, sprite.getPosition().y);
	if (sprite.getPosition().x < 0 - sprite.getLocalBounds().width / 2)
	{
		sprite.setPosition(1920 + sprite.getLocalBounds().width / 2, sprite.getLocalBounds().height * rand() / RAND_MAX);
		sprite.setScale(-wind * 1.2 * (2 * sprite.getLocalBounds().height - sprite.getPosition().y) / (2 * sprite.getLocalBounds().height), 1.2 * (2 * sprite.getLocalBounds().height - sprite.getPosition().y) / (2 * sprite.getLocalBounds().height));
		speed = 30 + 200.f * rand() / RAND_MAX;
	}
	if (sprite.getPosition().x > 1920 + sprite.getLocalBounds().width / 2)
	{
		sprite.setPosition(0 - sprite.getLocalBounds().width / 2, sprite.getLocalBounds().height * rand() / RAND_MAX);
		sprite.setScale(-wind * 1.2 * (2 * sprite.getLocalBounds().height - sprite.getPosition().y) / (2 * sprite.getLocalBounds().height), 1.2 * (2 * sprite.getLocalBounds().height - sprite.getPosition().y) / (2 * sprite.getLocalBounds().height));
		speed = 30 + 200.f * rand() / RAND_MAX;
	}

}

void ObjectCloud::Draw(sf::RenderWindow& window)
{
	window.draw(sprite);
}

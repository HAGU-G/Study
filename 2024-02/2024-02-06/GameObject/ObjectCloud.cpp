#include "pch.h"
#include "ObjectCloud.h"
#include "Utils.h"

int ObjectCloud::wind = 1;

ObjectCloud::ObjectCloud(const std::string& name)
	:GameObject(name)
{
}

void ObjectCloud::Init()
{
	speed = 30 + 200.f * rand() / RAND_MAX;
	sprite.setTexture(*ResourceMgr<sf::Texture>::Instance().Get("graphics/cloud.png"));
	Utils::SetOrigin(sprite, Origins::BC);
	sprite.setPosition(1920.f*rand()/RAND_MAX, sprite.getLocalBounds().height+sprite.getLocalBounds().height * rand() / RAND_MAX);
	float r = Utils::RandomRange(0.5f, 1.2f);
	sprite.setScale(-wind*r, r);
}

void ObjectCloud::Update(float dt, float& timeScale)
{
	sprite.setPosition(sprite.getPosition().x + wind * speed * dt*timeScale, sprite.getPosition().y);
	float r = Utils::RandomRange(0.5f, 1.2f);
	if (sprite.getPosition().x < 0 - sprite.getLocalBounds().width / 2)
	{
		sprite.setPosition(1920 + sprite.getLocalBounds().width / 2, sprite.getLocalBounds().height+sprite.getLocalBounds().height * rand() / RAND_MAX);
		sprite.setScale(-wind * r, r);
		speed = 30 + 200.f * rand() / RAND_MAX;
	}
	if (sprite.getPosition().x > 1920 + sprite.getLocalBounds().width / 2)
	{
		sprite.setPosition(0 - sprite.getLocalBounds().width / 2, sprite.getLocalBounds().height+sprite.getLocalBounds().height * rand() / RAND_MAX);
		sprite.setScale(-wind * r, r);
		speed = 30 + 200.f * rand() / RAND_MAX;
	}

}

void ObjectCloud::Draw(sf::RenderWindow& window)
{
	window.draw(sprite);
}

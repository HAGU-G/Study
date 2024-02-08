#include "pch.h"
#include "ObjectNewBee.h"




ObjectNewBee::ObjectNewBee(const std::string& name)
	:GameObject(name), direction(1.f, 1.f), time(0)
{

}

void ObjectNewBee::Init()
{
	sf::Transform rotate;
	direction = rotate.rotate(360*Utils::RandomValue())* direction;
	sprite << *ResourceMgr<sf::Texture>::Instance().Get("graphics/bee.png");
	Utils::SetOrigin(sprite, Origins::MC);
	sprite.setPosition(1920 * Utils::RandomValue(), 1080 * Utils::RandomValue());
}


void ObjectNewBee::Update(float dt, float& timeScale)
{
	time += dt;
	if (time > 1.f)
	{
		time = 0;
		sf::Transform rotate;
		direction = rotate.rotate(360 * Utils::RandomValue()) * direction;
	}

	//원형 바운드
	if (sqrt(pow(960 - sprite.getPosition().x, 2) + pow(540 - sprite.getPosition().y, 2)) > 300)
	{
		sprite.setPosition(sprite.getPosition() + sf::Vector2f(960 - sprite.getPosition().x, 540 - sprite.getPosition().y) * dt* timeScale);
	}
	else
	{
		sprite.setPosition(sprite.getPosition() + direction * dt * 100.f * timeScale);
	}
	sprite.setScale(-1 * direction.x / abs(direction.x), 1);
}

void ObjectNewBee::Draw(sf::RenderWindow& window)
{
	window.draw(sprite);
}

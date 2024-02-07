#include "pch.h"
#include "ObjectBee.h"
#include "ObjectCloud.h"

ObjectBee::ObjectBee(const std::string& name)
	: GameObject(name), beeSpeed(0.f), beeDirection(-1, 0.f), beeAerobatics(1), beeAccel(10.f)
{
}

void ObjectBee::Init()
{
	sprite.setTexture(*ResourceMgr<sf::Texture>::Instance().Get("graphics/bee.png"));
	Utils::SetOrigin(sprite, Origins::MC);
	sprite.setPosition(1920.f * rand() / RAND_MAX, 500.f + 200.f * rand() / RAND_MAX);

	beeSpeed = 100.f + 30.f * rand() / RAND_MAX;
	beeDirection = sf::Transform().rotate(180.f * ObjectCloud::wind) * beeDirection;
	sprite.setRotation(180.f * ObjectCloud::wind);
}

void ObjectBee::Update(float dt, float& timeScale)
{

	//벌이 비행 구역을 나갈 때 복귀방향을 정한다.
	if (sprite.getPosition().y < 400 && sprite.getPosition().y>390 && beeDirection.y < 0)
	{
		if (beeDirection.x < 0)
			beeAerobatics = 1;
		else
			beeAerobatics = -1;
	}
	if (sprite.getPosition().y < 860 && sprite.getPosition().y > 850 && beeDirection.y > 0)
	{
		if (beeDirection.x < 0)
			beeAerobatics = -1;
		else
			beeAerobatics = 1;
	}

	if (sprite.getPosition().y < 400)
	{
		if (beeSpeed < 1000.f)
			beeSpeed += 100 * dt;
		if ((sprite.getRotation() < 350 && beeAerobatics == 1) || ((sprite.getRotation() > 190 || sprite.getRotation() <= 180) && beeAerobatics == -1))
		{

			beeDirection = sf::Transform().rotate(180 * dt * timeScale * beeAerobatics) * beeDirection;
			sprite.setRotation(sprite.getRotation() + 180 * dt * timeScale * beeAerobatics);
			randR = 0;
		}
	}
	else if (sprite.getPosition().y > 850)
	{

		if ((sprite.getRotation() > 10 && beeAerobatics == -1) || ((sprite.getRotation() < 170 || sprite.getRotation() >= 180) && beeAerobatics == 1))
		{
			if (beeSpeed < 1000.f)
				beeSpeed += 100 * dt;
			if (sprite.getRotation() < 45 || sprite.getRotation() > 135)
			{

				beeDirection = sf::Transform().rotate(180 * dt * timeScale * beeAerobatics) * beeDirection;
				sprite.setRotation(sprite.getRotation() + 180 * dt * timeScale * beeAerobatics);
				randR = 0;
			}
		}
	}
	else
	{
		if (beeSpeed > 200.f)
			beeSpeed -= 500 * dt;
		else if (beeSpeed >= 50.f && beeSpeed <= 200.f)
			beeSpeed += beeAccel * dt;
		else
			beeSpeed += 50.f * dt;

		beeAerobatics = 0;
		beeDirection = sf::Transform().rotate(randR * timeScale) * beeDirection;
		sprite.setRotation(sprite.getRotation() + randR * timeScale);
	}
	if (beeDirection.x < 0 && beeAerobatics == 0)
	{
		sprite.setScale(1, 1);
	}
	else if (beeDirection.x > 0 && beeAerobatics == 0)
	{
		sprite.setScale(1, -1);
	}
	sf::Vector2f beePos = sprite.getPosition();
	beePos += beeDirection * beeSpeed * dt * timeScale;
	if (beePos.x > 1920)
		beePos.x -= 1920;
	if (beePos.x < 0)
		beePos.x += 1920;
	if (beePos.y > 1080)
		beePos.y -= 1080;
	if (beePos.y < 0)
		beePos.y += 1080;
	sprite.setPosition(beePos);

}

void ObjectBee::Draw(sf::RenderWindow& window)
{
	window.draw(sprite);
}

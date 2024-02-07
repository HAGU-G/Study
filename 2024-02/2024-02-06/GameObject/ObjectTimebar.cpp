#include "pch.h"
#include "ObjectTimebar.h"

ObjectTimebar::ObjectTimebar(const std::string& name)
	: GameObject(name), timeBarSize(400,80), timeBar(timeBarSize)
{
	timeBar.setFillColor(sf::Color::Red);
	Utils::SetOrigin(timeBar, Origins::MC);
	timeBar.setPosition(1920.f / 2, 1080 - 80);

	timeBarSpeed = -timeBarSize.x / timeBarDuration;
}

void ObjectTimebar::Init()
{
}

void ObjectTimebar::Update(float dt, float& timeScale)
{
	if (timeBar.getSize().x > 0.f)
		timeBar.setSize(sf::Vector2f(timeBar.getSize().x + timeScale*timeBarSpeed * dt, timeBarSize.y));

	if (timeBar.getSize().x <= 0.f)
		timeBar.setSize(sf::Vector2f(0.f, timeBarSize.y));
}

void ObjectTimebar::Draw(sf::RenderWindow& window)
{
	window.draw(timeBar);
}

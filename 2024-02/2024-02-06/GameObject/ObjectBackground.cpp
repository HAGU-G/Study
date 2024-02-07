#include "pch.h"
#include "ObjectBackground.h"

ObjectBackground::ObjectBackground(const std::string& name)
	:GameObject(name)
{
}

void ObjectBackground::Init()
{
	sprite.setTexture(*ResourceMgr<sf::Texture>::Instance().Get("graphics/background.png"));
}

void ObjectBackground::Update(float dt, float& timeScale)
{
}

void ObjectBackground::Draw(sf::RenderWindow& window)
{
	window.draw(sprite);
}

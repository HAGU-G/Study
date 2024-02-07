#include "pch.h"
#include "ObjectBranch.h"

ObjectBranch::ObjectBranch(const std::string& name)
	: GameObject(name)
{
}

void ObjectBranch::Init()
{
	sprite.setTexture(*ResourceMgr<sf::Texture>::Instance().Get("graphics/branch.png"));
	Utils::SetOrigin(sprite, Origins::ML);

}

void ObjectBranch::Update(float dt, float& timeScale)
{
	switch (side)
	{
	case Sides::LEFT:
		sprite.setScale(-1.f, 1.f);
		sprite.setPosition(960 - 150 + 4.f, y * 150.f);
		break;
	case Sides::RIGHT:
		sprite.setScale(1.f, 1.f);
		sprite.setPosition(960 + 150 - 4.f, y * 150.f);
		break;
	default:

		sprite.setPosition(-2000, -2000);
		break;
	}
}

void ObjectBranch::Draw(sf::RenderWindow& window)
{
	window.draw(sprite);
}

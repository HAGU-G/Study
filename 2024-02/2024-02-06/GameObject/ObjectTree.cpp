#include "pch.h"
#include "ObjectTree.h"

ObjectTree::ObjectTree(const std::string& name)
	: GameObject(name)
{

}

void ObjectTree::Init()
{
	sprite.setTexture(*ResourceMgr<sf::Texture>::Instance().Get("graphics/tree2.png"));
	Utils::SetOrigin(sprite, Origins::TC);
	sprite.setPosition(960, 0);
}

void ObjectTree::Update(float dt, float& timeScale)
{
}

void ObjectTree::Draw(sf::RenderWindow& window)
{
	window.draw(sprite);
}

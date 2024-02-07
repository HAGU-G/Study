#include "pch.h"
#include "GameObject.h"

GameObject::GameObject(const std::string& name) : name(name)
{
}

GameObject::~GameObject()
{
}

void GameObject::Init()
{
}

void GameObject::Release()
{
}

void GameObject::Reset()
{
}

void GameObject::Update(float dt, float& timeScale)
{
}

void GameObject::Draw(sf::RenderWindow& window)
{
}

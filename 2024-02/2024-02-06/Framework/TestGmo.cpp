#include "pch.h"
#include "TestGmo.h"

TestGmo::TestGmo(const std::string& name) : GameObject(name)
{
}

void TestGmo::Init()
{
}

void TestGmo::Release()
{
}

void TestGmo::Reset()
{
}

void TestGmo::Update(float dt, float& timeScale)
{
}

void TestGmo::Draw(sf::RenderWindow& window)
{
	window.draw(text);
}

#include "pch.h"
#include "Scene.h"

Scene::Scene(SceneIds id) : id(id)
{

}

void Scene::Update(float dt)
{
	for (auto& obj : gameObjects)
	{
		obj->Update(dt);
	}

}

void Scene::Draw(sf::RenderWindow& window)
{
	for (auto& obj : gameObjects)
	{
		obj->Draw(window);
	}
}

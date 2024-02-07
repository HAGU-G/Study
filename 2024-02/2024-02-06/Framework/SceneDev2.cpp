#include "pch.h"
#include "SceneDev2.h"
#include "TestGmo.h"

SceneDev2::SceneDev2(SceneIds id) : Scene(id)
{
}

void SceneDev2::Init()
{
	TestGmo* obj = new TestGmo();

	ResourceMgr<sf::Font>& fontMgr = ResourceMgr<sf::Font>::Instance();
	fontMgr.Load("fonts/KOMIKAP_.ttf");
	obj->text.setFont(*fontMgr.Get("fonts/KOMIKAP_.ttf"));
	obj->text.setString("SceneDev2 : ");


	gameObjects.push_back(obj);
}

void SceneDev2::Release()
{
}

void SceneDev2::Enter()
{
}

void SceneDev2::Exit()
{
}


void SceneDev2::Update(float dt, float& timeScale)
{
	Scene::Update(dt, timeScale);

	if (InputMgr::GetKeyDown(sf::Keyboard::Space))
	{
		SceneMgr::Instance().ChangeScene(SceneIds::SceneTimber);
	}
}

#include "pch.h"
#include "SceneDev1.h"
#include "TestGmo.h"

SceneDev1::SceneDev1(SceneIds id) : Scene(id)
{
}

void SceneDev1::Init()
{
	TestGmo* obj = dynamic_cast<TestGmo*>(AddGo(new TestGmo("Message")));

	ResourceMgr<sf::Font>& fontMgr = ResourceMgr<sf::Font>::Instance();
	obj->text.setFont(*fontMgr.Get("fonts/KOMIKAP_.ttf"));
	obj->text.setString("SceneDev1 : ");
	

	//gameObjects.push_back(obj);
}

void SceneDev1::Release()
{
}

void SceneDev1::Enter()
{
}

void SceneDev1::Exit()
{
}

void SceneDev1::Update(float dt)
{
	Scene::Update(dt);

	if (InputMgr::GetKeyDown(sf::Keyboard::Space))
	{
		SceneMgr::Instance().ChangeScene(SceneIds::SceneDev2);
	}

	if (InputMgr::GetKeyDown(sf::Keyboard::Num1))
	{
		GameObject* findGo = FindGo("Message");
		findGo->SetActive(!findGo->GetActive());
	}
}

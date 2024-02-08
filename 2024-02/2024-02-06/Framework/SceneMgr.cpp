#include "pch.h"
#include "SceneMgr.h"
#include "SceneDev1.h"
#include "SceneDev2.h"
#include "SceneTimber.h"
void SceneMgr::Init()
{
	Release();

	scenes.push_back(new SceneDev1(SceneIds::SceneDev1));
	scenes.push_back(new SceneDev2(SceneIds::SceneDev2));
	scenes.push_back(new SceneTimber(SceneIds::SceneTimber));

	for (auto& scene : scenes)
	{
		scene->Init();
	}

	currentScene = startScene;
	scenes[(int)currentScene]->Enter();
}

void SceneMgr::Release()
{
}

void SceneMgr::ChangeScene(SceneIds id)
{

	//To-Do 모든 게임 오브젝트의 업데이트가 끝난 후 씬 전환 (ChangeScene이 호출된 프레임이 끝나고)
	scenes[(int)currentScene]->Exit();
	currentScene = id;
	scenes[(int)currentScene]->Enter();
}

void SceneMgr::Update(float dt, float& timeScale)
{
	scenes[(int)currentScene]->Update(dt, timeScale);
}

void SceneMgr::Draw(sf::RenderWindow& window)
{
	scenes[(int)currentScene]->Draw(window);
}

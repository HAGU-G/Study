#pragma once
#include "Singleton.h"

class SceneMgr : public Singleton<SceneMgr>
{
protected:


public:
	std::vector<Scene*> scenes;
	SceneIds startScene = SceneIds::SceneTimber;
	SceneIds currentScene = startScene;

	SceneMgr() = default;
	SceneMgr(const SceneMgr&) = delete;
	SceneMgr(SceneMgr&&) = delete;
	inline virtual ~SceneMgr() { Release(); }
	SceneMgr& operator=(const SceneMgr&) = delete;
	SceneMgr& operator=(SceneMgr&&) = delete;



	void Init();
	void Release();

	void ChangeScene(SceneIds id);

	void Update(float dt, float& timeScale);
	void Draw(sf::RenderWindow& window);
};
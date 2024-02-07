#pragma once
#include "Singleton.h"

class SceneMgr : public Singleton<SceneMgr>
{
protected:
	std::vector<Scene*> scenes;
	SceneIds startScene = SceneIds::SceneDev1;
	SceneIds currentScene = startScene;

public:
	SceneMgr() = default;
	SceneMgr(const SceneMgr&) = delete;
	SceneMgr(SceneMgr&&) = delete;
	inline virtual ~SceneMgr() { Release(); }
	SceneMgr& operator=(const SceneMgr&) = delete;
	SceneMgr& operator=(SceneMgr&&) = delete;



	void Init();
	void Release();

	void ChangeScene(SceneIds id);

	void Update(float dt);
	void Draw(sf::RenderWindow& window);
};
#pragma once
class Scene
{
protected:
	Scene() = default;
	Scene(const Scene&) = delete;
	Scene(Scene&&) = delete;
	Scene& operator=(const Scene&) = delete;
	Scene& operator=(Scene&&) = delete;

	SceneIds id;
	std::list<GameObject*> gameObjects; //검색기능?

public:
	Scene(SceneIds id);
	virtual ~Scene() = default;

	virtual void Init() = 0;
	virtual void Release();

	virtual void Enter() = 0;
	virtual void Exit() = 0;

	virtual void Update(float dt, float& timeScale);
	virtual void Draw(sf::RenderWindow& window);

	virtual GameObject* FindGo(const std::string& name);
	virtual bool FindGoAll(const std::string& name,std::list<GameObject*>& list);
	virtual GameObject* AddGo(GameObject* obj);
	virtual void RemoveGo(GameObject* obj);

};
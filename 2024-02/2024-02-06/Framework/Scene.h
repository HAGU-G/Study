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
	std::list<GameObject*> gameObjects;

public:
	Scene(SceneIds id);
	virtual ~Scene() = default;

	virtual void Init() = 0;
	virtual void Release() = 0;

	virtual void Enter() = 0;
	virtual void Exit() = 0;

	virtual void Update(float dt);
	virtual void Draw(sf::RenderWindow& window);

};
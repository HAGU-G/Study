#pragma once
class GameObject
{
protected:

public:
	GameObject();
	virtual ~GameObject();

	virtual void Init();
	virtual void Release();

	virtual void Reset();

	virtual void Update(float dt);
	virtual void Draw(sf::RenderWindow& window);
};


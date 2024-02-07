#pragma once
class GameObject
{
protected:

	bool active = true;

public:
	std::string name = "";
	int sortLayer = 0;
	int sortOrder = 0;

	GameObject(const std::string& name = "");
	virtual ~GameObject();

	virtual void Init();
	virtual void Release();

	virtual void Reset();

	virtual void Update(float dt);
	virtual void Draw(sf::RenderWindow& window);

	inline virtual bool GetActive() const { return active; }
	inline virtual void SetActive(bool active) { this->active = active; }
};


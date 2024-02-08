#pragma once
class GameObject
{
protected:

	bool active = true;
	
	sf::Vector2f origin;
	sf::Vector2f position;

public:
	std::string name = "";
	int sortLayer = 0;
	int sortOrder = 0;

	GameObject(const std::string& name = "");
	virtual ~GameObject();


	virtual void Init();
	virtual void Release();

	virtual void Reset();

	virtual void Update(float dt, float& timeScale);
	virtual void Draw(sf::RenderWindow& window);

	inline virtual bool GetActive() const { return active; }
	inline virtual void SetActive(bool active) { this->active = active; }

	virtual void SetPosition(const sf::Vector2f& pos) { position = pos; }
	virtual sf::Vector2f GetPosition(const sf::Vector2f& pos) { return this->position; }
};


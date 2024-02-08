#pragma once
#include "GameObject.h"
class ObjectNewBee :
    public GameObject
{
protected:
    float time;
    sf::Vector2f direction;
    sf::Sprite sprite;
public:
    ObjectNewBee(const std::string& name = "");
    void Init() override;
    void Update(float dt, float& timeScale) override;
    void Draw(sf::RenderWindow& window) override;
};


#pragma once
#include "GameObject.h"
class ObjectBee :
    public GameObject
{
protected:
    sf::Sprite sprite;
    float beeSpeed;
    sf::Vector2f beeDirection;
    int beeAerobatics;
    float rotateTime;

public:
    float randR = 0.f;
    float beeAccel;
    ObjectBee(const std::string& name = "");

    void Init() override;
    void Update(float dt, float& timeScale) override;
    void Draw(sf::RenderWindow& window) override;
};


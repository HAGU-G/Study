#pragma once
#include "GameObject.h"
class ObjectCloud :
    public GameObject
{
protected:
public:
    static int wind;
    float speed = 0.f;
    sf::Sprite sprite;
    ObjectCloud(const std::string& name = "");

    void Init() override;
    void Update(float dt, float& timeScale) override;
    void Draw(sf::RenderWindow& window) override;
};


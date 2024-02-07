#pragma once
#include "GameObject.h"
class ObjectBranch :
    public GameObject
{
protected:
    sf::Sprite sprite;
public:
    Sides side = Sides::LEFT;
    float y;
    ObjectBranch(const std::string& name = "");

    void Init() override;
    void Update(float dt, float& timeScale) override;
    void Draw(sf::RenderWindow& window) override;
};


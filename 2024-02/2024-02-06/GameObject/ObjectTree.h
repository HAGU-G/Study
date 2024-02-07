#pragma once
#include "GameObject.h"
class ObjectTree :
    public GameObject
{
protected:
    sf::Sprite sprite;
public:
    ObjectTree(const std::string& name = "");

    void Init() override;
    void Update(float dt, float& timeScale) override;
    void Draw(sf::RenderWindow& window) override;
};


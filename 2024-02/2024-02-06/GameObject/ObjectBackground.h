#pragma once
#include "GameObject.h"
class ObjectBackground : public GameObject
{
protected:
    sf::Sprite sprite;
public:
    ObjectBackground(const std::string& name = "");

    void Init() override;
    void Update(float dt, float& timeScale) override;
    void Draw(sf::RenderWindow& window) override;
};


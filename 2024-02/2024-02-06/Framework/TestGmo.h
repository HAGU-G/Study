#pragma once
#include "GameObject.h"
class TestGmo : public GameObject
{
protected:

public:
    sf::Text text;

    void Init() override;
    void Release() override;

    void Reset() override;

    void Update(float dt) override;
    void Draw(sf::RenderWindow& window) override;
};


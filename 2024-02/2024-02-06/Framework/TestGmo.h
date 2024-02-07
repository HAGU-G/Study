#pragma once
#include "GameObject.h"
class TestGmo : public GameObject
{
protected:

public:
    TestGmo(const std::string& name = "");

    sf::Text text;

    void Init() override;
    void Release() override;

    void Reset() override;

    void Update(float dt) override;
    void Draw(sf::RenderWindow& window) override;
};


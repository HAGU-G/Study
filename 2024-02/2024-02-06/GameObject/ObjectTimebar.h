#pragma once
#include "GameObject.h"
class ObjectTimebar :
    public GameObject
{

public:
    ObjectTimebar(const std::string& name = "");

    void Init() override;
    void Update(float dt, float& timeScale) override;
    void Draw(sf::RenderWindow& window) override;


    sf::Vector2f timeBarSize;
    sf::RectangleShape timeBar;
    
    float timeBarDuration = 3.f;
    float timeBarSpeed;
};


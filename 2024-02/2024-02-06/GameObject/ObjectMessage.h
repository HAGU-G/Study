#pragma once
#include "GameObject.h"
class ObjectMessage :
    public GameObject
{
protected:
public:
    bool isStop = true;
    bool isGameOver = false;
    sf::Text textMessage;
    sf::Text scoreMessage;
    ObjectMessage(const std::string& name = "");

    void Init() override;
    void Update(float dt, float& timeScale) override;
    void Draw(sf::RenderWindow& window) override;
};


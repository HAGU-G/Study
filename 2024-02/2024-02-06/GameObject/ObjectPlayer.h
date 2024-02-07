#pragma once
class ObjectPlayer : public GameObject
{
protected:
public:
    sf::Sprite player;
    sf::Sprite axe;
    Sides playerSide = Sides::RIGHT;
    ObjectPlayer(const std::string& name = "");

    void Init() override;
    void Update(float dt, float& timeScale) override;
    void Draw(sf::RenderWindow& window) override;
};


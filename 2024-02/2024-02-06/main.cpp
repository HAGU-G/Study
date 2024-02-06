﻿#include "pch.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    auto& texMgr = ResourceMgr<sf::Texture>::Instance();
    texMgr.Load("graphics/player.png");

    sf::Sprite player;
    player.setTexture(*texMgr.Get("graphics/player.png"));

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(shape);
        window.draw(player);
        window.display();
    }

    texMgr.UnLoad("graphics/player.png");

    return 0;
}
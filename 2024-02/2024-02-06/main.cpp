#include "pch.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");

    ResourceMgr<sf::Font>& fontMgr = ResourceMgr<sf::Font>::Instance();
    fontMgr.Load("fonts/KOMIKAP_.ttf");
    SceneMgr& sceneMgr = SceneMgr::Instance();
    sceneMgr.Init();

    sf::Clock clock;
    while (window.isOpen())
    {
        float dt = sf::Time(clock.restart()).asSeconds();

        InputMgr::Clear();

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            InputMgr::UpdateEvent(event);
        }

        float timeScale = 1.f;
        sceneMgr.Update(dt, timeScale);

        window.clear();
        sceneMgr.Draw(window);
        window.display();
    }

    sceneMgr.Release();

    return 0;
}
// Timber, 2024-02-01 ~ 2024-02-
// 메뉴 없이 바로 게임 시작
// 시간은 계속 줄어든다.
// 나무를 패면 시간이 늘어난다.
#include "pch.h"
#include "SceneTimber.h"

int main()
{
	srand(time(NULL));
	sf::VideoMode vm(1920, 1080);
	sf::RenderWindow window(vm, "Timber", sf::Style::Default);
	SceneMgr& sm = SceneMgr::Instance();
	sm.Init();

	sf::Clock clock;
	float timeScale = 0.f;
	while (window.isOpen())
	{
		//시간
		float dt = sf::Time(clock.getElapsedTime()).asSeconds();
		clock.restart();

		//이벤트
		InputMgr::Clear();
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			InputMgr::UpdateEvent(event);
		}

		//입력 (모든 씬)
		if (InputMgr::GetKey(sf::Keyboard::Escape))
			window.close();

		//업데이트
		sm.Update(dt, timeScale);

		//화면출력
		window.clear();
		sm.Draw(window);
		window.display();
	}

	sm.Release();
	return 0;
}

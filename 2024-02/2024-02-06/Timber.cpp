// Timber, 2024-02-01 ~ 2024-02-
// �޴� ���� �ٷ� ���� ����
// �ð��� ��� �پ���.
// ������ �и� �ð��� �þ��.
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
		//�ð�
		float dt = sf::Time(clock.getElapsedTime()).asSeconds();
		clock.restart();

		//�̺�Ʈ
		InputMgr::Clear();
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			InputMgr::UpdateEvent(event);
		}

		//�Է� (��� ��)
		if (InputMgr::GetKey(sf::Keyboard::Escape))
			window.close();

		//������Ʈ
		sm.Update(dt, timeScale);

		//ȭ�����
		window.clear();
		sm.Draw(window);
		window.display();
	}

	sm.Release();
	return 0;
}

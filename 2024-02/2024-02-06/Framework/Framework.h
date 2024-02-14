#pragma once
#include "Singleton.h"
//1. 초기화 / 메인루프 / 정리
//2. 시간 관련 기능 / 윈도우 정보
//3. ...Mgr 관리

class Framework : public Singleton<Framework>
{
protected:
	Framework() = default;
	virtual ~Framework() = default;
	friend Singleton<Framework>;

	sf::RenderWindow window;
	sf::Vector2i windowSize;

	sf::Clock clock;
	float timeScale = 1.f;

	sf::Time realTime; //게임 시작부터 경과시간
	sf::Time time; //게임 시작부터 경과 시간 (timeScale 적용)

	sf::Time realDeltaTime;
	sf::Time deltaTime;

public:
	sf::RenderWindow& GetWindow() { return window; } //참조형태의 리턴, 사용에 주의
	const sf::Vector2i& GetWindowSize() const { return windowSize; }



	float GetDT() const { return deltaTime.asSeconds(); }
	float GetRealDT() const { return realDeltaTime.asSeconds(); }
	float GetTime() const { return time.asSeconds(); }
	float GetRealTime() const { return realTime.asSeconds(); }

	float GetTimeScale() const { return timeScale; }
	void SetTimeScale(float scale) { timeScale = scale; }

	virtual void Init(int width, int height);
	virtual void Do();
	virtual void Release();
	
};


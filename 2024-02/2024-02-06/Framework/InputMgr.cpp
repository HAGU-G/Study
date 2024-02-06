#include "pch.h"
#include "InputMgr.h"
#include <algorithm>

std::list<sf::Keyboard::Key> InputMgr::downList;
std::list<sf::Keyboard::Key> InputMgr::upList;
std::list<sf::Keyboard::Key> InputMgr::ingList;


void InputMgr::UpdateEvent(const sf::Event& ev)
{
	//키보드 입력을 프레임 단위로 처리
	switch (ev.type)
	{
	case sf::Event::KeyPressed:
		if (!GetKey(ev.key.code))
		{
			ingList.push_back(ev.key.code);
			downList.push_back(ev.key.code);
		}
		break;
	case sf::Event::KeyReleased:
		ingList.remove(ev.key.code);
		upList.push_back(ev.key.code);
		break;
	}
}

void InputMgr::Clear()
{
	downList.clear();
	upList.clear();
}

bool InputMgr::GetKeyDown(sf::Keyboard::Key key)
{
	//iterator를 이용한 순회
	//std::list<sf::Keyboard::Key>::iterator it = downList.begin();
	//auto it = downList.begin(); //위랑 동일
	//for (auto a = downList.begin(); it != downList.end(); ++it)
	//{
	//	if (*it == key)
	//		return true;
	//}
	//return false;

	return std::find(downList.begin(), downList.end(), key) != downList.end();


}

bool InputMgr::GetKeyUp(sf::Keyboard::Key key)
{
	return std::find(upList.begin(), upList.end(), key) != upList.end();;
}

bool InputMgr::GetKey(sf::Keyboard::Key key)
{
	return std::find(ingList.begin(), ingList.end(), key) != ingList.end();;
}
 
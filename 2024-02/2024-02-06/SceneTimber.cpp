#include "pch.h"
#include "SceneTimber.h"
#include "ObjectCloud.h"
#include "ObjectBackground.h"
#include "ObjectTree.h"
#include "ObjectBranch.h"
#include "ObjectBee.h"
#include "ObjectPlayer.h"
#include "ObjectTimebar.h"
#include "ObjectMessage.h"
#include "ObjectNewBee.h"
#include "sstream"


SceneTimber::SceneTimber(SceneIds id)
{
}

void SceneTimber::Init()
{
	//리소스
	ResourceMgr<sf::Texture>& textureMgr = ResourceMgr<sf::Texture>::Instance();
	ResourceMgr<sf::Font>& fontMgr = ResourceMgr<sf::Font>::Instance();
	textureMgr.Load("graphics/background.png");
	textureMgr.Load("graphics/cloud.png");
	textureMgr.Load("graphics/tree2.png");
	textureMgr.Load("graphics/branch.png");
	textureMgr.Load("graphics/player.png");
	textureMgr.Load("graphics/axe.png");
	textureMgr.Load("graphics/bee.png");
	fontMgr.Load("fonts/KOMIKAP_.ttf");

	//게임오브젝트
	ObjectBackground* background = new ObjectBackground("background");
	ObjectCloud::wind = 1 - 2 * (rand() % 2);
	ObjectCloud* cloud = new ObjectCloud[NUM_OF_CLOUD];
	ObjectTree* tree = new ObjectTree("tree");
	ObjectBranch* branch = new ObjectBranch[6];
	ObjectPlayer* player = new ObjectPlayer("player");
	ObjectBee* bee = new ObjectBee("bee");
	ObjectTimebar* timebar = new ObjectTimebar("timebar");
	ObjectMessage* message = new ObjectMessage("message");
	ObjectNewBee* bee2 = new ObjectNewBee("bee2");




	//씬에 오브젝트 등록
	AddGo(background);
	for (int i = 0; i < NUM_OF_CLOUD; i++)
	{
		cloud[i].name = "cloud" + std::to_string(i);
		AddGo(&(cloud[i]));
	}
	AddGo(tree);
	for (int i = 0; i < 6; i++)
	{
		branch[i].name = "branch" + std::to_string(i);
		AddGo(&(branch[i]));
		branch[i].y = i;
	}
	AddGo(player);
	AddGo(bee);
	AddGo(bee2);
	AddGo(timebar);
	AddGo(message);

	//오브젝트 Init
	for (auto& objects : gameObjects)
	{
		objects->Init();
	}
	ResetBranches();



}

void SceneTimber::Release()
{
	Scene::Release();
}

void SceneTimber::Enter()
{
}

void SceneTimber::Exit()
{
}

void SceneTimber::Update(float dt, float& timeScale)
{	timer += dt;

	if (dynamic_cast<ObjectTimebar*>(FindGo("timebar"))->timeBar.getSize().x == 0.f)
	{
		isGameOver = true;
		isStop = true;
		timeScale = 0.f;
	}
	if (timer >= 0.5f * rand() / RAND_MAX + 1.5f && timeScale > 0.f)
	{
		timer=0.f;
		dynamic_cast<ObjectBee*>(FindGo("bee"))->randR = dt * 360.f * rand() / RAND_MAX - (dt * 180.f);
		dynamic_cast<ObjectBee*>(FindGo("bee"))->beeAccel = 35.f * rand() / RAND_MAX - 20.f;
	}
	if (InputMgr::GetKeyDown(sf::Keyboard::Space))
	{
		if (timeScale > 0.f)
		{
			UpdateBranches();
			isMove = true;
		}
	}
	if (InputMgr::GetKeyDown(sf::Keyboard::Enter))
	{
		isStop = !isStop;
		timeScale = isStop ? 0.f : 1.f;
		if (isGameOver)
		{
			dynamic_cast<ObjectTimebar*>(FindGo("timebar"))->timeBar.setSize(dynamic_cast<ObjectTimebar*>(FindGo("timebar"))->timeBarSize);
			score = 0;
			std::stringstream ss;
			ss << "Score : " << score;
			dynamic_cast<ObjectMessage*>(FindGo("message"))->scoreMessage.setString(ss.str());
			ResetBranches();
			dynamic_cast<ObjectTimebar*>(FindGo("timebar"))->timeBarSpeed = -dynamic_cast<ObjectTimebar*>(FindGo("timebar"))->timeBarSize.x / 3.f;
			isGameOver = false;
			ObjectCloud::wind = 1.f - (rand() % 2 * 2);
			for (int i = 0; i < NUM_OF_CLOUD; i++)
			{
				dynamic_cast<ObjectCloud*>(FindGo("cloud"+std::to_string(i)))->sprite.setScale(-ObjectCloud::wind, 1);
			}
		}
	}
	if (InputMgr::GetKeyDown(sf::Keyboard::Right) && !isStop)
	{
		UpdateBranches();
		dynamic_cast<ObjectPlayer*>(FindGo("player"))->player.setScale(1, 1);
		dynamic_cast<ObjectPlayer*>(FindGo("player"))->playerSide = Sides::RIGHT;
		dynamic_cast<ObjectPlayer*>(FindGo("player"))->axe.setPosition(dynamic_cast<ObjectPlayer*>(FindGo("player"))->player.getGlobalBounds().left + dynamic_cast<ObjectPlayer*>(FindGo("player"))->player.getLocalBounds().width * 0.58f, dynamic_cast<ObjectPlayer*>(FindGo("player"))->player.getGlobalBounds().top + dynamic_cast<ObjectPlayer*>(FindGo("player"))->player.getLocalBounds().height * 0.73f);
		dynamic_cast<ObjectPlayer*>(FindGo("player"))->axe.setScale(1, -1);
		isMove = true;

	}
	if (InputMgr::GetKeyDown(sf::Keyboard::Left) && !isStop)
	{
		UpdateBranches();
		dynamic_cast<ObjectPlayer*>(FindGo("player"))->player.setScale(-1, 1);
		dynamic_cast<ObjectPlayer*>(FindGo("player"))->playerSide = Sides::LEFT;
		dynamic_cast<ObjectPlayer*>(FindGo("player"))->axe.setPosition(dynamic_cast<ObjectPlayer*>(FindGo("player"))->player.getGlobalBounds().left + dynamic_cast<ObjectPlayer*>(FindGo("player"))->player.getLocalBounds().width * 0.42f, dynamic_cast<ObjectPlayer*>(FindGo("player"))->player.getGlobalBounds().top + dynamic_cast<ObjectPlayer*>(FindGo("player"))->player.getLocalBounds().height * 0.73f);
		dynamic_cast<ObjectPlayer*>(FindGo("player"))->axe.setScale(-1, -1);
		isMove = true;

	}
	if (isMove)
	{
		isMove = false;
		if (dynamic_cast<ObjectPlayer*>(FindGo("player"))->playerSide != dynamic_cast<ObjectBranch*>(FindGo("branch" + std::to_string(5)))->side)
		{
			score += 10;
			if (dynamic_cast<ObjectTimebar*>(FindGo("timebar"))->timeBar.getSize().x < dynamic_cast<ObjectTimebar*>(FindGo("timebar"))->timeBarSize.x)
				dynamic_cast<ObjectTimebar*>(FindGo("timebar"))->timeBar.setSize(sf::Vector2f(dynamic_cast<ObjectTimebar*>(FindGo("timebar"))->timeBar.getSize().x - dynamic_cast<ObjectTimebar*>(FindGo("timebar"))->timeBarSpeed, dynamic_cast<ObjectTimebar*>(FindGo("timebar"))->timeBarSize.y));
			if (dynamic_cast<ObjectTimebar*>(FindGo("timebar"))->timeBar.getSize().x > dynamic_cast<ObjectTimebar*>(FindGo("timebar"))->timeBarSize.x)
				dynamic_cast<ObjectTimebar*>(FindGo("timebar"))->timeBar.setSize(dynamic_cast<ObjectTimebar*>(FindGo("timebar"))->timeBarSize);
			std::stringstream ss;
			ss << "Score : " << score;
			dynamic_cast<ObjectMessage*>(FindGo("message"))->scoreMessage.setString(ss.str());

			dynamic_cast<ObjectTimebar*>(FindGo("timebar"))->timeBarDuration = 2.0f * exp(-score / 200.f + 10) / (exp(-score / 200.f + 10) + 1) + 0.7f * exp(-score / 100.f + 7) / (exp(-score / 100.f + 7) + 1) + 0.3f;
			dynamic_cast<ObjectTimebar*>(FindGo("timebar"))->timeBarSpeed = -dynamic_cast<ObjectTimebar*>(FindGo("timebar"))->timeBarSize.x / dynamic_cast<ObjectTimebar*>(FindGo("timebar"))->timeBarDuration;
		}
		else
		{
			isGameOver = true;
			isStop = true;
			timeScale = 0.f;
		}


	}
	Scene::Update(dt, timeScale);
	dynamic_cast<ObjectMessage*>(FindGo("message"))->isStop = isStop;
	dynamic_cast<ObjectMessage*>(FindGo("message"))->isGameOver = isGameOver;


}

void SceneTimber::UpdateBranches()
{
	for (int i = 6 - 1; i > 0; i--)
	{
		dynamic_cast<ObjectBranch*>(FindGo("branch" + std::to_string(i)))->side = dynamic_cast<ObjectBranch*>(FindGo("branch" + std::to_string(i - 1)))->side;
	}

	int side = rand() % 4;
	switch (side)
	{
	case 0:
		dynamic_cast<ObjectBranch*>(FindGo("branch0"))->side = Sides::LEFT;
		break;
	case 1:
		dynamic_cast<ObjectBranch*>(FindGo("branch0"))->side = Sides::RIGHT;
		break;
	default:
		dynamic_cast<ObjectBranch*>(FindGo("branch0"))->side = Sides::NONE;
		break;
	}
}

void SceneTimber::ResetBranches()
{
	for (int i = 0; i < 6; i++)
	{
		UpdateBranches();
	}
	dynamic_cast<ObjectBranch*>(FindGo("branch5"))->side = Sides::NONE;
}
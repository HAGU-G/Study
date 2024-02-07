#pragma once
class SceneTimber : public Scene
{
protected:
	const int NUM_OF_CLOUD = 3;
	bool isMove = false;
	bool isStop = true;
	bool isGameOver = false;
	int score = 0;
public:
	float timer = 0.f;

	SceneTimber() = default;
	SceneTimber(SceneIds id);
	SceneTimber(const SceneTimber&) = delete;
	SceneTimber(SceneTimber&&) = delete;

	virtual ~SceneTimber() = default;



	void Init() override;
	virtual void Release() override;

	void Enter() override;
	void Exit() override;
	void Update(float dt, float& timeScale) override;

	void UpdateBranches();
	void ResetBranches();
};


#pragma once
class SceneDev2 : public Scene
{
protected:

public:
	SceneDev2() = default;
	SceneDev2(SceneIds id);
	SceneDev2(const SceneDev2&) = delete;
	SceneDev2(SceneDev2&&) = delete;

	virtual ~SceneDev2() = default;



	void Init() override;
	virtual void Release() override;

	void Enter() override;
	void Exit() override;


	void Update(float dt) override;

};


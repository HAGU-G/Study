#pragma once
class SceneDev1 : public Scene
{
protected:

public:
	SceneDev1() = default;
	SceneDev1(SceneIds id);
	SceneDev1(const SceneDev1&) = delete;
	SceneDev1(SceneDev1&&) = delete;

	virtual ~SceneDev1() = default;



	void Init() override;
	virtual void Release() override;

	void Enter() override;
	void Exit() override;
	void Update(float dt) override;

};


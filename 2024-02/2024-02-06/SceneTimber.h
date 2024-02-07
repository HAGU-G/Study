#pragma once
class SceneTimber : public Scene
{
protected:

public:
	SceneTimber() = default;
	SceneTimber(SceneIds id);
	SceneTimber(const SceneTimber&) = delete;
	SceneTimber(SceneTimber&&) = delete;

	virtual ~SceneTimber() = default;



	void Init() override;
	virtual void Release() override;

	void Enter() override;
	void Exit() override;
	void Update(float dt) override;
};


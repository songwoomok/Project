#pragma once
#include "Scene.h"

class GameClearScene : public Scene
{
public:
	GameClearScene(SceneManager * a_pParent);
	virtual ~GameClearScene();

	// Scene��(��) ���� ��ӵ�
	virtual eScene GetScene() override;

	virtual void Init() override;
	virtual void Update(float a_fDeltaTime) override;
	virtual void Render() override;

};


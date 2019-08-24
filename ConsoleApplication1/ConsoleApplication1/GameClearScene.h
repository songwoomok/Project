#pragma once
#include "Scene.h"

class GameClearScene : public Scene
{
public:
	GameClearScene(SceneManager * a_pParent);
	virtual ~GameClearScene();

	// Scene을(를) 통해 상속됨
	virtual eScene GetScene() override;

	virtual void Init() override;
	virtual void Update(float a_fDeltaTime) override;
	virtual void Render() override;

};


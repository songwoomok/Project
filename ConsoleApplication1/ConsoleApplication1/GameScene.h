#pragma once
#include "Scene.h"
class GameScene : public Scene
{
public:
	GameScene(SceneManager * a_pParent);
	virtual ~GameScene();

	// Scene을(를) 통해 상속됨
	virtual eScene GetScene() override;

	virtual void Init() override;
	virtual void Update(float a_fDeltaTime) override;
	virtual void Render() override;

};


#pragma once
#include "Scene.h"
class GameOverScene : public Scene
{
public:
	GameOverScene(SceneManager * a_pParent);
	virtual ~GameOverScene();

	virtual eScene GetScene() override;

	virtual void Init() override;
	virtual void Update(float a_fDeltaTime) override;
	virtual void Render() override;

};


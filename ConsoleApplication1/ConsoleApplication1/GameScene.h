#pragma once
#include "Scene.h"
class GameScene : public Scene
{
public:
	GameScene(SceneManager * a_pParent);
	virtual ~GameScene();

	virtual eScene GetScene() override;

	virtual void Init() override;
	virtual void Update(float a_fDeltaTime) override;
	virtual void Render() override;

	bool m_bGameOver = true;
	bool m_bGameClear = false;
	int m_Width, m_Height;
	int m_nX = 0;
	int m_nY = 0;
};


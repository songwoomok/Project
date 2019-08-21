#include "pch.h"
#include "GameOverScene.h"


GameOverScene::GameOverScene(SceneManager * a_pParent) : Scene(a_pParent)
{
}

GameOverScene::~GameOverScene()
{
}

eScene GameOverScene::GetScene()
{
	return eScene::GameOverScene;
}

void GameOverScene::Init()
{
}
void GameOverScene::Update(float a_fDeltaTime)
{
	SetCursor(5, 4);
	cout << a_fDeltaTime << endl;
}
void GameOverScene::Render()
{
	SetCursor(5, 5);
	cout << "test scene" << endl;
}

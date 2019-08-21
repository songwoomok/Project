#include "pch.h"
#include "GameScene.h"


GameScene::GameScene(SceneManager * a_pParent) : Scene(a_pParent)
{
}

GameScene::~GameScene()
{
}

eScene GameScene::GetScene()
{
	return eScene::GameScene;
}

void GameScene::Init()
{
}
void GameScene::Update(float a_fDeltaTime)
{
	SetCursor(5, 4);
	cout << a_fDeltaTime << endl;
}
void GameScene::Render()
{
	SetCursor(5, 5);
	cout << "test scene" << endl;
}

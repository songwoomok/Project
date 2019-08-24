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
	
}
void GameOverScene::Render()
{
	system("cls");
	SetCursor(5, 5);
	cout << "Game Over" << endl;
}

#include "pch.h"
#include "GameClearScene.h"


GameClearScene::GameClearScene(SceneManager * a_pParent) : Scene(a_pParent)
{
}

GameClearScene::~GameClearScene()
{
}

eScene GameClearScene::GetScene()
{
	return eScene::GameOverScene;
}

void GameClearScene::Init()
{
}
void GameClearScene::Update(float a_fDeltaTime)
{

}
void GameClearScene::Render()
{
	system("cls");
	SetCursor(5, 5);
	cout << "Game Clear" << endl;
}

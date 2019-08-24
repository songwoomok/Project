#include "pch.h"
#include "GameScene.h"
#include "GameManager.h"

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
	SetCursor(2, 1);
	cout << "����� �Է��ϼ���.";
	SetCursor(5, 3);
	cout << "���� ������ :";
	cin >> m_Width;
	
	SetCursor(5, 4);
	cout << "���� ������ : ";
	cin >> m_Height;
}
void GameScene::Update(float a_fDeltaTime)
{
	GameManager GM(m_Width, m_Height);
	GM.LandMine();
	GM.MakeGameBoard();
	while (true)
	{
		GM.DrawGameBoard(GM.GamePlay(&m_nX, &m_nY));
		if (m_bGameOver == false)
		{
			m_refParent->ChangeScene(eScene::GameOverScene);
		}
		if (m_bGameClear == true)
		{
			m_refParent->ChangeScene(eScene::GameClearScene);
		}
	}
}
void GameScene::Render()
{
	
}

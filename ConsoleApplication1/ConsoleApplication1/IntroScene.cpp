#include "pch.h"
#include "IntroScene.h"
#include "SceneManager.h"

IntroScene::IntroScene(SceneManager * a_pParent) : Scene(a_pParent)
{
}

IntroScene::~IntroScene()
{
}

eScene IntroScene::GetScene()
{
	return eScene::IntroScene;
}

void IntroScene::Init()
{
}
void IntroScene::Update(float a_fDeltaTime)
{
	
	if (GetAsyncKeyState(VK_SPACE) & 0x8000)
	{
		m_refParent->ChangeScene(eScene::GameScene);
	}
}
void IntroScene::Render()
{
	SetCursor(0, 8);
	cout << "����Ű : W,A,S,D  ���� : J  ��� : K  ��� ���� : L";
	SetCursor(7, 3);
	cout << "GameStart - Press 'Space' Key";
	SetCursor(7, 5);
	cout << "GameExit  - Press 'ESC' Key";
}


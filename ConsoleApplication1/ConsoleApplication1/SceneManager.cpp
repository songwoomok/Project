#include "pch.h"

#include "SceneManager.h"
#include "Scene.h"

#include "SceneFactory.h"


SceneManager::~SceneManager()
{
	SAFE_DELETE(m_pNowScene);
}

void SceneManager::Init()
{
	ChangeScene(eScene::IntroScene);
}

void SceneManager::ChangeScene(eScene a_eScene)
{
	SAFE_DELETE(m_pNowScene);

	m_pNowScene = SceneFactory::Make(a_eScene);

	assert((m_pNowScene != nullptr) && "error");

	system("cls");

	m_pNowScene->Init();
}

void SceneManager::NextScene()
{
	ChangeScene(eScene::GameScene);
}

void SceneManager::Update(float a_fDeltaTime)
{
	m_pNowScene->Update(a_fDeltaTime);
}

void SceneManager::Render()
{
	m_pNowScene->Render();
}


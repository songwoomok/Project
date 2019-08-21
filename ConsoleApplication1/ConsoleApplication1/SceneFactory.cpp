#include "pch.h"
#include "SceneFactory.h"

#include "SceneManager.h"
#include "IntroScene.h"
#include "GameScene.h"
#include "GameOverScene.h"

Scene* SceneFactory::Make(eScene a_eScene)
{
	SceneManager* pParent = SceneMng();
	Scene* pMakedScene = nullptr;

	switch (a_eScene)
	{
	case eScene::IntroScene:
		pMakedScene = new IntroScene(pParent);
		break;
	case eScene::GameScene:
		pMakedScene = new IntroScene(pParent);
		break;
	case eScene::GameOverScene:
		pMakedScene = new IntroScene(pParent);
		break;
	default:
		assert(false && "arg error");
		break;
	}

	return pMakedScene;
}



#pragma once
#include "Scene.h"
class IntroScene : public Scene
{
public:
	IntroScene(SceneManager * a_pParent);
	virtual ~IntroScene();
	

	virtual eScene GetScene() override;

	virtual void Init() override;
	virtual void Update(float a_fDeltaTime) override;
	virtual void Render() override;

};


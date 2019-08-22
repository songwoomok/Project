#pragma once

#include "SceneManager.h"

class Scene
{
public:

	Scene(SceneManager * a_pParent);
	virtual ~Scene();

	virtual eScene GetScene() = 0;

	virtual void Init();
	virtual void Update(float a_fDeltaTime);
	virtual void Render();

public:

	class SceneManager * m_refParent = nullptr;
};

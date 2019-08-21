#pragma once

class SceneManager
{
public:

private:
	static inline SceneManager * m_pInstance = nullptr;
	SceneManager() = default;
	~SceneManager();

	SceneManager operator=(SceneManager&) = delete;
	SceneManager(SceneManager&&) = delete;
	SceneManager(const SceneManager&) = delete;

public:

	static void CreateInstance()
	{
		if (m_pInstance == nullptr)
		{
			m_pInstance = new SceneManager();
		}
	}

	static SceneManager * GetInstance()
	{
		return m_pInstance;
	}

	static void ReleaseInstance()
	{
		SAFE_DELETE(m_pInstance);
	}

public:

	void Init();
	void ChangeScene(eScene a_eScene);

	void Update(float a_fDeltaTime);
	void Render();

private:
	class Scene * m_pNowScene = nullptr;
};


#define InitSceneMng()		{SceneManager::CreateInstance(); SceneManager::GetInstance()->Init();}
#define SceneMng()			(SceneManager::GetInstance())
#define ReleaseSceneMng()	(SceneManager::ReleaseInstance())
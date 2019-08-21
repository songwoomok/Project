#pragma once

class Application
{
public:
	Application();
	~Application();

	void Run();
	constexpr static float GetTargetFPS();

protected:

	eUpdateState Update(float a_fDelta);
	void Render();

private:

	long m_nDeltaTick;
	long m_nLastStamp = 0;
};

#pragma once

enum class eScene
{
	IntroScene,
	GameScene,
	GameOverScene,
	GameClearScene,
};

enum class eUpdateState
{
	Run,
	Final,
};

enum eGamePlay
{
	Player = 100,

	Mine = 90,
	Open = 30,
	Flag = 80,
};
#define SAFE_DELETE(x)		{ if((x) != nullptr ) { delete (x); (x) = nullptr; } }
#define SAFE_DELETE_ARR(x)	{ if((x) != nullptr ) { delete[] (x); (x) = nullptr; } }

void SetCursor(const COORD& Coord);
void SetCursor(int x, int y);

void CursorView(char show);
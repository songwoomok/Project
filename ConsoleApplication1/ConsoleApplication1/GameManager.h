#pragma once
#include "Define.h"


class GameManager
{
private:
	int m_nMineCount;

	int m_Width;
	int m_Height;

	int* m_GameData;
	int* m_TempData;

public:
	GameManager(int a_Width, int a_Height);
	~GameManager();

	int LandMine();
	void DrawGameBoard(int a_nLocation);
	void MakeGameBoard();
	void SetPosBoard(int a_nLocation);
	void MineCountDisplay(int x, int y);
	int GamePlay(int* x, int* y);


	class GameScene* GameOverCheck;
};


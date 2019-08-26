#include "pch.h"
#include "GameManager.h"
#include "GameScene.h"


GameManager::GameManager(int a_Width, int a_Height) : 
	m_Width(a_Width), m_Height(a_Height)
{
	int nSize = a_Width * a_Height;
	m_GameData = new int[(sizeof(int) * nSize)];
	m_TempData = new int[(sizeof(int) * nSize)];

	memset(m_GameData, 0, sizeof(int) * nSize);
	memset(m_TempData, 0, sizeof(int) * nSize);
}


GameManager::~GameManager()
{
	SAFE_DELETE_ARR(m_GameData);
	SAFE_DELETE_ARR(m_TempData);
}




int GameManager::LandMine()
{
	if (m_Width <= 1 || m_Height <= 1)
	{
		cout << "크기 오류" << endl;
		return 0;
	}
	
	int nRandom;
	int nCount = 0;

	int nMineQuantity = floor((m_Width * m_Height) * 0.2);
	int nBoardSize = m_Width * m_Height;
	srand(time(0));

	do
	{
		while (m_GameData[nRandom = rand() % nBoardSize - 1]);
		m_GameData[nRandom] = Mine;
		++nCount;
	} while (nCount != nMineQuantity);
	
	m_nMineCount = nCount;
	return 1;
}

void GameManager::DrawGameBoard(int a_nLocation)
{
	system("cls");

	for (int i = 0; i < m_Height; i++)
	{
		for (int j = 0; j < m_Width; j++)
		{
			if (m_GameData[i * m_Height + j] == Mine && i * m_Height + j != a_nLocation)
			{
				cout << "◈";
			}
			else if (m_GameData[i * m_Height + j] == 0 && i * m_Height + j != a_nLocation)
			{
				cout << "■";
			}
			else if (i * m_Height + j == a_nLocation)
			{
				cout << "★";
			}
			else if (m_GameData[i * m_Height + j] == Open)
			{
				cout << "□";
			}
			else if (m_GameData[i * m_Height + j] == Flag)
			{
				cout << "♣";
			}
			else
			{
				cout << m_GameData[i * m_Height + j] << " ";
			}
		}
		cout << endl;
	}
	SetCursor(m_Width, m_Height);
	cout << endl;
	cout << "방향키 : W,A,S,D  선택 : J  깃발 : K  깃발 해제 : L";
	cout << endl;
	cout << "지뢰 수 : " << m_nMineCount << " 개";
}

void GameManager::MakeGameBoard()
{
	int nSum;
	int nCount = 0;

	for (int i = 0; i < m_Height; i++)
	{
		for (int j = 0; j < m_Width; j++)
		{
			if (m_GameData[i*m_Height + j] != Mine)
			{
				for (int k = i - 1; k <= i + 1; k++)
				{
					for (int l = j - 1; l <= j + 1; l++)
					{
						if (k < 0 || l < 0 || k == m_Height || l == m_Width)continue;
						else if (m_GameData[k * m_Height + l] == Mine)
						{
							nCount++;
						}

					}
				}
				m_TempData[i * m_Height + j] = nCount;
				nCount = 0;
			}
			if (m_GameData[i*m_Height + j] == Mine)
			{
				m_TempData[i * m_Height + j] = Mine;
			}
		}
	}
	memset(m_GameData, 0, sizeof(int)*(m_Width*m_Height));
	SetCursor(5, 5);
	cout << "지뢰 수 : " << m_nMineCount;
}

void GameManager::SetPosBoard(int a_location)
{
	system("cls");
	for (int i = 0; i < m_Height; ++i)
	{
		for (int j = 0; j < m_Width; ++j)
		{
			if (m_TempData[i * m_Height + j] == Mine && i * m_Height + j != a_location)
			{
				cout << "※";
			}
			else if (Mine && i * m_Height + j != a_location)
			{
				cout << m_TempData[i * m_Height + j] << " ";
			}
			else
			{
				cout << "★ " << m_TempData[i * m_Height + j];
			}
		}
		cout << endl;
	}
}

void GameManager::MineCountDisplay(int x, int y)
{
	int nLocation = x + y;

	if (m_GameData[nLocation] == 0)
	{
		m_GameData[nLocation] = Open;
	}
	if (m_TempData[nLocation + 1] != 0 && nLocation + 1 < nLocation + ((y - nLocation) + m_Height)) 
	{
		m_GameData[nLocation + 1] = m_TempData[nLocation + 1];
	}
	if (m_TempData[nLocation - 1] != 0 && nLocation - 1 >= y) 
	{
		m_GameData[nLocation - 1] = m_TempData[nLocation - 1];
	}
	if (m_TempData[nLocation + m_Height] != 0 && nLocation + m_Width <= ((m_Width*m_Height) - m_Width) + x)  
	{
		m_GameData[nLocation + m_Width] = m_TempData[nLocation + m_Width];
	}
	if (m_TempData[nLocation - m_Width] != 0 && nLocation - m_Width >= x)
	{
		m_GameData[nLocation - m_Width] = m_TempData[nLocation - m_Width];
	}
	if (m_TempData[nLocation + 1] == 0 && nLocation + 1 < nLocation + ((y - nLocation) + m_Height) && m_GameData[nLocation + 1] == 0) MineCountDisplay(x + 1, y);
	if (m_TempData[nLocation - 1] == 0 && nLocation - 1 >= y && m_GameData[nLocation - 1] == 0) MineCountDisplay(x - 1, y); 
	if (m_TempData[nLocation + m_Width] == 0 && nLocation + m_Width <= ((m_Width*m_Height) - m_Width) + x && m_GameData[nLocation + m_Width] == 0) MineCountDisplay(x, y + m_Width); 
	if (m_TempData[nLocation - m_Width] == 0 && nLocation - m_Width >= x && m_GameData[nLocation - m_Width] == 0) MineCountDisplay(x, y - m_Width); 
}

int GameManager::GamePlay(int* x, int* y)
{
	char KeyInput;
	int nLocation;
	KeyInput = _getch();

	if (KeyInput == 'd' && (*x) < m_Width - 1) 
	{ 
		++(*x); 
	}
	else if (KeyInput == 'a' && (*x) > 0) 
	{ 
		--(*x); 
	}
	else if (KeyInput == 'w' && (*y) - m_Width >= 0) 
	{ 
		(*y) -= m_Width; 
	}
	else if (KeyInput == 's' && (*y) + m_Width < m_Height * m_Width) 
	{ 
		(*y) += m_Width; 
	}
	else if (KeyInput == 'j')
	{
		if (m_TempData[(*x) + (*y)] == 0)
		{
			MineCountDisplay(*x, *y);
		}
		else if (m_TempData[(*x) + (*y)] == Mine)
		{
			GameOverCheck->m_bGameOver = false;
		}
		else if (m_GameData[(*x) + (*y)] != Flag)
		{
			m_GameData[(*x) + (*y)] = m_TempData[(*x) + (*y)];
		}
	}
	else if (KeyInput == 'k')
	{
		if (m_TempData[(*x) + (*y)] == Mine && m_GameData[(*x) + (*y)] != Flag)
		{
			m_GameData[(*x) + (*y)] = Flag;
			--m_nMineCount;
			
			if (m_nMineCount == 0)
			{
				GameOverCheck->m_bGameClear = true;
			}
		}
	}
	else if (KeyInput == 'l')
	{
		if (m_TempData[(*x) + (*y)] == Mine && m_GameData[(*x) + (*y)] == Flag)
		{
			m_GameData[(*x) + (*y)] = 0;
			++m_nMineCount;
		}
		else if (m_GameData[(*x) + (*y)] == Flag)
		{
			m_GameData[(*x) + (*y)] = 0;
		}
	}

	nLocation = (*x) + (*y);
	return nLocation;
}

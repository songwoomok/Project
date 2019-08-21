#include "pch.h"
#include "Define.h"


void SetCursor(const COORD& Coord)
{
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Coord);
}

void SetCursor(int x, int y)
{
	SetCursor(COORD{ (short)x,(short)y });
}

void CursorView(char show)//Ä¿¼­¼û±â±â
{
	HANDLE hConsole;
	CONSOLE_CURSOR_INFO ConsoleCursor;

	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	ConsoleCursor.bVisible = show;
	ConsoleCursor.dwSize = 1;

	SetConsoleCursorInfo(hConsole, &ConsoleCursor);
}
#include "Console-Settings.h"


void ClearConsole()
{
	system("cls");
}


void DefaultConsole()
{
	// style of console
	system("mode con cols=115 lines=30");
	HWND hwnd = GetConsoleWindow();
	SetWindowPos(hwnd, HWND_NOTOPMOST, 200, 10, 0, 0, SWP_NOSIZE | SWP_NOZORDER);


	// changed the font size and transformed it to bold font
	static CONSOLE_FONT_INFOEX  fontex;
	fontex.cbSize = sizeof(CONSOLE_FONT_INFOEX);
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	GetCurrentConsoleFontEx(hOut, 0, &fontex);
	fontex.FontWeight = 150;
	fontex.dwFontSize.X = 28;
	fontex.dwFontSize.Y = 28;
	SetCurrentConsoleFontEx(hOut, NULL, &fontex);
}


void SetConsoleColor(int text, int background)
{
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hStdOut, (WORD)((background << 4) | text));
}


void SetCursorPosition(int x, int y)
{
	HANDLE output = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos = { x, y };
	SetConsoleCursorPosition(output, pos);
}


void ClearSector(const std::string& ch, int startPosX, int startPosY, int stopPosX, int stopPosY)
{
	for (int x = startPosX; x < stopPosX; x++)
	{
		for (int y = startPosY; y <= stopPosY; y++)
		{
			SetCursorPosition(x, y);
			std::cout << ch;
		}
	}
}
#ifndef CONSOLE_SETTINGS_H
#define CONSOLE_SETTINGS_H

#pragma once
#include <iostream>
#include <string>
#include "Windows.h"

void ClearConsole();

void DefaultConsole();

enum ConsoleColor
{
	Black = 0,
	Blue = 1,
	Green = 2,
	Cyan = 3,
	Red = 4,
	Magenta = 5,
	Brown = 6,
	LightGray = 7,
	DarkGray = 8,
	LightBlue = 9,
	LightGreen = 10,
	LightCyan = 11,
	LightRed = 12,
	LightMagenta = 13,
	Yellow = 14,
	White = 15,
};


void SetConsoleColor(int text, int background);

void SetCursorPosition(int x, int y);

void ClearSector(const std::string& ch, int startPosX, int startPosY, int stopPosX, int stopPosY);

#endif
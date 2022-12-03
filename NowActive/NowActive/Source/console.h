
#ifndef CONSOLE_h
#define CONSOLE_H

#include <Windows.h>
#include <conio.h>

// delay()
// delay console using Sleep()
void delay(DWORD Delay)
{
	Sleep(Delay);
}

// pause()
// To pause console
void pause()
{
	const char PAUSE = _getch();
}

// clear()
// To clear console
void clear()
{
#ifdef _WIN32
	system("CLS");
#else
	system("CLEAR");
#endif // _WIN32
}

// Console_MoveTo()
// To change console position
void Console_MoveTo(int X, int Y)
{
	HWND console = GetConsoleWindow();
	SetWindowPos(console, 0, X, Y, 0, 0, SWP_NOSIZE | SWP_NOZORDER);
}

// Console_ToSize()
// To change console size
void Console_ToSize(int WIDTH, int HEIGHT)
{
	HWND console = GetConsoleWindow();
	RECT conrect;
	GetWindowRect(console, &conrect);
	MoveWindow(console, conrect.left, conrect.top, WIDTH, HEIGHT, TRUE);
}

// WindowTitle
// To change console window title
void WindowTitle(LPCSTR title)
{
	SetConsoleTitleA(title);
}


#endif // !CONSOLE_H

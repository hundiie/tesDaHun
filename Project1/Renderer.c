#include "Randerer.h"
#include <Windows.h>

HANDLE s_screens[2];
int s_backBufferIndex;

bool Renderer_Init(void)
{
	//s_screens[s_backBufferIndex];
	//콘솔 프로그램에 대한 화면 만드는 함수
	s_screens[0] = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
	if (s_screens[0]==INVALID_HANDLE_VALUE)
	{
		CloseHandle(s_screens[1]);
		return false;
	}
	s_screens[1] = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
	if (s_screens[1] == INVALID_HANDLE_VALUE)
	{
		CloseHandle(s_screens[0]);
		return false;
	}

	return true;
}

void Renderer_Cleanup(void)
{
	CloseHandle(s_screens[0]);
	CloseHandle(s_screens[1]);
}

void Renderer_Flip(void)
{
	//콘솔에 쓸 함수를 정해주는 함수
	//1.현재 콘솔의 스크린 버퍼를 백 버퍼로 전환
	SetConsoleActiveScreenBuffer(s_screens[s_backBufferIndex]);

	s_backBufferIndex = !s_backBufferIndex;
}

void Renderer_Clear(void)//이거하면 화면이 지워짐
{
	HANDLE consoleHandle = s_screens[s_backBufferIndex];

	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(consoleHandle, &csbi);

	SMALL_RECT scrollRect;
	scrollRect.Left = 0;
	scrollRect.Top = 0;
	scrollRect.Right = csbi.dwSize.X;
	scrollRect.Bottom = csbi.dwSize.Y;

	COORD scrollTarget;
	scrollTarget.X = 0;
	scrollTarget.Y = (SHORT)(0 - csbi.dwSize.Y);

	CHAR_INFO fill;
	fill.Char.UnicodeChar = TEXT(' ');
	fill.Attributes = csbi.wAttributes;

	ScrollConsoleScreenBuffer(consoleHandle, &scrollRect, NULL, scrollTarget, &fill);

	csbi.dwCursorPosition.X = 0;
	csbi.dwCursorPosition.Y = 0;
	SetConsoleCursorPosition(consoleHandle, csbi.dwCursorPosition);
}

void Renderer_DrawText(const char* text, int numberofText)
{
	HANDLE backBuffer = s_screens[s_backBufferIndex];
	//현재 커서의 위치에서 문자열을 출력하는 함수.
	WriteConsoleA(backBuffer, text, numberofText, NULL, NULL);
}
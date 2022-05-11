#include "Randerer.h"
#include <Windows.h>

HANDLE s_screens[2];
int s_backBufferIndex;

bool Renderer_Init(void)
{
	//s_screens[s_backBufferIndex];
	//�ܼ� ���α׷��� ���� ȭ�� ����� �Լ�
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
	//�ֿܼ� �� �Լ��� �����ִ� �Լ�
	//1.���� �ܼ��� ��ũ�� ���۸� �� ���۷� ��ȯ
	SetConsoleActiveScreenBuffer(s_screens[s_backBufferIndex]);

	s_backBufferIndex = !s_backBufferIndex;
}

void Renderer_Clear(void)//�̰��ϸ� ȭ���� ������
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
	//���� Ŀ���� ��ġ���� ���ڿ��� ����ϴ� �Լ�.
	WriteConsoleA(backBuffer, text, numberofText, NULL, NULL);
}
#include "App.h"
#include "Randerer.h"
#include "Timer.h"
#include <stdio.h>
#include <stdlib.h>

bool App_Init(void)
{	
	if (false == Renderer_Init())
	{
		return false;
	}
	return true;
}

void ProgressInput(void)
{

}
char str[128];
int elapsedTime;
bool canShow = false;

void App_Update(void)
{
	Sleep(10);
	sprintf_s(str, sizeof(str), "delta time : %f", Timer_GetDeltaTime());
	
	elapsedTime += Timer_GetDeltaTime();
	
	if (elapsedTime >= 0.5f)
	{
		elapsedTime == 0.0f;
		canShow = !canShow;
	}
	if (canShow)
	{
		Renderer_DrawText(str, sizeof(strlen(str)));
	}

}
void Render(void)
{

	Renderer_Flip();//1. ȭ�� ��ȯ�ϱ�
	Renderer_Clear();//2. �� ������ ���� �����
}

int App_Run(void)
{
	Timer_Init();

	while (true)
	{
		Timer_Update();
		ProgressInput();
		App_Update();
		Render();
	}
	//���� ���� ���� �Է� -> ������Ʈ -> ���
}

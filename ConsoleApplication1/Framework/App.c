#include "App.h"
#include "common.h"
#include "Renderer.h"
#include "Timer.h"

bool App_Init()
{
	if (false == Renderer_Init())
	{
		return false;
	}
	return true;
}
void processInput()
{
	
}
void update()
{
	char str[128] = "";
	sprintf_s(str,sizeof(str), "���� FPS : %d", (int32)(1 / Timer_GetDeltaTime()));
	Renderer_DrawText(str, strlen(str));

	//Renderer_DrawText("Hello Game", sizeof("Hello Game"));
}
void render()
{
	Renderer_Flip();
}
void cleanup()
{
	Renderer_Cleanup();
}

int32 App_Run()
{
	atexit(cleanup);
	Timer_Init(60);
	// Game Loop : ������ ���۽�Ű�� ����. ������(Frame)�̶�� �Ѵ�.
	while (true)
	{
		//deltaTime : ������ ���� �ð�
		Timer_Update();
		processInput();      // �Է� ó��
		update();         // ���� ������Ʈ
		render();         // ���� ���
	}

	return 0;
}
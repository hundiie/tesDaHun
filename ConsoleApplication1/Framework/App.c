#include "type.h"
#include "App.h"
#include "common.h"
#include "Renderer.h"
#include "Timer.h"
#include "Input.h"
#include "Random.h"
#include "Text.h"

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

float elapsedTime;
bool canShow = false;
char str[128] = "";
Text text[128];
void update()
{
	TextCopy(text, L"�ؽ�Ʈ ���",0);
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
	Random_Init();
	Timer_Init(60);
	
	const int32 FIXED_FPS = 60;
	const float FIXED_TIME = 1.0f / FIXED_FPS;

	// Game Loop : ������ ���۽�Ű�� ����. ������(Frame)�̶�� �Ѵ�.
	while (true)
	{
		if (Timer_Update())
		{
			//deltaTime : ������ ���� �ð�
			Input_Update();
			processInput();      // �Է� ó��
			update();         // ���� ������Ʈ
			render();         // ���� ���
		}
	}

	return 0;
} 
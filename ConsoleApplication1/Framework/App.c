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

float elapsedTime;
bool canShow = false;

void update()
{
	char str[128] = "";
	sprintf_s(str,sizeof(str), "현재 FPS : %d", (int32)(1 / Timer_GetDeltaTime()));
	Renderer_DrawText(str, strlen(str));

	//0.5초 마다 깜박이는 텍스트

	elapsedTime += DELTA_TIME;

	if (elapsedTime >= 0.5f)
	{
		elapsedTime = 0.0f;
		canShow = !canShow;
	}
	if (canShow)
	{
		Renderer_DrawText("text", sizeof("text"));
	}
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
	
	const int32 FIXED_FPS = 60;
	const float FIXED_TIME = 1.0f / FIXED_FPS;

	// Game Loop : 게임을 동작시키는 루프. 프레임(Frame)이라고 한다.
	while (true)
	{
		if (Timer_Update())
		{
			//deltaTime : 프레임 간의 시간
			processInput();      // 입력 처리
			update();         // 게임 업데이트
			render();         // 게임 출력
		}
	}

	return 0;
}
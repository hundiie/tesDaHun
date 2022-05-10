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
	sprintf_s(str,sizeof(str), "현재 FPS : %d", (int32)(1 / Timer_GetDeltaTime()));
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
	// Game Loop : 게임을 동작시키는 루프. 프레임(Frame)이라고 한다.
	while (true)
	{
		//deltaTime : 프레임 간의 시간
		Timer_Update();
		processInput();      // 입력 처리
		update();         // 게임 업데이트
		render();         // 게임 출력
	}

	return 0;
}
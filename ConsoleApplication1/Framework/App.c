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
	TextCopy(text, L"텍스트 출력",0);
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

	// Game Loop : 게임을 동작시키는 루프. 프레임(Frame)이라고 한다.
	while (true)
	{
		if (Timer_Update())
		{
			//deltaTime : 프레임 간의 시간
			Input_Update();
			processInput();      // 입력 처리
			update();         // 게임 업데이트
			render();         // 게임 출력
		}
	}

	return 0;
} 
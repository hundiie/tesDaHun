#include "type.h"
#include "App.h"
#include "common.h"
#include "Renderer.h"
#include "Timer.h"
#include "Input.h"


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
char str[2][128] = { "" };

void update()
{
	int32 minVal = -45;
	int32 maxVal = 32;
	int32 randInt = Random_NumberInt(minVal, maxVal);
	assert(minVal <= randInt && randInt < maxVal);

	sprintf_s(str[0], sizeof(str[0]), "%d ~ %d 사이의 정수 : %d\n", minVal, maxVal, randInt);

	//float fminVal = -12.342f;
	//float fmaxVal = 25.982;
	//float frand = Random_NumberFloat(fminVal, fmaxVal);
	//assert(fminVal <= frand && frand <= maxVal);
	//
	//sprintf_s(str[1], sizeof(str[1]), "%f ~ %f 사이의 실수 : %f", fminVal, fmaxVal, frand);
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
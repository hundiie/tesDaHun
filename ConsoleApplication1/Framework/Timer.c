#include "Common.h"
#include "Timer.h"

clock_t s_prevTick;
float s_deltaTime;

void Timer_Init(void)
{
	// 시점을 하나 찍어준다.
	s_prevTick = clock();
}

void Timer_Update(void)
{
	// 1. 현재 시점을 구한다.
	clock_t currentTick = clock();

	// 2. 현재 시점과 이전 시점의 차이를 통해 흐른 시간을 구한다.
	s_deltaTime = (float)(currentTick - s_prevTick) / CLOCKS_PER_SEC;

	// 3. 이전 시점을 업데이트한다.
	s_prevTick = currentTick;
}

float Timer_GetDeltaTime(void)
{
	return s_deltaTime;
}
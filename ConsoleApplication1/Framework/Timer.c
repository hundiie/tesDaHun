#include "Common.h"
#include "Timer.h"

clock_t s_prevTick;
float s_deltaTime;

void Timer_Init(void)
{
	// ������ �ϳ� ����ش�.
	s_prevTick = clock();
}

void Timer_Update(void)
{
	// 1. ���� ������ ���Ѵ�.
	clock_t currentTick = clock();

	// 2. ���� ������ ���� ������ ���̸� ���� �帥 �ð��� ���Ѵ�.
	s_deltaTime = (float)(currentTick - s_prevTick) / CLOCKS_PER_SEC;

	// 3. ���� ������ ������Ʈ�Ѵ�.
	s_prevTick = currentTick;
}

float Timer_GetDeltaTime(void)
{
	return s_deltaTime;
}
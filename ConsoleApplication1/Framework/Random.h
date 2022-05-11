#pragma once
#include "Type.h"

//랜덤을 초기화 하는 함수
void Random_Init(void);

//정수 32비트를 랜덤으로 얻는 함수
int32 Random_NumberInt(int32 MinNumber, int32 MaxNumber);

//실수를 랜덤으로 얻는 함수
float Random_NumberFloat(float MinNumber, float MaxNumber);


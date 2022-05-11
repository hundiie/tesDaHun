#pragma once

#include "Type.h"

//랜더러 초기화

bool   Renderer_Init(void);
//런더러 정리
void   Renderer_Cleanup(void);
//화면 바꾸기
void   Renderer_Flip(void);
//텍스트를 출력한다.
void   Renderer_DrawText(const char* text, int32 numberOfChar);
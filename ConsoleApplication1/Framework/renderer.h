#pragma once

#include "Type.h"

//������ �ʱ�ȭ

bool   Renderer_Init(void);
//������ ����
void   Renderer_Cleanup(void);
//ȭ�� �ٲٱ�
void   Renderer_Flip(void);
//�ؽ�Ʈ�� ����Ѵ�.
void   Renderer_DrawText(const char* text, int32 numberOfChar);
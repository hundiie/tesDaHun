#pragma once
#include "Type.h"

//������ �ʱ�ȭ

bool   Renderer_Init(void);
//������ ����
void   Renderer_Cleanup(void);
//ȭ�� �ٲٱ�
void   Renderer_Flip(void);
//�ؽ�Ʈ�� ����Ѵ�.
void   Renderer_DrawText(const Text* text, int32 numberOfChar, int32 x, int32 y);
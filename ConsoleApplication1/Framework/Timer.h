#pragma once

#include "Type.h"

/// <summary>
/// Ÿ�̸Ӹ� �ʱ�ȭ�Ѵ�.
/// </summary>
/// ������Ʈ�� �����ϸ� �� �ƴϸ� ����
void   Timer_Init(int32 fps);

/// <summary>
/// Ÿ�̸Ӹ� ������Ʈ�Ѵ�.
/// </summary>
bool   Timer_Update(void);

/// <summary>
/// ��ŸŸ���� ���Ѵ�.
/// </summary>
/// <return>DeltaTime : ������ ���� �ð�. ���� ���������κ��� ���� �������� ������ ������ �ɸ� �ð�</return>
float   Timer_GetDeltaTime(void);

#define DELTA_TIME Timer_GetDeltaTime()
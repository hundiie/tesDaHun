#include <stdio.h>
#include "App.h"


int main(void)
{
	//1. ���α׷� �ʱ�ȭ
	//2. ���α׷� ����
	if (false ==App_Init())
	{
		puts("�� �ʱ�ȭ ����");

		return 1;
	}
	return App_Run();
}
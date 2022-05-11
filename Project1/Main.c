#include <stdio.h>
#include "App.h"


int main(void)
{
	//1. 프로그램 초기화
	//2. 프로그램 실행
	if (false ==App_Init())
	{
		puts("앱 초기화 실패");

		return 1;
	}
	return App_Run();
}
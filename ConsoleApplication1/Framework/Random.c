#include "Random.h"
#include "Type.h"
#include "Common.h"

#define SRAND srand(time(NULL));

int32 r_Int = 0;
float r_Float = 0;

void Random_Init(void)
{
	SRAND;

	r_Int = 0;
	r_Float = 0;
	
	return true;
}
//- 2,147,483,648 ~2,147,483,647
// 32, 767
int32 Random_NumberInt(int32 MinNumber, int32 MaxNumber)
{
	int k = (rand()%21475) * 10000;

	int a = k ;
	
	k = (rand()%8365) * 10;
	
	a += k;

	k = rand() % 10;//1자리

	if (a >= 2147483640)//변수 정리
	{
		k = rand() % 8;
	}

	a += k;
	
	r_Int = a % (MaxNumber - MinNumber + 1) + MinNumber;
	
	int h = rand() % 2;
	
	if (h == 0)
	{
		r_Int *= -1;
	}
	
	return r_Int;
}
//3.4e+38
float Random_NumberFloat(float MinNumber, float MaxNumber)
{
	r_Float = (rand() % 10000);
	float k = 0;
	float l = 1000000;
	k = r_Float / l;
	return k;
}
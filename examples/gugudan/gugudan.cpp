#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int inputNum;
	scanf("%d", &inputNum);
	for (int i = 1; i < 10; i++)
	{
		printf("%d * %d = %d\n", inputNum, i, inputNum * i);
	}
}



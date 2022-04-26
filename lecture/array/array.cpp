#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int arrayNum[1000];
	int firstNum;
	scanf("%d", &firstNum);

	int secondNum;

	for (int i = 0; i < firstNum; i++)
	{
		scanf("%d", &secondNum);
		arrayNum[i] = secondNum;
	}
	//printf("%d\n", arrayNum[0]);
	//printf("%d\n", arrayNum[1]);
	//printf("%d\n", arrayNum[2]);
	//printf("%d\n", arrayNum[3]);
	//printf("%d\n", arrayNum[4]);
}


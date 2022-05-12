#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


int main()

{
	int N;
	scanf("%d", &N);
	cycle(N);
}


void prectal(int i, int j, int N)
{
	if ((i / N) % 3 == 1 && (j / N) % 3 == 1) // 3으로 나눈 나머지가 1이거나, 
	{
		printf(" ");
	}

	else
	{
		if (N / 3 == 0)
		{
			printf("*");
		}
		else
		{
			prectal(i, j, N / 3);
		}
	}
}

void cycle(int N)
{
	int i, j;
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
		{
			//printf("*");
			prectal(i, j, N);
		}
		printf("\n");
	}[]
}
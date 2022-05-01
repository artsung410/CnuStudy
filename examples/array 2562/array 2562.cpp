#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int arr[9]; int maxNum; int rank;

	for (int i = 0; i < 9; i++)
	{
		scanf("%d", &arr[i]);
	}

	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (arr[i] > arr[j])
			{
				maxNum = arr[i];
				rank = i;
			}

			else
			{
				maxNum = arr[j];
				rank = i;
			}
		}
	}

	printf("%d\n", maxNum);
	printf("%d", rank);
	return 0;
}


#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


// 3052
int main()
{
	int arr[10] = { 0 };
	int result = 0;
	int inputNum = 0;

	for (int i = 0; i < 10; i++) // 담
	{
		scanf("%d", &inputNum);
		arr[i] = (inputNum % 42);
	}

	for (int i = 0; i < 10; i++)
	{
		int count = 0;
		for (int j = 0; j < i; j++)
		{
			if (arr[i] == arr[j])
			{
				count++;
			}
		}

		if (count == 0)
		{
			result++;
		}
	}

	printf("%d", result);
}


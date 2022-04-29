#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int testCase; int gradeNum;

	scanf("%d", &testCase);
	do
	{
		int sum = 0; float avg = 0;
		scanf("%d", &gradeNum);
		int arr[1000];

		for (int i = 0; i < gradeNum; i++)
		{
			scanf("%d", &arr[i]);
			sum += arr[i];
		}

		avg = (float)sum / gradeNum;

		int studentCount = 0;
		for (int i = 0; i < gradeNum; i++)
		{
			if (arr[i] > avg)
			{
				studentCount++;
			}
		}
		printf("%.3f%%\n", (studentCount * 100.0f / gradeNum)); // 암시적 형변환 int -> float 변환

		testCase--;

	} while (testCase > 0);

	return 0;
}
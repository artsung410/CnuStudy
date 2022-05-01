#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{

	// 입력 : ox 퀴즈의 결과를 입력받는다.

	// 처리 : 점수 계산
	// 1. O일때 점수가 늘어남
	// 2. 그 문제까지 연속된 O의 개수만큼 점수가 늘어남.

	// O - 1점
	// OO - 1점 + 2점
	// OOO - 1점 + 2점 + 3점
	// OOOO - 1점 + 2점 + 3점 + 4점

	// 1. 현재 문제를 맞췄는가?
	// 1-1. 맞았다면 연속적으로 맞춘만큼 점수를 부여한다.

	// 1. 현재 문제를 맞았는가?
	// 2. 그 문제까지 연속적으로 얼마나 맞췄는가?

	// 출력 : 점수 출력

	char oxResult[80];

	int T;
	scanf("%d ", &T);


	while (T > 0)
	{
		scanf("%79s", oxResult);

		int score = 0;
		int consecutiveCorrectAnswerCount = 0;
		for (int i = 0; oxResult[i] != '\0'; ++i)
		{
			// 현재 문제를 맞췄는가?
			if (oxResult[i] == 'O')
			{
				// 1 - 1 맞았다면 연속적으로 맞춘만큼 점수를 부여한다.
				++consecutiveCorrectAnswerCount;
				score += consecutiveCorrectAnswerCount;
			}
			else
			{
				consecutiveCorrectAnswerCount = 0;
			}
		}
		printf("%d\n", score);
		T--;
	}

	return 0;
}
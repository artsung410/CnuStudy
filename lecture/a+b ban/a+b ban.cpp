#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main()
{
	int N;
	scanf("%d", &N);

	int cycle = 0;
	int result = N;

	do{
		++cycle;

		int firstDigit = result % 10;
		int secondDigit = result / 10;
		int newNumber = secondDigit + firstDigit;

		result = firstDigit * 10 + newNumber % 10;
		

	}while (result != N);

	printf("%d", cycle);


	// 수를 기록해야하므로 변수를 만든다.
	// 1. 수가 10보다 작은가 ?
	// 1 - 1. 수에 10을 곱한다.
	// 1 - 2. 크다면 각 자리수를 구한다.
	// 1 - 2 - 1. 각 자리수를 더한다.
	// 1 - 2 - 2. 일의 자리수 * 10 + 새로운수의 일의 자리
	
	// 처음과 일치할 때까지 
}

//int A;
//while (1)
//{
//	scanf("%d", &A);
//	int firstNum = A / 10;
//	int secondNum = A % 10;

//	int firstNum = firstNum / 10;
//	int secondNum = A % 10;

//	printf("%d %d", firstNum, secondNum);
//}

//while (T > 0)
//{
//    scanf("%d %d", &A, &B);
//    printf("%d\n", A + B);
//    T--;
//}


//int num;
//
//scanf("%d", &num);
//
//int addNum = 0;
//for (int i = 0; i <= num; i++)
//{
//	addNum += i;
//}
//printf("%d", addNum);

// 15552
//int T;
//scanf("%d", &T);
//
//int A; int B;
//while (T > 0)
//{
//	scanf("%d %d", &A, &B);
//	printf("%d\n", A + B);
//	T--;
//}

// 2741
//int T;
//scanf("%d", &T);
//
//for (int i = 1; i <= T; i++)
//{
//	printf("%d\n", i);
//}

// 2742
//int T;
//scanf("%d", &T);
//
//while (T > 0)
//{
//	printf("%d\n", T--);
//}

//11021

//#include <stdio.h>
//
//int main()
//{
//	int T; int A; int B;
//	scanf("%d", &T);
//
//	for (int i = 1; i <= T; i++)
//	{
//		scanf("%d %d", &A, &B);
//		printf("Case #%d: %d\n", i, A + B);
//	}
//}

//11022
//#include <stdio.h>
//
//int main()
//{
//	int T; int A; int B;
//	scanf("%d", &T);
//
//	for (int i = 1; i <= T; i++)
//	{
//		scanf("%d %d", &A, &B);
//		printf("Case #%d: %d + %d = %d\n", i, A, B, A + B);
//	}
//}


// 10871
//#include <stdio.h>
//
//int main()
//{
//	int N;
//	int X;
//	scanf("%d %d", &N, &X);
//
//	int A = 0;
//	while (N > 0)
//	{
//		scanf("%d\n", &A);
//		if (A < X)
//		{
//			printf("%d ", A);
//		}
//		N--;
//	}
//}
// 
// in
// 1. 정수를 입력 받는다.
// 2. 입력 받은 정수가 x보다 작으면 출력한다.

//10952
//#include <stdio.h>
//
//int main()
//{
//	int A; int B;
//	while (1)
//	{
//		scanf("%d %d", &A, &B);
//		if (A != 0)
//		{
//			printf("%d\n", A + B);
//		}
//
//		if ((A == 0) && (B == 0))
//		{
//			break;
//		}
//	}
//}

//2438
//#include <stdio.h>
//
//int main()
//{
//	int starNum;
//	scanf("%d", &starNum);
//	for (int i = 1; i <= starNum; i++)
//	{
//		for (int j = 0; j < i; j++)
//		{
//			printf("*");
//		}
//		printf("\n");
//	}
//	printf("\n");
//}

// 2439
//#include <stdio.h>
//
//int main()
//{
//	int starNum;
//	scanf("%d", &starNum);
//	for (int i = 1; i <= starNum; i++)
//	{
//		for (int j = 0; j < i; j++)
//		{
//			for (int k = 0; k < (starNum - i); k++)
//			{
//				if (j > 0)
//					break;
//				printf(" ");
//			}
//			printf("*");
//		}
//		printf("\n");
//	}
//	printf("\n");
//}


// 10951
/*
#include <stdio.h>

int main()
{

	while (1)
	{
		int A, B;
		if (EOF == scanf("%d %d", &A, &B))
		{
			break;
		}
		printf("%d\n", A + B);
	}
}

*/

// 1110

/*
#include <stdio.h>

int main()
{
	int N;
	scanf("%d", &N);

	int cycle = 0;
	int result = N;

	do{
		++cycle;

		int firstDigit = result % 10;
		int secondDigit = result / 10;
		int newNumber = secondDigit + firstDigit;

		result = firstDigit * 10 + newNumber % 10;


	}while (result != N);

	printf("%d", cycle);


	// 수를 기록해야하므로 변수를 만든다.
	// 1. 수가 10보다 작은가 ?
	// 1 - 1. 수에 10을 곱한다.
	// 1 - 2. 크다면 각 자리수를 구한다.
	// 1 - 2 - 1. 각 자리수를 더한다.
	// 1 - 2 - 2. 일의 자리수 * 10 + 새로운수의 일의 자리

	// 처음과 일치할 때까지
}

*/
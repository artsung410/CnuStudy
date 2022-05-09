#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

//int factorial(int n);
//
//
//int pibonazzi(int n);


// 10진수를 2진수로 ?



// 3. 몫이 1이 될 때까지 반복한다.
// 4. 가장 마지막에 나온 몫부터 순서대로 적어나간다.

void binarry(int n)
{
	//3. 몫이 1이 될 때까지 반복한다.
	if (n == 0)
	{
		return;
	}

	// 1 . 2로 나눠서 몫과 나머지를 계산한다.
	int quo = n / 2;
	int rem = n % 2;

	// 2. 다시 그 몫에 대해서 2로 나눈다.
	binarry(quo);

	// 4. 나머지를 역순으로 출력한다.
	printf("%d", rem);
}

// binary(15) : quo(7), rem(1)
// binary(7) : quo(3), rem(1)
// binary(3) : quo(1), rem(1)
// binary(1) : quo(0), rem(1)
// binary(0) => 종료

int main()
{
	int N;
	scanf("%d", &N);
	binarry(N);
	return 0;
}

//int factorial(int n)
//{
//
//	if (n == 1)
//	{
//		return 1;
//	}
//
//	return n * factorial(n - 1);
//}
//
//
//int pibonazzi(int n)
//{
//	if (n <= 1)
//	{
//		return n;
//	}
//	return pibonazzi(n - 1) + pibonazzi(n - 2);
//}



#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


int main() 
{
	//int h;
	//int min;

	//scanf("%d %d", &h, &min);

	//if (h > 0)
	//{
	//	if (min - 45 >= 0)
	//	{
	//		printf("%d %d", h, min - 45);
	//	}

	//	else if (min - 45 < 0)
	//	{
	//		printf("%d %d", h - 1, 60 + (min - 45));
	//	}
	//}
	//else
	//{
	//	if (min - 45 >= 0)
	//	{
	//		printf("%d %d", h, min - 45);
	//	}

	//	else if (min - 45 < 0)
	//	{
	//		printf("%d %d", 23, 60 + (min - 45));
	//	}
	//}

	int H;
	int M;
	int A;
	scanf("%d %d", &H, &M);
	if ((0 <= H && H <= 23) && (0 <= M && M <= 59))
	{
		A = M - 45;
		if (A < 0 && H != 0)
		{
			A = 60 + A;
			H = H - 1;
		}

		else if (A > 0 && H != 0)
		{
			H = H - 1;
		}

		else if (A < 0 && H == 0)
		{
			A = 60 + A;
			H = 23;
		}
	}

	printf("%d %d", H, A);
}
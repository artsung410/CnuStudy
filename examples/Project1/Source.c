#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


int main(void)
{

	// 최대나올수있는 글자수50 + null = 51

	char str[100]; //Empty String 
	char alphabet[27] = "abcdefghijklmnopqrstuvwxyz"; //baekjoon
	scanf("%100s", str); 

	int count = 0;
	int ocount = 0;
	for (int i = 0; alphabet[i] != NULL; ++i)
	{
		for (int j = 0; str[j] != NULL; ++j)
		{
			if (str[j] == alphabet[i] )
			{
				if (str[j] == 'o')
				{
					ocount++;
				}
				printf("%d ", j);

				count = 1;
			}
		}

		if (count == 0)
		{
			printf("%d ", -1);
		}

		count = 0;
	}

	return 0;

}
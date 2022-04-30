#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


int main(void)
{

	int testCase;
	scanf("%d", &testCase);

	char str[21];
	char Sword[21];
	
	int repeatCharNum;
	while (testCase > 0) 
	{
		scanf("%d", &repeatCharNum);
		scanf("%20s", str);

		for (int j = 0; str[j] != NULL; j++)
		{
			for (int i = 0; i < repeatCharNum; i++)
			{
				printf("%c", str[j]);
			}
		}
		printf("\n");
		testCase--;
	}
	return 0;
}
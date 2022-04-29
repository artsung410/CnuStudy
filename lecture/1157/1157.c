#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


int main(void)
{


	char text[1000001] = { 0 };
	scanf("%1000000s", text);
	// 처리 : 가장 많이 사용된 알파벳이 무엇인지 알아내야함.

	// 각 알파벳이 몇개나 사용됐는지 세야함. => 객체가 필요하다.

	int counts[26] = { 0 };
	// Index를 알파벳과 대응 => 어떻게 알파벳과 index를 대응시킬지
	// a, A => 0
	// b, B => 1
	// c, C => 2
	// d, D => 3
	
	// 1. 단어에 있는 모든 알파벳의 개수를 센 후에 거기서 최댓값을 찾는다.
	// 2. 세어 가면서 최댓값을 찾는다. 

	int maxCount = 0;// 3. 최댓값은 무엇인지?
	char maxAlphabet = '\0'// 4. 그에 대응하는 알파벳은 무엇인지?

	//printf("%s", pickAlphabet);

	//for (int i = 0; alphabet[i] != NULL; ++i)
	//{
	//	for (int j = 0; sword[j] != NULL; ++j)
	//	{
	//		if (alphabet[i] == sword[j])
	//		{
	//			++pickAlphabet[i];
	//		}
	//	}
	//	pickAlphabet[i] = 1;
	//}

	//printf("%s", pickAlphabet);
	//for (int i = 0; pickAlphabet[i] != NULL; ++i)
	//{
	//	printf("%c ", pickAlphabet[i]);
	//}

	return 0;
}

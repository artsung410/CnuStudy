// ConsoleApplication3.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <stdlib.h>

int main()
{
	srand(time(NULL));
	int minInclusive = 0;
	int range = 33333;
	int count = 1 + range / RAND_MAX;

	int result = 0;
	for (int i = 0; i < count; ++i)
	{
		result += rand() % range;
		std::cout << i<< "번째 돌림" << result << std::endl;
	}
	result += minInclusive;

    std::cout << result;
}
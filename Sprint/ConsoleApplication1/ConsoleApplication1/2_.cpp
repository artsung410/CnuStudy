#include <iostream>

using namespace std;

int main()
{
	srand(time(NULL));

	int resultNum = 1 + rand() % 10;

	std::cout << "숫자를 입력하세요 : ";
	int myNum;
	std::cin >> myNum;

	if (myNum == resultNum)
	{
		std::cout << "true" << "\n";
	}
	else if (myNum < resultNum)
	{
		std::cout << "더 큰수 입니다." << "\n";
	}
	else if (myNum > resultNum)
	{
		std::cout << "더 작은수 입니다." << "\n";
	}

	std::cout << "정답은 " << resultNum << "이었습니다!!" << "\n";
}
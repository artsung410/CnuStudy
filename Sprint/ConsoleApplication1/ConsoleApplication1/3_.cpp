/*
#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{

	srand(time(NULL));
	int answer;
	answer = rand() % 100;		<=  0 도 포함되서 출력된다

	cout << "1 ~ 100 사이의 숫자를 하나 입력하시오" << endl;
	int mynum = 0;
	cin >> mynum;

	if (answer == mynum)
	{
		cout << "승리" << endl;
	}
	int chance;
	for (chance = 5; chance > 0; chance--)
	{
		cout << "오답입니다" << endl;
		cout << "남은 기회는 " << chance << "번 입니다";
		cin >> mynum;
		if (answer > mynum)
		{
			cout << "정답보다 낮습니다" << endl;
		}
		else if (answer < mynum)
		{
			cout << "정답보다 높습니다" << endl;
		}
		if (chance == 1)
		{
			cout << "컴퓨터 승! 정답은 " << answer << endl;
		}
	}
}
*/

#include <iostream>

using namespace std;

int main()
{
	srand(time(NULL));

	int result = 1 + rand() % 100;
	int myNum;
	for (int i = 5; i > 0; i--)
	{
		std::cout << "숫자를 입력하시요 : ";
		std::cin >> myNum;

		if (myNum > result)
		{
			std::cout << "정답보다 높습니다. (남은 기회 " << i << " )" << std::endl;
		}
		else if (myNum < result)
		{
			std::cout << "정답보다 낮습니다. (남은 기회 " << i << " )" << std::endl;
		}
		else if (myNum == result)
		{
			std::cout << "정답입니다." << std::endl;
			break;
		}
	}

	if (myNum != result)
	{
		std::cout << "컴퓨터 승! 인간패배 정답은 " << result << "이었습니다." << std::endl;
	}
}
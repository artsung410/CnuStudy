/*
양의 정수 X의 각 자리가 등차수열을 이룬다면, 그 수를 한수라고 한다.
ex) 123 -> 한수 
	369 -> 한수

첫째줄 자연수 N (1000보다 작거나 같다)
출력 입력수보다 작거나 같은 한수의 개수 출력
*/
#include <iostream>

using namespace std;

void ArithmeticNumber(int n)
{
	int cnt = 0;

	int action = n;
	int digitNum = n;

	for(int i = 0; i < action; i++)
	{
		int digit[4] = { 0 };
		// 자연수를 자릿수별로 
		int idx = 0;
		while(digitNum != 0)
		{
			digit[idx] = digitNum % 10;
			digitNum /= 10;
			idx++;
		}

		digitNum = --n;

		// [i] - [i + 1] = [j]
		// [j] == [j+1]

		// 각 자리수 차이가 같으면 ++cnt
		// 두자리수와 한자리수는 한수다
		if ((digit[0] - digit[1] == digit[1] - digit[2] || digitNum < 99) && (digit[3] != 1))
		{
			++cnt;
		}
	}

	cout << cnt;
}

int main()
{
	int inputNum;
	cin >> inputNum;

	ArithmeticNumber(inputNum);
}
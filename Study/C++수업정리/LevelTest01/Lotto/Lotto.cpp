#include <iostream>

using namespace std;

/// <summary>
/// 로또 번호를 만든다.
/// </summary>
/// <param name="maxValue">최대 번호값</param>
/// <param name="digitCount">생성 숫자 개수</param>
/// <returns>로또 번호들 (동적 할당된) </returns>
int* MakeLotto(int maxValue, int digitCount);

int main()
{
	// 입력 : 최대 번호값과 생성 숫자 개수 입력 받는다.
	cout << "최대 번호 값을 입력하세요. : ";
	int maxValue;
	cin >> maxValue;

	cout << "생성할 숫자의 개수를 입력하세요. : ";
	int digitCount;
	cin >> digitCount;

	// 처리 : 로또 생성 
	int* lotto = MakeLotto(maxValue, digitCount); // 생성? 생성자

	// 출력 : 로또 번호 출력
	for (int i = 0; i < digitCount; ++i)
	{
		cout << lotto[i] << " ";
	}

	delete[] lotto;

	return 0;
}

int* MakeLotto(int maxValue, int digitCount)
{
	// 1 ~ maxValue 사이의 값 중 중복되지 않게 digitCount만큼 뽑음.
	int* lotto = new int[digitCount];

	srand(time(nullptr));

	// 로또 번호 정하기
	// 3. 1번부터 digitCount만큼 반복한다.
	for (int curPos = 0; curPos < digitCount; ++curPos)
	{
		int candidate = 0;
		bool isExist = false;

		do
		{
			// 1. [1, maxValue] 사이의 값으로 무작위로 뽑는다.
			candidate = 1 + rand() % maxValue;
			isExist = false;

			// 2. 중복인지 확인한다. => 이미 나온 값인지 확인한다.
			for (int i = 0; i < curPos; ++i)
			{
				// 2-1. 중복이면? 1번을 다시 수행한다.
				if (candidate == lotto[i])
				{
					isExist = true;

					break;
				}
			}
		} while (isExist);

		// 2-2. 중복이 아니면? 데이터를 저장한다.
		lotto[curPos] = candidate;
	}

	return lotto;
}

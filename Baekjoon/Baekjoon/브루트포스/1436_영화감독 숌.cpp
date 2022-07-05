#include <iostream>

using namespace std;

#define MAX_SIZE 10000

int N;
// N번째 영화제목을 배열에 저장
int titleNum[MAX_SIZE];
int findNum;
int cnt;

int main()
{
	int startNum = 666;
	// 6이 연속3번이상 나오는 수들을 작은순서대로 배열에 저장하기
	while (cnt < MAX_SIZE)
	{
		// 임시저장
		int temp = startNum;
		// 자릿수에 6 나올때마다 카운트
		int sixCount = 0;

		int i = 0;
		// 66606이 배열에 안담김
		while ( temp)
		{
			int sixDigit = temp % 10;
			
			// 이 과정을 숫자 전체를 확인해야함
			// 666006 같은경우를 생각하면
			if (sixDigit == 6) // 6이 나오면 +1
			{
				sixCount++;
			}
			else // 그외 값이나오면 0으로
			{
				sixCount = 0;
			}
			// 연속으로 6이 나오면 sixCount가 바로 3이된다.
			// 6이 연속3번나왔을때
			if (sixCount == 3)
			{
				titleNum[cnt] = startNum;
				cnt++;
			}
			temp /= 10;
		}
		++startNum;
	}

	cin >> N;
	cout << titleNum[N - 1];
}


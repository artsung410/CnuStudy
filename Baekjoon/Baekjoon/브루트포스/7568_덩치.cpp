/*
몸무게 키 -> 덩치

A	(55, 185)	2
B	(58, 183)	2
C	(88, 186)	1
D	(60, 175)	2
E	(46, 155)	5

공동2등 가능

*/
#include <iostream>
#include <algorithm>

#define MAX_MEN 50

using namespace std;

int bulk[MAX_MEN][2];
int weight, height;
int N;

int rankArr[MAX_MEN];

int main()
{
	cin >> N;

	// 몸무게 키 입력
	for (int i = 0; i < N; i++)
	{
		cin >> weight >> height;

		bulk[i][0] = weight;
		bulk[i][1] = height;
	}
	
	// 하나하나씩 비교하기위해서 이중반복문 사용
	// 이중for문을 사용하면 하나를 고정하고 나머지들을 순차적으로 비교할수있다.
	for (int i = 0; i < N; i++)
	{
		int cnt = 1;
		for (int j = 0; j < N; j++)
		{
			// 비교할 몸무게, 키가 다른 대상보다 작을경우
			// 순위카운트를 증가시킨다.
			// 몸무게가 크지만 키는 작은경우 등수가 같은등수면서, 4등이아닌 2등임을 고려해
			// 논리합 연산자 사용
			if (bulk[i][0] < bulk[j][0] && bulk[i][1] < bulk[j][1]) // 비교값이 최소값일수록 많이 실행된다. 즉, 순위카운트가 올라감
			{
				cnt++;
			}
		}
		rankArr[i] = cnt; // 순위를 저장한 배열, 순서는 덩치배열과 동일하다.
	}

	for (int i = 0; i < N; i++)
	{
		cout << rankArr[i] << " ";
	}
	
}

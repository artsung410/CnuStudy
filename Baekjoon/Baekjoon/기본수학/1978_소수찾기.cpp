#include <iostream>

using namespace std;

#define MAX_LINE 100
#define MAX_NUM 1000

int N;
int cnt;
int arr[MAX_NUM];
int input;

int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> input;

		// 소수판별
		// 나눴을때 1과 자기자신
		// 1은 제외

		// 소수면
		int least = 0;
		for (int j = 1; j <= input; j++)
		{
			if (input % j == 0)
			{
				least++;
			}
		}
		if (least == 2)
		{
			cnt++;
		}
	}

	cout << cnt;
}

// 4 1 2 4
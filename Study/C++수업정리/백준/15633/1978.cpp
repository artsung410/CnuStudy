#include <iostream>

using namespace std;

#define MAX_NUM 1001

int arr[1001];

int main()
{
	int N;

	cin >> N;

	int yaksu = 0;
	int result = 0;

	for (int i = 0; i < N; i++)
	{
		int inputNum = 0;
		cin >> arr[i];
	}

	int cnt = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 1; j < arr[i]; j++)
		{
			if (arr[i] % j == 0)
			{
				++cnt;
			}
		}

		if (cnt == 1)
		{
			result += 1;
		}

		cnt = 0;
	}
	
	cout << result;


	return 0;
}
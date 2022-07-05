#include <iostream>

using namespace std;

int N; // [1, 1000000]

int main()
{
	// 분해합 입력
	cin >> N;

	for (int i = 1; i < N; i++)
	{
		int sum = i;
		int ans = i;

		while (sum)
		{
			int digits = sum % 10;
			ans = ans + digits;
			sum /= 10;
		}

		if (ans == N)
		{
			cout << i;
			return 0;
		}
	}

	cout << 0;
}
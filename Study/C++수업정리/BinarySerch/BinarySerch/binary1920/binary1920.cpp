#include <iostream>
#include <algorithm>

int arr[100'000];

int main()
{
	std::ios::sync_with_stdio(false);
	std::cout.tie(nullptr);
	std::cin.tie(nullptr);

	int N;
	std::cin >> N;
	for (int i = 0; i < N; ++i)
		std::cin >> arr[i];

	std::sort(arr, arr + N);

	int M;
	std::cin >> M;
	for (int i = 0; i < M; ++i)
	{
		int num;
		std::cin >> num;

		bool isExist = false;
		int s = 0, e = N;
		while (s < e)
		{
			// 중간 지점 구하고
			int m = (s + e) / 2;

			// 비교하고
			if (arr[m] == num)
			{
				isExist = true;
				break;
			}
			// 그거에 따라서 범위 조정
			else if (arr[m] < num)
			{
				s = m + 1;
			}
			else
			{
				e = m;
			}
		}

		std::cout << (isExist ? "1\n" : "0\n");
	}
}
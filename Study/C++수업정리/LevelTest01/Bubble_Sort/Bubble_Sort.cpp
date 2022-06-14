//https://visualgo.net/en/sorting
#include <iostream>

using namespace std;

void Sort(int* arr, int size)
{
	// 버블 소트는 여러 페이즈로 이뤄지며,
	// 각 페이즈가 끝날 시 맨 끝 원소부터 정렬된다.
	for (int phase = 0; phase < size; ++phase)
	{
		// 첫 번째 원소부터 비교해나간다.
		for (int i = 0; i < size - 1 - phase; ++i)
		{
			// 정렬 조건 : 현재 원소가 다음 원소보다 클 때(오름차순)
			if (arr[i] > arr[i + 1])
			{
				// 서로 바꾼다.
				std::swap(arr[i], arr[i + 1]);
			}
		}
	}
}

int main()
{
	int arr[10] = { 5, 2, 4, 1, 3, 7, 8, 4, 5, 4 };
	Sort(arr, 10);

	for (int i = 0; i < 10; ++i)
	{
		cout << arr[i] << " ";
	}

	return 0;
}
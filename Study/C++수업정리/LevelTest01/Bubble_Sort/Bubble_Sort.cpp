//https://visualgo.net/en/sorting
//#include <iostream>

//using namespace std;
//
//void Sort(int* arr, int size)
//{
//	// 버블 소트는 여러 페이즈로 이뤄지며,
//	// 각 페이즈가 끝날 시 맨 끝 원소부터 정렬된다.
//	for (int phase = 0; phase < size; ++phase)
//	{
//		// 첫 번째 원소부터 비교해나간다.
//		for (int i = 0; i < size - 1 - phase; ++i)
//		{
//			// 정렬 조건 : 현재 원소가 다음 원소보다 클 때(오름차순)
//			if (arr[i] > arr[i + 1])
//			{
//				// 서로 바꾼다.
//				std::swap(arr[i], arr[i + 1]);
//			}
//		}
//	}
//}
//
//int main()
//{
//	int arr[10] = { 5, 2, 4, 1, 3, 7, 8, 4, 5, 4 };
//	Sort(arr, 10);
//
//	for (int i = 0; i < 10; ++i)
//	{
//		cout << arr[i] << " ";
//	}
//
//	return 0;
//}

#include <iostream>

#define arrSize 10
#define X 3
#define Y 2

using namespace std;

int *PrintSort(int *arr, int size)
{
	for (int i = 0; i < size; ++i) {
		arr[i] = 7 * (i + 1);
	}
	*(arr + 3) = 777;
	return arr;
}

typedef int(*Array2D)[X];

Array2D PrintSort2(int(*arr)[X], int x, int y)
{
	int count = 1;
	for (int i = 0; i < y; i++)
	{
		for (int j = 0; j < x; j++)
		{
			arr[i][j] = count++;
		}
	}
	return arr;
}

int main()
{
	// 1차원 배열
	cout << "[1차원 배열 출력]" << endl;
	int arr[arrSize] = { 1, 2, 3, 4, 5}; 
	int* arrPtr = PrintSort(arr, arrSize);

	for (int i = 0; i < arrSize; ++i) {
		cout << arrPtr[i] << " ";
	}
	cout << "\n\n";



	// 2차원 배열
	cout << "[2차원 배열 출력]" << endl;
	int arr2[Y][X];

	int (*arrPtr2)[X] = PrintSort2(arr2, X, Y);

	for (int i = 0; i < Y; i++)
	{
		for (int j = 0; j < X; j++)
		{
			cout << arrPtr2[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "\n";

	return 0;
}
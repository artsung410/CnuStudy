#include <iostream>

#define arrSize 5
#define X 3
#define Y 2

using namespace std;

void PrintSort(int* arr, int size)
{
	arr[3] = 777;
	for (int i = 0; i < size; ++i)
	{
		cout << arr[i] << " ";
	}
	cout << "\n";
}

void PrintSort2(int(*arr)[X], int x, int y)
{
	for (int i = 0; i < y; i++)
	{
		for (int j = 0; j < x; j++)
		{
			cout << arr[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "\n";
}

int main()
{
	int arr[arrSize] = { 1, 2, 3, 4, 5 };
	int arr2[Y][X] = {
		{1, 2, 3},
		{4, 5, 6}
	};

	cout << "[1차원 배열 출력]" << endl;
	PrintSort(arr, arrSize);	cout << "\n"; // result : 1, 2, 3, 777, 5

	cout << "[2차원 배열 출력]" << endl;
	PrintSort2(arr2, X, Y);		cout << "\n"; /* result: 1, 2, 3
														 4, 5, 6       */

	return 0;
}
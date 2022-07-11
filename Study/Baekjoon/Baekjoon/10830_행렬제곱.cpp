#include <iostream>

using namespace std;

int arr[5][5] = { 0 };
int resultArr[5][5] = { 0 };

int main()
{
	int N, r; 
	cin >> N >> r;

	// 2, 5

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> arr[i][j];
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cout << arr[i][j] << ' ';
		}
		cout << '\n';
	}

	// 1
	resultArr[0][0] = (arr[0][0] * arr[0][0] + arr[0][1] * arr[1][0]);
	resultArr[0][1] = (arr[0][0] * arr[0][1] + arr[0][1] * arr[1][1]);
	resultArr[1][0] = (arr[1][0] * arr[0][0] + arr[1][1] * arr[1][0]);
	resultArr[1][1] = (arr[1][0] * arr[0][1] + arr[1][1] * arr[1][1]);

	// 2
	resultArr[0][0] = (arr[0][0] * resultArr[0][0] + arr[0][1] * resultArr[1][0]);
	resultArr[0][1] = (arr[0][0] * resultArr[0][1] + arr[0][1] * resultArr[1][1]);
	resultArr[1][0] = (arr[1][0] * resultArr[0][0] + arr[1][1] * resultArr[1][0]);
	resultArr[1][1] = (arr[1][0] * resultArr[0][1] + arr[1][1] * resultArr[1][1]);

	// 3
	resultArr[0][0] = (arr[0][0] * resultArr[0][0] + arr[0][1] * resultArr[1][0]);
	resultArr[0][1] = (arr[0][0] * resultArr[0][1] + arr[0][1] * resultArr[1][1]);
	resultArr[1][0] = (arr[1][0] * resultArr[0][0] + arr[1][1] * resultArr[1][0]);
	resultArr[1][1] = (arr[1][0] * resultArr[0][1] + arr[1][1] * resultArr[1][1]);
	
	//4 
	resultArr[0][0] = (arr[0][0] * resultArr[0][0] + arr[0][1] * resultArr[1][0]);
	resultArr[0][1] = (arr[0][0] * resultArr[0][1] + arr[0][1] * resultArr[1][1]);
	resultArr[1][0] = (arr[1][0] * resultArr[0][0] + arr[1][1] * resultArr[1][0]);
	resultArr[1][1] = (arr[1][0] * resultArr[0][1] + arr[1][1] * resultArr[1][1]);

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cout << resultArr[i][j] << ' ';
		}
		cout << '\n';
	}

	return 0;
}
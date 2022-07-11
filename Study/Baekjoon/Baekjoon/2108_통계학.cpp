#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

int arr[500001];
int digitCount[8001];

vector<int> v;
vector<int> trueNum;

int avg(int n, int * arr)
{
	double addNum = 0;

	for (int i = 0; i < n; i++)
	{
		addNum += arr[i];
	}

	if (addNum < 0)
	{
		return -1 *(double)round(abs(addNum / n));
	}
	else
	{
		return (double)round(addNum / n);
	}
}

int max(int n, int* arr)
{
	sort(arr, arr + n);

	int result = *(arr + (n - 1)) - *arr;

	return result;
}

int center(int n, int* arr)
{
	sort(arr, arr + n);

	return arr[(n - 1) / 2];
}

int usually(int n, int* arr)
{

	int max = 0;
	for (int i = 0; i < 8001; i++)
	{
		if (max < digitCount[i])
		{
			max = digitCount[i];

			if (v.size() != 0)
			{
				v.clear();
			}

			if (i < 4001)
			{
				v.push_back(i);
			}

			else if (i >= 4001)
			{
				v.push_back(4000 - i);
			}
		}

		else if (max == digitCount[i])
		{
			max = digitCount[i];

			if (i < 4001)
			{
				v.push_back(i);
			}
			else
			{
				v.push_back(4000 - i);
			}
		}
	}

	sort(v.begin(), v.end());

	if (v.size() > 1)
	{
		return v[1];
	}
	else
	{
		return v[0];
	}
}

int main()
{
	int N;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		int inputNum;
		cin >> inputNum;
		arr[i] = inputNum;
		if (inputNum >= 0)
		{
			++digitCount[inputNum];
		}
		else
		{
			++digitCount[4000 - inputNum];
		}
	}

	cout << avg(N, arr) << '\n';
	cout << center(N, arr) << '\n';
	cout << usually(N, arr) << '\n';
	cout << max(N, arr);

	return 0;
}
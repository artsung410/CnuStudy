#include <iostream>
#include <algorithm>

using namespace std;
#define MAX 1001

int arrSize;
int arr[MAX];

int main()
{

	int sum = 0;
	cin >> arrSize;

	for (int i = 0; i < arrSize; i++)
	{
		cin >> arr[i];
		sum += arr[i];
	}

	sort(arr, arr + arrSize);

	float average = (float)sum / arrSize;
	float new_average = average / arr[arrSize - 1] * 100;

	cout << new_average << endl;

	return 0;
}
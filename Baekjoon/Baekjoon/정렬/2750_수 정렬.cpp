#include <iostream>
#include <algorithm>

using namespace std;
int arr[10000];
int main()
{
	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}

	for (int i = 0; i < N; i++)
	{
		sort(arr, arr + N);
		cout << arr[i] << "\n";
	}
}
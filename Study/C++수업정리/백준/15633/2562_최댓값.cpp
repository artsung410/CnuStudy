#include <iostream>
#include <algorithm>
#include <stack>

#define LOOP 9

using namespace std;
stack<int> st;

int main()
{
	int arr[LOOP];
	int max = 0;

	for (int i = 0; i < LOOP; i++)
	{
		cin >> arr[i];
		st.push(arr[i]);
	}

	sort(arr, arr + LOOP);

	cout << arr[LOOP - 1] << "\n";
	
	int cnt = 0;

	while (!st.empty())
	{
		if (st.top() == arr[LOOP - 1])
		{
			cout << LOOP - cnt;
		}
		st.pop();
		++cnt;
	}
}

// sort¿Í stack ÀÌ¿ë....
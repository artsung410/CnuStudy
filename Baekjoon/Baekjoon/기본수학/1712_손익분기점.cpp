#include <iostream>

using namespace std;

#define MAX_COST 2100000000

int A, B, C;

int main()
{
	cin >> A >> B >> C;

	if ((C - B) <= 0)
	{
		cout << -1;
		return 0;
	}
	else if (C - B > 0)
	{
		int ans = A / (C - B) + 1;
		cout << ans;
	}
}
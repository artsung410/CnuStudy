#include <iostream>
#include <string>
#include <stack>

using namespace std;
int digitCount[26] = { 0 };

stack<int> st;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	string str;
	cin >> str;

	char alpha1;
	char alpha2;

	int size = str.size();
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < 26; j++)
		{
			alpha1 = j + 65;
			alpha2 = j + 97;

			if ((str[i] == alpha1) || (str[i] == alpha2))
			{
				digitCount[j]++;
				break;
			}
		}
	}

	st.push(0);
	int max = 0;
	int maxAlpahbetCount = 0;
	int sameCnt = 0;
	char result;

	for (int i = 0; i < 26; i++)
	{
		if (digitCount[i] != 0 && st.top() <= digitCount[i])
		{
			if (st.top() == digitCount[i])
			{
				++sameCnt;
			}

			max = i;
			maxAlpahbetCount = digitCount[i];
			st.push(digitCount[i]);
		}
	}

	if (maxAlpahbetCount == st.top() && sameCnt > 0)
	{
		if (maxAlpahbetCount > 1)
		{
			result = max + 65;
			cout << result;
		}
		else
		{
			cout << "?";
		}
	}

	else
	{
		result = max + 65;
		cout << result;
	}


	return 0;
}
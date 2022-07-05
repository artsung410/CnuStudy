#include <iostream>
#include <string>
#include <stack>

using namespace std;
int digitCount[26] = { 0 };

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

	int maxIndex = 0;
	int maxdigit = digitCount[0];

	int cnt = 0;
	char result;
	for (int i = 0; i < 26; i++)
	{
		if (digitCount[i] >= maxdigit)
		{
			maxdigit = digitCount[i];
			maxIndex = i;
		}
	}

	if (maxdigit == 1 && maxIndex == 0) // abcde
	{
		cout << "?";
	}

	else
	{
		result = 65 + maxIndex;
		cout << result;
	}

	return 0;
}
#include <iostream>
#include <string>

using namespace std;

int main()
{
	string str;

	cin >> str;

	char myCh;

	for (int i = 97; i < 123; i++)
	{
		myCh = i;
		for (int j = 0; j < str.size(); j++)
		{
			if (str[j] == myCh)
			{
				cout << j << " ";
				break;
			}

			if (j == str.size() - 1)
			{
				cout << -1 << " ";
				break;
			}
		}
	}


	return 0;
}
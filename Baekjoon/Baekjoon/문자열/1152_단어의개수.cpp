#include <iostream>
#include <string>

using namespace std;

#define BLANK ' '

string input;
int cnt;
int strIdx;

int main()
{
	getline(cin, input);
	int strLen = input.length();

	for (int i = 0; i < strLen; i++)
	{
		if (input[i] == BLANK)
			cnt++;
	}

	if (input[0] == ' ' && strLen != 1)
	{
		if (input[strLen - 1] == BLANK)
		{
			cnt--;
		}
		cout << cnt;
	}
	else if (input[strLen - 1] == BLANK && strLen != 1)
	{
		cout << cnt;
	}
	else if (input[strIdx] == BLANK && strLen == 1)
	{
		cout << 0;
	}
	else
	{
		cout << cnt + 1;
	}

}
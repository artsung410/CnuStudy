#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
	vector <int> stack;
	int length;

	cin >> length;

	for (int i = 0; i < length; i++)
	{
		string command;
		cin >> command;

		if (command == "push")
		{
			int num;
			cin >> num;
			stack.push_back(num);
		}

		else if (command == "pop")
		{
			if (stack.empty())
			{
				cout << "-1" << endl;
			}
			else
			{
				cout << stack.back() << endl;
				stack.pop_back();
			}
		}

		else if (command == "size")
		{
			cout << stack.size() << endl;
		}

		else if (command == "empty")
		{
			cout << stack.empty() << endl;
		}

		else if (command == "top")
		{
			if (stack.empty())
			{
				cout << "-1" << endl;
			}
			else
			{
				cout << stack.back() << endl;
			}
		}

	}
}
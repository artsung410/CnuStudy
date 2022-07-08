#include <iostream>
#include <stack>

using namespace std;

int main()
{
	stack<int> sung;

	sung.push (10);
	sung.push (20);
	sung.push (30);

	while (!sung.empty())
	{
		cout << sung.top() << endl;
		sung.pop();
	}

	cout << boolalpha << "스택이 비어 있나요? : " << sung.empty() << endl;

	return 0;

}

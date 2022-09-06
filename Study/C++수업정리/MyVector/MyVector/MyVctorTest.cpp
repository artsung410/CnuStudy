#include <iostream>

#include "MyVector.h"

using namespace std;

int main()
{
	MyVector mvec;
	MyVector mvec2(5);

	mvec.push_back(1);
	mvec.push_back(2);
	mvec.push_back(3);
	mvec.push_back(4);
	mvec.push_back(5);
	mvec.pop_back();

	mvec.erase(mvec.begin());

	for (size_t i = 0; i < mvec.size(); ++i)
	{
		cout << mvec[i] << " ";
	}


	cout << endl;
}

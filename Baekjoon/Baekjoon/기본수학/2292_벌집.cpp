#include <iostream>

using namespace std;

#define MAX_NUM 1'000'000'000

int N;

int main()
{
	/*
	1  6   17   34  58
	 5   11   17  24
	   6    6    7


	1 4 13
	 3  9
	   6

	1  2  9  22

	  1  7  13

	    6  6
		  
	*/

	cin >> N;

	if (N == 1)
	{
		cout << 1;
	}
	else if(N == 2 || N == 3 || N == 4 || N == 5 || N == 6 || N == 7)
	{
		cout << 2;
	}
	else
	{

	}

}
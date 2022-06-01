#include <iostream>


class A
{
	int _privateData;

public:
	int publicData;
};

A a;


// 메모리에 표현되는 것은 C의 구조체의 그것과 같다.
// [_data(4)] [padding(4)[ _data(8)]

int main()
{
	a._privateData;
	a.publicData;

	return 0;
}
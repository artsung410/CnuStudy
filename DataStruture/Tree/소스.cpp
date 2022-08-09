#include "Set.h"
#include <initializer_list>
#include <iostream>

using namespace std;

int main()
{
	auto initList = { 10, 5, 1, 6, 17, 14, 21 };

	Set s;
	for (int elem : initList)
	{
		s.insert(elem);
	}
	
	cout << "전위순회\n";
	s.traverseByPreorder();
	cout << endl;
	cout << endl;

	cout << "중위순회\n";
	s.traverseByInorder();
	cout << endl;
	cout << endl;

	cout << "후위순회\n";
	s.traverseByPostorder();
	cout << endl;
	cout << endl;

	cout << "레벨순회\n";
	s.traverseByLevelorder();
	cout << endl;

	/*Set s;

	for (int i = 0; i < 5; i++)
	{
		s.insert(i);
	}*/

	std::cout << s.height() << " " << s.height2();

}
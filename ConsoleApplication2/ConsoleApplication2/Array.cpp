#include <iostream>

using namespace std;

// arr = &arr[i]
// arr + 1 &arr[0] + 1
//int main()
//{
//    int arr[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
//
//    for (int i = 0; i < 10; i++)
//    {
//        cout << "&arr["<< i << "] = " << *(arr + i)<< endl;
//    }
//}

/*
	1. arr = &arr[0]
	2. *ptr = arr[0]
	3. ptr + 1 = ptr에 sizeof(*ptr)를 더한 값
*/


//int main()
//{
//	int arr[2][3] = { {1, 2, 3}, {4, 5, 6} };
//	//cout << sizeof(arr) << endl; // 24
//	//cout << sizeof(arr[0]) << endl; //12
//	//cout << sizeof(arr[0][0]) << endl; //4
//
//	int(*ptr)[3] = arr;
//
//	// 1. ptr[i] = arr[i]
//	// 2. ptr[i][j] = arr[i][j]
//	// ptr = arr
//	for (int i = 0; i < 2; i++)
//	{
//		for (int j = 0; j < 3; j++)
//		{
//			cout << ptr[i][j] << " ";
//		}
//		cout << endl;
//	}
//}


// 배열 포인터 : 배열을 가리키는 포인터	int (*ptr)[4];
// 포인터 배열 : 포인터들이 들어있는 배열' int *ptr[4];
int main()
{
	//int arr[4] = { 1, 2, 3, 4 };

	//int* ptr[4];

	//for (int i = 0; i < 4; i++)
	//{
	//	ptr[i] = &arr[i];
	//}

	//for (int i = 0; i < 4; i++)
	//{
	//	cout << *ptr[i] << endl;
	//}

	char strings[3][10] = { "Hello", "World", "artsung" };
	char* p_str[3];

	for (int i = 0; i < 3; i++)
	{
		p_str[i] = strings[i];
	}

	for (int i = 0; i < 3; i++)
	{
		cout << p_str[i] << endl;
	}

}

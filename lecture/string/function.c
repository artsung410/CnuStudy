#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


// 2개의 정수를 받아 서로 데이터를 교환


//void swap(int* x, int* y)
//{
//	int temp = *x;
//	*x = *y;
//	*y = temp;
//}
//
//// islower() : 한 개의 문자를 받아 소문자인지 판별한다.
//
//int isLower(char alphabet)
//{
//	if ( 'a' <= alphabet && alphabet <= 'z')
//	{
//		return 1;
//	}
//	else
//	{
//		return 0;
//	}

//int isLower(char alphabet)
//{
//	if ('a' <= alphabet && alphabet <= 'z')
//	{
//		return 1;
//	}
//	else
//	{
//		return 0;
//	}
//}

// tolower() / toupper()

//char tolower(char ch)
//{
//	ch = (int)ch + 32;
//	return ch;
//}
//
//char toupper(char ch)
//{
//	ch = (int)ch - 32;
//	return ch;
//}


// strlen() : 문자열의 길이를 구하는 함수
// 배열을 받으려면 포인터를 사용해야 한다.
// 배열을 매개변수로 받는 함수는 배열의 크기를 같이 받는다.
// 문자열의 끝은 널 문자(Null Character)다. => 따라서 배열의 크기를 알지 않아도 끝을 알 수 있다.
// 매개변수 1개 => 문자열을 저장하기 위한 객체 => pointer to char


// 어떻게 문자열의 길이를 구할 수 있을까?

// 1. str은 문자열이다.
// 2. 문자열의 끝은 널 문자다.

int strlen(const char* str)
{
	int legnthCount = 0;
	for (int i = 0; str[i] != NULL; ++i)
	{
		++legnthCount;
	}
	return legnthCount;
}


// strchr() : 문자열에서 특정 문자의 위치를 찾는 것
// 입력 : 문자열(const char*), 내가 찾을 문자(const char)
// 1. 문자가 있는 경우 => 그 문자의 위치
// 2. 문자가 없는 경우 => NULL

// strrchr()
char* strchr(const char* str, const char ch)
{

	while (*str != '\0')
	{
		if (*str == ch)
		{
			return str;
		}
		++str;
	}
	return NULL;
}


int main()
{
	////int arr[10];
	//const char * str = "// 배열을 받으려면 포인터를 사용해야 한다.배열을 매개변수로 받는 함수는 배열의 크기를 같이 받는다. 문자열의 끝은 널 문자(Null Character)다. => 따라서 배열의 크기를 알지 않아도 끝을 알 수 있다.매개변수 1개 => 문자열을 저장하기 위한 객체 => pointer to char";
	
	const char* str = "hello";
	char ch = 'l';
	printf("%p", strchr(str, ch));

	return 0;
}


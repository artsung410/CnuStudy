#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <string>

using namespace std;

void PrintName(string name);

void PrintText();

void printAdult(int age);

void printAverage(int a, int b);

void PrintFour();

int main()
{
	cout << "이름을 입력하세요 : ";
	string inputName;
	cin >> inputName;
	PrintName(inputName);

	PrintText();

	cout << "나이를 입력하세요 : ";
	int age;
	cin >> age;
	printAdult(age);

	cout << "첫번째 정수 : ";
	int A;
	cin >> A;
	cout << "두번째 정수 : ";
	int B;
	cin >> B;
	printAverage(A, B);

	PrintFour();
}

void PrintName(string name)
{
	cout << "\'" << name << "\'" << "씨 사랑해요!" << endl;
}

void PrintText()
{
	cout << "\'소환사의 협곡에 오신 것을 환영합니다\'" << endl;
}

void printAdult(int age)
{
	if (age <= 19)
	{
		cout << "미성년자" << endl;
	}
	else
	{
		cout << "성년" << endl;
	}
}

void printAverage(int a, int b)
{
	float avg = (float)(a + b) / 2;
	cout << avg << endl;
}

void PrintFour()
{
	cout << "첫번째 정수 : ";
	int A;
	cin >> A;
	cout << "두번째 정수 : ";
	int B;
	cin >> B;
	float avg = (float)(A + B) / 2;
	cout << avg << endl;
}

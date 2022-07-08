#include <unordered_map> // key값으로 hash value를 찾는데 시간이 적게걸림 평균 O(1) 흔히 사용하는 hash 자료구조
#include <map> // key값 기준으로 정렬되있음. 이진탐색트리로 구현되면서 정렬하므로 value값을 찾는데 unordered보다 오래걸릴수있다.
#include <string>
#include <iostream>

enum Gender
{
	MALE,
	FEMALE,
};

struct Student
{
	bool IsOnGlasses;
	Gender Gender;
	bool IsCodingGosu;
	int Age;
};

using namespace std;

ostream& operator<<(ostream& out, const Student& student)
{
	out << "=========================================\n";
	if (student.IsOnGlasses)
	{
		out << "이 학생은 안경을 썻습니다.\n";
	}
	else
	{
		out << "이 학생은 안경을 안 썻습니다.\n";
	}

	if (student.Gender == MALE)
	{
		out << "남자\n";
	}
	else
	{
		out << "여자\n";
	}

	if (student.IsCodingGosu)
	{
		out << "코딩고수입니다.\n";
	}
	else
	{
		out << "노력중이지요\n";
	}

	if (student.Age)
	{
		out << "나이는 " << student.Age << "살 입니다.\n";
	}
	out << "=========================================\n";

	return out;
}

int main()
{
	// assosiative? key-value 쌍으로 이루어짐

	unordered_map<string, Student> hashTable;

	std::hash<string> hash; // string타입의 해시값을 생성하는 과정. 해시타입에는 호출연산자 operator()가 오버로딩되어있어 함수처럼 사용할수있다.
	size_t value = hash("최서연"); // 어떤값을 넣든지 간에 size_t(8바이트)값으로 나온다

	hashTable["최서연"] = { false, FEMALE, true, 22 };
	hashTable["홍승완"] = { false, MALE, false, 30 };
	hashTable["성권문"] = { false, MALE, false, 35 };
	hashTable["김동현"] = { true, MALE, false, 28 };

	cout << hashTable["최서연"];
	cout << hashTable["홍승완"];
	cout << hashTable["성권문"];
	cout << hashTable["김동현"];

}
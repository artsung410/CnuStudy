#include <iostream>
#include <unordered_map>
#include <string>

enum Gender { MALE, FEMALE };

struct Student
{
    bool IsOnGlasses;
    Gender Gender;
    bool IsCodingGosu;
    int age;
};

using namespace std;

ostream& operator << (ostream& oss, const Student& student)
{
    oss << "------------------------------------\n";
    if (student.IsOnGlasses)
    {
        oss << "이 학생은 안경을 썼습니다. \n";
    }
    else
    {
        oss << "이 학생은 안경을 쓰지 않았습니다. \n";
    }

    if (student.Gender == MALE)
    {
        oss << "이 학생은 남자입니다. \n";
    }
    else
    {
        oss << "이 학생은 여자입니다. \n";
    }

    if (student.IsCodingGosu)
    {
        oss << "이 학생은 코딩고수 \n";
    }
    else
    {
        oss << "그닥 \n";
    }

    if (student.IsOnGlasses)
    {
        oss << "안경씀 \n";
    }
    else
    {
        oss << "안경 안씀 \n";
    }

    oss << "------------------------------------\n";

    return oss;
}

int main()
{
    unordered_map<string, Student> hashTable;

    hashTable["성권문"] = { false, MALE, true, 29 };
    hashTable["용준헌"] = { true, FEMALE, true, 27 };
    hashTable["홍승완"] = { true, FEMALE, true, 30 };

    cout << hashTable["성권문"];
    cout << hashTable["용준헌"];
    cout << hashTable["홍승완"];

}

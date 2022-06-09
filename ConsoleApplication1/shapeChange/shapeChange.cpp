#include <iostream>
#include <string>

// 묵시적(암시적) 형변환 imlicit conversion
// 명시적 형변환 explicit conversion

using namespace std;

class Item {


public:
    explicit  Item(int num) : num(num)
    {
        // 변환 생성자
        cout << "Item(int)" << endl;
    }

    explicit  Item(string name) : name(name)
    {
        cout << "Item(string)" << endl;
    }

    explicit  Item(int num, string name) : num(num), name(name)
    {
        cout << "Item(int, string)" << endl;
    }

    void print()
    {
        cout << num << " : " << name << endl;
    }

    // int로의 형변환 연산자 오버로딩
    explicit operator int() const
    {
        return num;
    }

    // string으로의 형변환 연산자 오버로딩
    operator string() const
    {
        return to_string(num) + " : " + name;
    }

private:
    int num;
    string name;

};

void println(string s)
{
    cout << s << endl;
}

int main()
{
    Item i1 = Item(1);
    Item i2(2);
    Item i3 = 3;
    i3 = 3; // 묵시적 변환
    Item i4 = (Item)4; // 명시적 변환

    Item i5(5);
    i5 = (string)"stone";

    Item i6(1, "grass");
    Item i7 = { 2, "dirt" };
    i7 = { 2, "dirt" };
    Item i8{ 3, "wood" };

    int itemNum1 = (int)i8;
    int itemNum2 = i7;

    cout << itemNum1 << endl;
    cout << itemNum2 << endl;

    println((string)i8); // 명시적 형변환
    println(i8); // 묵시적 형변환
}

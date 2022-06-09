#include <iostream>

using namespace std;

class Vector2
{
public:
	Vector2() : x(0), y(0)
	{
		cout << this << " : Vector2()" << endl;
	}

	Vector2(const float x, const float y) : x(x), y(y)
	{
		cout << this << " : Vector2(const float x, const float y)" << endl;
	}
	~Vector2()
	{
		cout << this << " : ~Vector2()" << endl;
	}

	float GetX() const { return x; }
	float GetY() const { return y; }

private:
	float x;
	float y;
};

int main()
{
	Vector2 s1 = Vector2(); // 정적 할당 -> 데이터 영역에 저장
	Vector2 s2 = Vector2(3, 2); // 정적 할당 -> 데이터 영역에 저장

	Vector2* d1 = new Vector2(); // 동적 할당 -> 힙 영역에 저장
	Vector2* d2 = new Vector2(3, 2); // 동적 할당 -> 힙 영역에 저장

	cout << "(" << d1->GetX() << ", " << d1->GetY() << ")" << endl;
	cout << "(" << d2->GetX() << ", " << d2->GetY() << ")" << endl;

	delete d1; // 메모리 해제
	delete d2; // 메모리 해제
}

#include <iostream>

using namespace std;


class Vector2
{
public: 
	Vector2();
	Vector2(float x, float y);
	
	float GetX() const;
	float GetY() const;

	Vector2 operator+(const Vector2& rhs) const;
	Vector2 operator-(const Vector2& rhs) const;
	Vector2 operator*(const float rhs) const;
	Vector2 operator/(const float rhs) const;
	float operator*(const Vector2& rhs) const;

private:
	float x;
	float y;

};

// 생성자 초기화
Vector2::Vector2() : x(0), y(0) { }

Vector2::Vector2(float x, float y) : x(x), y(y) {}


// x값 반환
float Vector2::GetX() const { return x; }


// y값 반환
float Vector2::GetY() const { return y; }


// 연산자 오버로딩
Vector2 Vector2::operator+(const Vector2& rhs) const
{
	return Vector2(x + rhs.x, y + rhs.y);
}

Vector2 Vector2::operator-(const Vector2& rhs) const
{
	return Vector2(x - rhs.x, y - rhs.y);
}

Vector2 Vector2::operator*(const float rhs) const
{
	return Vector2(x * rhs, y * rhs);
}

Vector2 Vector2::operator/(const float rhs) const
{
	return Vector2(x / rhs, y / rhs);
}

float Vector2::operator*(const Vector2& rhs) const
{
	return x * rhs.x + y * rhs.y;
}

int main()
{
	Vector2 a(2, 3);
	Vector2 b(-1, 4);
	Vector2 c = a + b;
	Vector2 c1 = a - b;
	Vector2 c2 = a * 1.6;
	Vector2 c3 = a / 2;
	float c4 = a * b;

	cout << c.GetX() << ", " << c.GetY() << endl; // 1, 7
	cout << c1.GetX() << ", " << c1.GetY() << endl; // 3, -1
	cout << c2.GetX() << ", " << c2.GetY() << endl; // 3.2, 4.8
	cout << c3.GetX() << ", " << c3.GetY() << endl; // 1, 1.5
	cout << c4 << endl; // 10
}




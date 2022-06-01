#include <iostream>
using namespace std;


//class JoonHeon
//{
//private:
//
//	int age;
//	int tall;
//
//public:
//	JoonHeon(int my_age, int my_tall) : age(my_age), tall(my_tall)
//	{
//
//	}
//
//	JoonHeon(const JoonHeon& copy_JoonHeon) : age(copy_JoonHeon.age), tall(copy_JoonHeon.tall)
//	{
//		cout << "허니의 아바타가 생성되었습니다." << endl;
//	}
//
//	void ShowJoonheonInfo()
//	{
//		cout << "준헌이의 나이는? : " << age << endl;
//		cout << "준헌이의 키는? : " << tall << endl;
//	}
//};
//
//
//
//
//struct SDL_Texture
//{
//	int num1;
//	int num2;
//};
//
//
//
//class Image
//{
//
//public :
//	Image(int x, int y, int alpha) : _Width(x), _Height(y), _Alpha(alpha), _ScaleX(1), _ScaleY(1)
//	{
//		cout << "이미지 생성자 호출" << endl;
//	}
//
//	Image(const char* filename)
//	{
//		//Load(filename);
//		cout << "이미지 불러오기 완료" << endl;
//	}
//	~Image()
//	{
//		cout << "이미지 소멸자 호출" << endl;
//	}
//
//	void Get_Value()
//	{
//		cout << "이미지 랜더링중... " << endl;
//		cout << "이미지 출력중... " << endl;
//		cout << "" << endl;
//		cout << "[Image Info]" << endl;
//		cout << "Width : " << _Width << endl;
//		cout << "Height : " << _Height << endl;
//		cout << "Alpha : " << _Alpha << endl; 
//		cout << "ScaleX : " << _ScaleX << endl;
//		cout << "ScaleY : " << _ScaleY << endl;
//
//	}
//
//	void Set_Value(int mod_x, int mod_y, int mod_alpha)
//	{
//		cout << " " << endl;
//		cout << "이미지 수정중..." << endl;
//		cout << "이미지 출력중... " << endl;
//		cout << " " << endl;
//
//		cout << "이미지 수정이 완료되었습니다" << endl;
//		_Width = mod_x;
//		_Height = mod_y;
//		_Alpha = mod_alpha;
//	}
//
//private:
//	int	_Width;
//	int	_Height;
//	int _Alpha;
//	float _ScaleX;
//	float _ScaleY;
//};
//
//
//class Base1
//{
//public:
//	
//	void Foo() 
//	{
//		cout << "Base1의 Foo()" << endl;
//	}
//};
//
//class Base2
//{
//public:
//
//	void Foo()
//	{
//		cout << "Base의 Foo()" << endl;
//	}
//};
//
//
//class Vector2D
//{
//public:
//	// 두 벡터끼리 더할 수 있어야 함
//	// 두 벡터끼리 뺄 수 있어야함
//	// 스칼라 곱
//	
//private:
//
//};

// 물리량
// 스칼라 : 단순 수치(ex. 10, 3.14)
// 벡터 : 스칼라 _ 방향

// 2차원
// V = (x 좌표, y 좌표)
// Ex. V = (1, 2)

class Vector2D
{
public:
	// 생성자 : 필드의 초기화
	Vector2D()
		: Vector2D(0, 0) {}

	Vector2D(int x, int y)
		: _x(x), _y(y) {}

	// 접근자(Getter)
	int GetX() const { return _x; }
	int GetY() const { return _y; }

	// 설정자(setter)
	void SetX(int x) { _x = x; }
	void SetY(int y) { _y = y; }

	// 두 벡터끼리 더할 수 있어야 함
	Vector2D operator+(const Vector2D& rhs) const
	{
		// lhs + rhs
		// lhs => this; 나 자신이 됨.
		// rhs : 매개변수로 적어줌.
		return Vector2D(_x + rhs._x, _y + rhs._y);
	}

	// 두 벡터끼리 뺄 수 있어야 함
	Vector2D operator-(const Vector2D& rhs) const
	{
		return Vector2D(_x - rhs._x, _y - rhs._y);
	}

	// 스칼라 곱
	// 왼쪽 피연산자 : 나 자신 (Veector2D)
	// 오른쪽 피연산자 : 정수값(int)
	Vector2D operator*(int rhs) const
	{
		return Vector2D(_x * rhs, _y * rhs);
	}

	// 반환 타입 식별자(매개변수 목록) {함수 바디}
	// 두 벡터끼리 뺄 수 있어야함
	// 스칼라 곱
private:
	int _x;
	int _y;
};

// 변수를 private에 넣고 접근자와 설정자를 두는 이유 :

// 1. 데이터 은닉에 위반 => 객체지향적 설계에 맞지 않음.
// - 데이터 은닉(Data Hiding) : 구현 세부 사항에 사용되는 데이터를 외부에 노출하지 않는 것
// 2. 디버깅이 어려워짐.
// 3. 확장성이 떨어짐.



class Mother
{
	int age;

public:
	Mother() { cout << "Mother Constructor" << endl; }
	~Mother() { cout << "Mother Destructor" << endl; }

	virtual void Foo()
	{
		cout << "Mother::Foo()\n";
	}

};


class Son : public Mother
{
public:
	Son() { cout << "Son Constructor" << endl; }
	~Son() { cout << "Son Destructor" << endl; }

	virtual void Foo()
	{
		cout << "Son::Foo()\n";
	}
};


// [상속]
// 생성은 부모 클래스부터 자식 클래스 순으로 하게 된다.
// 소멸은 반대로 자식 클래스에서 부모 클래스 순으로 하게 된다.
// public 상속의 의미
// public 상속은 자식에게 public 멤버로 만들고 protected멤버를 protected멤버로 만든다.

// 다중상속 : 콤마로 구분한다. 
// 다중상속의 문제점 : 인스턴스를 만들고 함수를 호출할때, 어떤 부모클래스의 함수를 호출해야할지 모호해서 컴파일 오류가 날 수있다.
// 이를 죽음의 다이아몬드(The Deadly Diamond) 현상이라고 한다.


int main()
{
	Son son;
}


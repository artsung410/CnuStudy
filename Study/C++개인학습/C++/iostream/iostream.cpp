#include <iostream> // 표준 파일 입출력은 이 헤더를 포함해야 한다.
#include <iomanip>  // 입출력과 관련된 조작을 위한 헤더다.


int main()
{
    // 출력은 << 연산자를 사용하면 된다.
    std::cout << "Hello World!\n";

    // 포맷팅도 가능하다.
    // 1. 정수 관련 포맷
    std::cout << 12 << "\n";     // "12"
    std::cout << std::hex;       // 16진수로 출력한다.
    std::cout << 12 << "\n";     // "c"
    std::cout << std::showbase;  // 진법을 표현한다.
    std::cout << 12 << "\n";     // "0xc"
    // 다시 원래대로 되돌린다.
    std::cout << std::dec << std::noshowbase;

    // 2. 실수 관련 포맷
    std::cout << 12.34 << "\n";         // "12.34"
    std::cout << std::fixed;            // 소수점 자리를 고정시켜 표현한다.
    std::cout << 12.34 << "\n";         // "12.340000"
    std::cout << std::setprecision(12); // 소수점 자리를 12자리로 고정한다.
    std::cout << 12.34 << "\n";         // "12.340000000000"
    // 다시 원래대로 되돌린다.
    std::cout << std::defaultfloat << std::setprecision(6);

    // 3. 불리언 관련 포맷
    std::cout << std::boolalpha;    // 불리언 값을 출력할 때 숫자 대신 문자로 출력한다.
    std::cout << true << "\n";      // "true"
    // 다시 원래대로 되돌린다.
    std::cout << std::noboolalpha;

    // 4. 정렬 관련 포맷
    std::cout << std::setfill('*'); // 공백대신 *출력
    std::cout << std::setw(12);     // 출력 길이를 일시적으로 12로 지정한다.
    std::cout << std::left;         // 왼쪽 정렬
    std::cout << std::hex << std::showbase;
    std::cout << 42 << "\n";        // "0x2a********"
    // 계속 같은 길이를 사용하려면 width()을 사용한다.
    std::cout.width(12);
    std::cout << std::right; // 오른쪽 정렬
    std::cout << 42 << "\n"; // "********0x2a"
    // 다시 원래대로 되돌린다.
    std::cout << std::setfill(' ');
    std::cout.width(0);

    // 입력은 >> 연산자를 사용하면 된다.
    std::cout << "숫자를 입력하세요 : ";
    int num;
    std::cin >> num;

    // good() / fail()로 오류 여부를 알 수 있다.
    if (std::cin.good())
    {
        std::cout << "숫자를 입력함.\n";
    }
    else if (std::cin.fail())
    {
        std::cout << "숫자가 아닌 다른 값을 입력함.\n";
        std::cin.clear(); // clear()를 사용하면 객체를 정상화할 수 있다.
    }

    // bool 타입으로 변환이 가능하다.
    if (std::cin)
    {
        std::cout << "오류가 없음.\n";
    }
    else
    {
        std::cout << "오류 발생함.\n";
    }

    return 0;
}
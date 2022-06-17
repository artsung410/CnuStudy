#include <iostream>
#include <string> // std::string을 쓰고 싶다면 이 헤더를 포함해야 한다.
#include <assert.h>

int main()
{
    std::string s = "Hello";
    std::cout << s << "\n";

    // empty()로 빈 문자열인지 확인할 수 있다.
    if (s.empty())
    {
        std::cout << "빈 문자열이다.\n";
    }

    // length() / size()로 문자열의 길이를 알 수 있다.
    std::cout << "이 문자열의 길이는 " << s.length() << "\n";
    // std::cout << "이 문자열의 길이는 " << s.size() << "\n";

    // [] 연산자로 각 문자에 접근할 수 있다.
    // front()로 첫 번째 문자에, back()으로 마지막 문자에 접근할 수 있다.
    std::cout << "이 문자열의 3번째 문자는 " << s[2] << "\n";
    std::cout << "이 문자열의 1번째 문자는 " << s.front() << "\n";
    std::cout << "이 문자열의 마지막 문자는 " << s.back() << "\n";

    // clear()로 빈 문자열로 만들 수 있다.
    s.clear();
    if (s.empty())
    {
        std::cout << "빈 문자열이다.\n";
    }

    // push_back() / append() / + 연산자로 맨 끝에 문자(열)를(을) 삽입할 수 있다.
    s.push_back('H');   // "H"
    s.append("ello");   // "Hello"
    s += " World!";     // "Hello World!"
    std::cout << s << "\n";

    // insert()로 문자(열)를(을) 중간에 삽입할 수 있다.
    s.insert(5, " Inserted"); // "Hello Inserted World!"
    std::cout << s << "\n";

    // pop_back()으로 마지막 문자를 삭제할 수 있다.
    s.pop_back(); // "Hello Inserted World"
    std::cout << s << "\n";

    // erase()로 문자(열)를(을) 삭제할 수 있다.
    s.erase(5, 9); // "Hello World"
    std::cout << s << "\n";

    // ==, !=, <, > 연산자로 문자열을 비교할 수 있다.
    if (s == "Hello World")
    {
        std::cout << "Hello World와 같다.\n";
    }

    if (s != "Hello")
    {
        std::cout << "Hello와 다르다.\n";
    }

    if (s > "Hello")
    {
        std::cout << s << "가 Hello 뒤에 나온다.\n";
    }

    if (s < "Idle")
    {
        std::cout << s << "가 Idle 전에 나온다.\n";
    }

    // substr()로 문자열을 추출할 수 있다.
    std::cout << s.substr(6) << "\n";       // "World"
    std::cout << s.substr(0, 5) << "\n";    // "Hello"

    // 숫자와 문자열 간 변환도 가능하다.
    s = "3.14";
    float f = std::stof(s); // f(3.14)
    s = "142";
    int i = std::stoi(s); // i(142)
    s = std::to_string(f); // s("3.14")

    // 입력도 받을 수 있다.
    std::cout << "단어를 입력해주세요. : ";
    std::cin >> s;
    std::cout << s;
    std::cin.get();
    std::cout << "문장을 입력해주세요. : ";
    std::getline(std::cin, s);
    std::cout << s;

    return 0;
}


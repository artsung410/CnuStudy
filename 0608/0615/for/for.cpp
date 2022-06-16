#include <iostream>

using namespace std;

int main()
{
    // 1에서 100까지 출력
    for (int i = 1; i <= 100; i++)
    {
        cout << i << " ";
    }
    cout << "\n";


    int currentNumber = 1;
    for (int currentNumber = 0; currentNumber < 100; currentNumber++)
    {
        // 15의 배수는 FizzBuzz를 출력하낟.
        if (currentNumber % 3 == 0 && currentNumber % 5 == 0)
        {
            cout << "FizzBuzz\n";
        }

        // 3의 배수는 숫자대신 Fizz를 출력한다.
        else if (currentNumber % 3 == 0)
        {
            cout << "Fizz" << endl;
        }

        // 5의 배수는 숫자대신 buzz를 출력한다.
        else if (currentNumber % 5 == 0)
        {
            cout << "Buzz\n";
        }

        // 그 외의 숫자는 그대로 출력한다. 
        else
        {
            std::cout << currentNumber << "\n";
        }
    }
}

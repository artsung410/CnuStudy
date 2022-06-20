#include <iostream>

#include <string.h>// memset 함수 사용

using namespace std;
int main()
{
    int X, Y;
    while (1)
    {
        cout << "동적할당 // 행의 개수를 입력시오 :_"; cin >> Y;
        cout << "동적할당 // 열의 개수를 입력시오 :_"; cin >> X;
        cout << "\n";

        system("cls");

        int** arr = new int* [Y];
        for (int i = 0; i < Y; ++i)
        {
            arr[i] = new int[X];
            memset(arr[i], 0, sizeof(int) * X);   // 메모리 공간을 0으로 초기화
        }

        int count = 10;
        for (int i = 0; i < Y; i++)
        {
            for (int j = 0; j < X; j++)
            {
                arr[i][j] = count++;  // 배열에 원소 담기
            }
        }


        for (int i = 0; i < Y; i++)
        {
            for (int j = 0; j < X; j++)
            {
                cout << arr[i][j] << ", "; // 배열의 원소 출력
            }
            cout << "\n";
        }

        for (int i = 0; i < Y; ++i)
        {
            delete[] arr[i]; // 각 행의 배열 제거
        }

        delete[] arr; // 전체 배열 제거
    }

}

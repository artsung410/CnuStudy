// BinarySerch.cpp : This file c#include <algorithm>
#include <iostream>
#include <algorithm>
int main()
{
    int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

    // std::binary_search는 이진 검색으로 주어진 값을 찾는다.
    if (std::binary_search(arr, arr + 10, 3))
    {
        std::cout << "arr에는 3이 존재한다.\n";
    }

    int arr2[] = { 1, 2, 4, 5, 5, 6 };

    // std::lower_bound는 이진 검색으로
    // element >= value의 조건을 만족하는 값을 찾는다.
    std::cout << "\n[lower_bound]\n";
    for (int i = 0; i < 8; ++i)
    {
        int* lowerBound = std::lower_bound(arr2, arr2 + 6, i);

        std::cout << i << " <= ";
        if (lowerBound == arr2 + 6)
        {
            std::cout << "not found\n";
        }
        else
        {
            std::cout << *lowerBound << " at index " << lowerBound - arr2 << "\n";
        }
    }

    // std::upper_bound는 이진 검색으로
    // element < value의 조건을 만족하는 값을 찾는다.
    std::cout << "\n[upper_bound]\n";
    for (int i = 0; i < 8; ++i)
    {
        int* upperBound = std::upper_bound(arr2, arr2 + 6, i);

        std::cout << i << " < ";
        if (upperBound == arr2 + 6)
        {
            std::cout << "not found\n";
        }
        else
        {
            std::cout << *upperBound << " at index " << upperBound - arr2 << "\n";
        }
    }

    // std::equal_range는 이진 검색으로
    // value와 같은 원소의 범위를 찾는다.
    std::cout << "\n[equal_range]\n";
    // pair는 단순히 2가지의 데이터를
    // 담을 수 있는 타입이다.
    std::pair<int*, int*> range = std::equal_range(arr2, arr2 + 6, 5);
    if (range.first == arr2 + 3 && range.second == arr2 + 5)
    {
        std::cout << "arr2에서 5가 있는 곳은 arr2의 세 번째 원소부터 네 번째 원소까지다.\n";
    }

}


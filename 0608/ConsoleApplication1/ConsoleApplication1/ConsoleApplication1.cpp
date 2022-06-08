#include <iostream>
#include <vector>

using namespace std;

int main()
{
    // 벡터 생성하기

    vector<int> vec;
    cout << boolalpha << vec.empty() << endl;
    cout << vec.size() << endl;
    cout << vec.capacity() << endl;

    // 삽입
    // push_back
    vec.push_back(3);
    vec.push_back(4);
    vec.push_back(2);
    
    // {3, 4, 2}

    // 반복자
    // begin() : 컨테이너의 첫 원소를 가리키는 반복자
    // end() : 컨테이너의 마지막 원소의 다음을 가리키는 반복자
    for (vector<int>::iterator iter = vec.begin(); iter != vec.end(); ++iter)
    {
        cout << *iter << ",";
    }
    cout << endl;

    // rbegin() : 컨테이너의 마지막 원소를 가리키는 반복자
    // rend() : 컨테이너의 첫 원소의 이전을 가리키는 반복자
    for (vector<int>::reverse_iterator iter = vec.rbegin(); iter != vec.rend(); ++iter)
    {
        cout << *iter << ",";
    }
    cout << endl;



    // insert : pos 이전에 데이터를 삽입
    vector<int>::iterator iter = vec.begin();
    ++iter; // 2번째 원소 : 4

    iter = vec.insert(iter, 10); // vec : {3, 10, 4, 2}, iter : &vec[1] (10)
    iter = vec.insert(iter, 3, 5); // vec : {3, 5, 5, 5, 10, 4, 2}, iter : &ver[1] (5)
    iter = vec.insert(iter, vec.begin() + 3, vec.end() - 1); // vec : {3, 5, 10, 4, 5, 5, 5, 10, 4, 2}
                                                      // iter : &vec[1] (5)
    for (vector<int>::iterator iter = vec.begin(); iter != vec.end(); ++iter)
    {
        cout << *iter << ",";
    }

    // 삭제
    // pop_back : 맨 끝에 있는 데이터를 삭제
    // vec : {3, 5, 10, 4, 5, 5, 5, 10, 4, 2}
    vec.pop_back();
    vec.pop_back();
    vec.pop_back();
    // vec : {3, 5, 10, 4, 5, 5, 5, 10, 4, 2}

    // erase : pos에 있는 데이터를 삭제
    vec.erase(vec.begin());
    // vec : {5, 10, 4, 5, 5, 5}
    vec.erase(vec.begin() + 1, vec.begin() + 3);
    // vec : {5, 10, 4, 5, 5, 5, 10, 4, 2}

    // 읽기
    cout << vec.front() << endl; // 5
    cout << vec.back() << endl; // 5
    cout << vec[2] << endl; // 5

    // 검색 = > 메소드가 아니라 알고리즘 라이브러리에 존재

    // 다른 생성
    vector<int> vec(5); // {0, 0, 0, 0, 0}
    vector<int> vec3(5, 10); // {10, 10, 10, 10, 10}


    return 0;

    // inset : pos 이전에 데이터를 삽입

}


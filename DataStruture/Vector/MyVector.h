#pragma once

#include <utility>
class MyVector
{
public:
    // 기본 생성자
    MyVector();

    // count만큼 공간이 할당된 생성자
    explicit MyVector(size_t count);
    //    : _container(new int[count]), _size(count), _capacity(count)
    //{
    //    for (size_t i = 0; i < count; i++)
    //    {
    //        _container[i] = 0; //기본값 할당
    //    }
    //}

    // 복사 생성자. 깊은 복사(deep copy)가 이뤄져야 한다.
    MyVector(const MyVector& other);
    /*    : _container(new int[other._capacity]), _size(other._size), _capacity(other._capacity)
    {
        for (size_t i = 0; i < _size; i++)
        {
            _container[i] = other._container[i];
        }
    }*/

    // 할당 연산자. 깊은 복사(deep copy)가 이뤄져야 한다.
    MyVector& operator=(MyVector rhs);
    //{
    //    std::swap(_container, rhs._container);
    //    std::swap(_size, rhs._size);
    //    std::swap(_capacity, rhs._capacity);
    //
    //    return *this; // 자기자신을 반환해줘야 기본타입처럼 사용할수있음 
    //    /*
    //        int a, b;
    //        a = b = 5; 가능
    //            a.operator=(b.operator(5)); 
    //
    //        vector v1, v2, v3;
    //        v1 = v2 = v3; 가능
    //            v1.operator=(v2.operator(v3));
    //    */
    //}

    // 소멸자 : 자원정리
    ~MyVector();
    /*{
        clear();
    }*/

    // 첫 번째 요소를 가리키는 반복자를 반환한다. 모든 컨테이너에서 가지고있다
    int* begin()
    {
        // 벡터가 비어있다면 end() 반환
        if (empty())
        {
            return end();
        }

        // 비어있지않는다면 첫번째 원소를 가리키는 반복자 반환. 포인터를 반환하려면 주소값을 넘겨주면된다
        return _container;
    }
    const int* begin() const
    {
        //코드중복을 방지하기위한 기술은 아직 수련부족
        // 벡터가 비어있다면 end() 반환
        if (empty())
        {
            return end();
        }

        // 비어있지않는다면 첫번째 원소를 가리키는 반복자 반환. 포인터를 반환하려면 주소값을 넘겨주면된다
        return _container;
    }

    // 마지막 요소의 다음 번째를 가리키는 반복자를 반환한다.
    int* end()
    {
        // _container : 컨테이너의 주소
        // _size : 현재가지고있는 원소개수
        // _capacity : 최대원소의 개수
        return _container + _size;
    }
    const int* end() const { return _container + _size; }

    // 컨테이너가 비었는지 검사한다.
    bool                empty() const
    {
        if (0 == _size) // bigin() == end() 같다
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    // 원소의 개수를 반환한다.
    size_t              size() const { return _size; }

    // 현재 할당된 공간의 크기를 반환한다.
    size_t              capacity() const { return _capacity; }

    //// pos에 위치한 원소의 참조를 반환한다. 만약 pos가 범위에서 벗어나면 std::out_of_range 예외가 던져진다.
    //int& at(size_t pos);
    //const int& at(size_t pos) const; 예외처리안배움

    // pos에 위치한 원소의 참조를 반환한다.
    // vetor<int> v;
    // vector[2]
    int& operator[](size_t pos)
    {
        return _container[pos];
    }
    const int& operator[](size_t pos) const
    {
        return _container[pos];
    }

    // 컨테이너의 첫 번째 원소의 참조를 반환한다. 비어있는지 안 비어있는지 검사할필요없다?
    int& front()
    {
        return *begin(); //begin타입은 포인터여서 역참조연산자 가능
    }
    const int& front() const
    {
        return *begin();
    }

    // 컨테이너의 마지막 원소의 참조를 반환한다.
    int& back()
    {
        return *(end() - 1);
    }
    const int& back() const
    {
        return *(end() - 1);
    }

    // 컨테이너를 비운다.
    void                clear()
    {
        delete[] _container;
        //해제후 무효화된영역의 포인터 = 댕글링포인터
        // 댕글링포인터에 역참조하면 오류난다. 널포인터로 바꿔줘야한다
        _container = nullptr;
        _size = 0;
        _capacity = 0;
    }

    // pos "이전" 위치에 value를 삽입한다.
    // value가 삽입된 곳을 가리키는 포인터를 반환한다.
    int* insert(int* pos, int value)
    {
        //몇개를 옮겨야되는지 알아야하고
        // capacity를 알아야한다 -> 새로운공간확보후 이동
        
        //1. 처음으로부터 얼마나 떨어져있는지 확인
        int distance = pos - begin(); 

        //2. 용량확인
        if (_capacity == 0)
        {
            //빈용량이라면 용량할당
            reserve(1);

            // 새로 위치 잡아줌
            pos = begin() + distance;
        }
        else if (_size == _capacity)
        {
            reserve(_capacity * 2); // 가장효율적인 2배

            pos = begin() + distance; //위치새로잡아줌
        }

        //3. 삽입
        for (int* iter = end(); iter != pos; iter--) //end부터시작해 감소하면서
        {
            *iter = *(iter - 1); // 뒤로 밀어준다
        }
        *pos = value; //pos는 삽입된 값을 가리키는 반복자

        //4. 필드 데이터 최신화
        ++_size;

        return pos; // 가리키는 포인터를 반환한다.
    }

    // pos에 위치한 원소를 지운다.
    // 삭제된 요소의 다음 포인터를 반환한다.(위치는 변하지않음)
    int* erase(int* pos)
    {
        // If[first, last) is an empty range, then last is returned.
        // 1. 비어있다면 end반환
        if (_size == 0)
        {
            return end();
        }
        // If last == end() prior to removal, then the updated end() iterator is returned.
        // 2. 데이터 이동(삭제)
        int* last = end() - 1;
        for (int* iter = pos;  iter != last;  iter++)
        {
            *iter = *(iter + 1);
        }
        
        // 3. 필드 업데이트
        --_size;

        return pos;
    }

    // 컨테이너의 맨 끝에 원소를 추가한다.
    void                push_back(int value)
    {
        insert(end(), value);
    }

    // 컨테이너의 마지막 원소를 삭제한다.
    void                pop_back()
    {
        erase(end() - 1);
    }

    // value가 존재하는지 검사한다.
    bool                contains(int value)
    {
        for (size_t i = 0; i < _size; i++)
        {
            if (_container[i] == value)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
    }

    // 컨테이너의 용량을 newCapacity보다 같거나 크게 늘린다.
    // newCapacity > _capacity라면 새로운 메모리를 할당하고,
    // 그렇지 않다면 아무 동작도 수행하지 않는다.
    //reserve() does not change the size of the vector. reserve는 벡터의 사이즈를 바꾸지 않는다
    /*
    reserve하면 새로운 공간을할당함(메모리주소다름)
    할당후 이전 메모리는 free한다
    iter는 댕글링포인터가 되면서ㅓ 오류뜸
    */
    void                reserve(size_t newCapacity)
    {
        //1. newCapacity가 _capacity보다 큰지 크기비교
        if (newCapacity >= _capacity)
        {
            int* temp;
            //2. 새로운메모리할당
            temp = new int[newCapacity];

            for (size_t i = 0; i < _size; i++)
            {
             //3. 이전메모리데이터 복사
                temp[i] = _container[i];
            }
             //4. 이전메모리 해제
            delete[] _container;

            //5. 필드 데이터 수정 _capacity = newCapacity;
            _container = temp;
            _capacity = newCapacity;
        }
    }

private:
    int*    _container = nullptr; // 컨테이너의 주소
    size_t  _size = 0;            // 현재가지고있는 원소개수
    size_t  _capacity = 0;        // 최대원소의 개수
};

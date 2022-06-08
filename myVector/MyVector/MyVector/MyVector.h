#pragma once

#include <string>
#include <utility>
#include <sstream>
using namespace std;

struct MyObject
{
    int _id;
};


class MyVector
{
    using iterator = MyObject*;
    using const_iterator = const MyObject*;

private:
    size_t _size = 0; // 원소의 개수
    size_t _capacity = 0; // 벡터의 용량
    MyObject* _MyObjs = nullptr; // 벡터의 주소값

private:

    void reallocate(int newCapacity)
    {
        MyObject* newContainer = new MyObject[newCapacity];

        for (size_t i = 0; i < +_size; ++i)
        {
            newContainer[i] = _MyObjs[i];
        }

        delete[] _MyObjs;

        _MyObjs = newContainer;
        _capacity = newCapacity;
    }

    void reserve(int newCapacity)
    {
        if (_capacity >= newCapacity)
        {
            return;
        }

        MyObject* newContainer = new MyObject[newCapacity];

        for (size_t i = 0; i < +_size; ++i)
        {
            newContainer[i] = _MyObjs[i];
        }

        delete[] _MyObjs;

        _MyObjs = newContainer;
        _capacity = newCapacity;

    }

    iterator begin() { return _MyObjs; }
    const_iterator begin() const { return _MyObjs; }
    iterator end() const { return _MyObjs + _size; }
    //const_iterator end() const { return _MyObjs + _size; }

    //const_iterator end() const { return _MyObjs + _size; };

    iterator erase(iterator pos)
    {
        if (_size == 0)
        {
            return end();
        }

        iterator last = end() - 1;
        for (iterator iter = pos; iter != last; ++iter)
        {
            *iter = *(iter + 1);
        }

        --_size;

        return pos;
    }

public:
    // Constructor.

    MyVector() = default;

    MyVector(int capacity) : _MyObjs(new MyObject[capacity]), _size(0), _capacity(capacity){}

    // Copy constructor. -> 필드값들에 재 할당과정이 들어간다. 
    MyVector(const MyVector& other) 
        : _MyObjs(new MyObject[other._capacity]), _size(other._size),
        _capacity(other._capacity)
    {
        for (size_t i = 0; i < _size; i++)
        {
            _MyObjs[i] = other._MyObjs[i];
        }
    }

    // Assignment operator.
    MyVector& operator=(const MyVector& other)
    {
        if (this == &other)
        {
            return *this;
        }

        MyVector temp(other);
        std::swap(_MyObjs, temp._MyObjs);
        std::swap(_size, temp._size);
        std::swap(_capacity, _capacity);
    }

    // Destructor.
    ~MyVector()
    {
        delete[] _MyObjs;
        _MyObjs = nullptr;
        _size = 0;
        _capacity = 0;
    }

public: // 아래 기능 함수들을 .cpp 파일에 구현합니다.

    // Returns current capacity of this vector.
    int GetCapacity() const
    {
        return _capacity;
    }

    // Returns current size of this vector.
    int GetSize() const
    {
        return _size;
    }

    // Creates a new MyObject instance with the given ID, and appends it to the end of this vector.
    void Add(int id)
    {
        // 용량이 가득 찼을 떄!
        if (_capacity == _size)
        {
            reserve((_capacity == 0) ? 1 : _capacity * 2);
        }

        _MyObjs[_size]._id = id;
        ++_size;
    }

    // Returns the first occurrence of MyObject instance with the given ID.
    // Returns nullptr if not found.
    MyObject* FindById(int MyObjectId) const
    {
        for (size_t i = 0; i < _size; ++i)
        {
            if (_MyObjs[i]._id == MyObjectId)
            {
                return &_MyObjs[i];
            }
        }
        return nullptr;
    }

    // Trims the capacity of this vector to current size.
    void TrimToSize()
    {
        if (_size == _capacity)
        {
            return;
        }

        reallocate(_size);
    }

    // Returns the MyObject instance at the specified index.
    MyObject& operator[](size_t index){ return _MyObjs[index]; }

    //Returns string representation of the vector.

    std::string ToString() const
    {
        // {1, 2, 3, 4, 5}
        // [1, 2, 3, 4, 5]

        std::stringstream ss;

        ss << "[";

        for (size_t i = 0; i < _size; ++i)
        {
            ss << _MyObjs[i]._id << ",";
        }

        ss << "]";

        return ss.str();
    }

    // Remove all MyObject instances with the given ID in this vector.
    void RemoveAll(int MyObjectId)
    {
        iterator iter = begin();

        while (iter != end())
        {
            if (iter->_id == MyObjectId)
            {
                iter = erase(iter);
            }
            else
            {
                ++iter;
            }
        }

    }

    // {1, 1, 2, 2, 3, 3, 4, 4}
    // {1, 1}
    // {2, 2}
    // {3, 3}
    // {4, 4}

    MyVector* GroupById(int* numGroups)
    {
        MyVector ids;
        for (size_t i = 0; i < _size; ++i)
        {
            if (nullptr == ids.FindById(_MyObjs[i]._id))
            {
                ids.Add(_MyObjs[i]._id);
            }
        }

        int count = ids.GetSize();
        MyVector* result = new MyVector[count];

        for (size_t i = 0; i < _size; ++i)
        {
            size_t index = ids.FindById(_MyObjs[i]._id) - ids.begin();
            result[index].Add(_MyObjs[i]._id);
        }

        *numGroups = count;
        return result;
    }
};
#include <iostream>
using namespace std;

template <typename T>
class MyVector
{
private:
    T *data;
    size_t capacity;
    size_t currSize;

public:
    MyVector() : data{nullptr}, capacity{0}, currSize{0}
    {
        cout << "Constructor with no args" << endl;
    }

    MyVector(std::initializer_list<T> initList) : data{nullptr}, capacity{0}, currSize{0}
    {
        cout << "Constructor for a vector with initialization" << endl;
        for (const auto &it : initList)
        {
            push_back(it);
        }
    }

    MyVector(const MyVector &otherVec) : currSize{otherVec.currSize}, capacity{otherVec.capacity}
    {
        cout << "copy constructor" << endl;
        T *newVec = new T[capacity];

        for (int i = 0; i < currSize; i++)
        {
            newVec[i] = otherVec[i];
        }

        if (data)
        {
            delete[] data;
        }

        data = newVec;
    }

    MyVector(MyVector &&otherVec) : currSize{otherVec.currSize}, capacity{otherVec.capacity}
    {
        cout << "move constructor" << endl;

        data = otherVec.data;
        otherVec.data = nullptr;
        otherVec.currSize = 0;
        otherVec.capacity = 0;
    }

    void push_back(T val)
    {
        if (currSize >= capacity)
        {
            cout << "push_back function : " << val << " : cap :" << capacity << endl;
            size_t newCap = (capacity == 0) ? 1 : 2 * capacity;
            reserve(newCap);
        }

        data[currSize++] = val;
    }

    void reserve(size_t newCapacity)
    {
        cout << "Reserve function" << endl;
        if (newCapacity <= capacity)
            return;

        T *newData = new T[newCapacity];

        for (auto i = 0; i < currSize; i++)
        {
            newData[i] = data[i];
        }

        if (data)
        {
            delete[] data;
        }

        data = newData;

        capacity = newCapacity;
    }

    T &operator[](size_t index)
    {
        cout << endl
             << "operator [] overloading function " << endl;
        return data[index];
    }

    const T &operator[](size_t index) const
    {
        cout << endl
             << "const operator [] overloading function " << data[index] << endl;
        return data[index];
    }

    MyVector &operator=(const MyVector &otherVec)
    {
        cout << "copy assignement operator" << endl;
        currSize = otherVec.currSize;
        capacity = otherVec.capacity;

        T *newVec = new T[capacity];

        for (int i = 0; i < currSize; i++)
        {
            newVec[i] = otherVec[i];
        }

        if (data)
        {
            delete[] data;
        }

        data = newVec;

        return *this;
    }

    MyVector &operator=(MyVector &&otherVec)
    {
        cout << "move assignement operator" << endl;
        currSize = otherVec.currSize;
        capacity = otherVec.capacity;

        data = otherVec.data;
        otherVec.data = nullptr;
        otherVec.currSize = 0;
        otherVec.capacity = 0;

        return *this;
    }

    size_t size()
    {
        cout << "size : " << currSize << endl;
        return currSize;
    }

    size_t size() const
    {
        cout << "size : " << currSize << endl;
        return currSize;
    }
};

int main()
{
    MyVector<int> vec; // constructor with no args

    vec.push_back(5); // push_back function

    cout << "vec[0] : " << vec[0] << endl; // operator [] overloading function

    vec[0] = 8;                                           // operator overloading function
    cout << "After updating vec[0] : " << vec[0] << endl; // operator overloading function

    const MyVector<int> constVec = {5, 6};           // constructor with arg initializer_list
    cout << "constVec[0] : " << constVec[0] << endl; // const operator [] overloading function

    constVec.size(); // const size function
    vec.size();      // size function

    MyVector<int> vec1 = vec; // copy constructor

    cout << "new vec vec1[0] : " << vec1[0] << " copied from vec[0] : " << vec[0] << endl;

    MyVector<int> vec2; // copy assignment operator
    vec2 = vec1;

    cout << "new vec vec2[0] : " << vec2[0] << " copied from vec1[0] : " << vec1[0] << endl;

    MyVector<int> vec3 = std::move(vec2); // move constructor

    cout << "new vec vec3[0] : " << vec3[0] << " moved from vec2[0]" << endl;

    MyVector<int> vec4;
    vec4 = std::move(vec3); // move assignement operator

    cout << "new vec vec4[0] : " << vec4[0] << " moved from vec3[0]" << endl;

    return 0;
}
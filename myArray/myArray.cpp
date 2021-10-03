#include "pch.h"
#include <iostream>
#include "MyArray.h"

using namespace std;

template<class T, size_t N>
MyArray<T, N>::MyArray() 
{
    //arr = new T[5];
}

template<class T, size_t N>
T& MyArray<T, N>::operator [] (int i)
{
    return (T&)arr[i];
}

template<class T, size_t N>
void MyArray<T, N>::Print()
{
    for (const auto v : arr)
    {
        cout << v << "'";
    }
    cout << endl;
}

template MyArray<double, 5>; template MyArray<string, 5>;



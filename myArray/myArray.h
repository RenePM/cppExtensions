#pragma once
// EXAMPLE OF EXPORTING A CLASS IMPLEMENTED IN A DLL
// DLL EXPORT/IMPORT Interface Define
#ifdef MYARRAY_EXPORTS
#   define MYARRAY_API    __declspec(dllexport)
#   define MYARRAY_FUNC   extern "C" __declspec(dllexport)
#   define MYARRAY_TEMPLATE
#else
#   define MYARRAY_API    __declspec(dllimport)
#   define MYARRAY_FUNC   extern "C" __declspec(dllimport)
#   define MYARRAY_TEMPLATE    extern
#endif

#ifndef MYARRAY_H
#	define MYARRAY_H 
template<class T, size_t N>
class MYARRAY_API MyArray
{
    T arr[N];
public:
    MyArray();
    void Print();
    T& operator[](int i);
};
#endif

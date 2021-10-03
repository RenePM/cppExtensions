#pragma once
// DLL EXPORT/IMPORT Define
#ifdef MYSTL_EXPORTS
#   define MYSTL_API    __declspec(dllexport)
#   define MYSTL_FUNC   extern "C" __declspec(dllexport)
#   define MYSTL_TEMPLATE
#else
#   define MYSTL_API    __declspec(dllimport)
#   define MYSTL_FUNC   extern "C" __declspec(dllimport)
#   define MYSTL_TEMPLATE    extern
#endif

#include <iostream>
#include <string>
#include <vector>

template<typename T>
struct MYSTL_API It
{
    std::vector<T>& vec_;
    int pointer_;

    It(std::vector<T>& vec) : vec_{ vec }, pointer_{ 0 } {}

    It(std::vector<T>& vec, int size) : vec_{ vec }, pointer_{ size } {}

    bool operator!=(const It<T>& other) const
    {
        return !(*this == other);
    }

    bool operator==(const It<T>& other) const
    {
        return pointer_ == other.pointer_;
    }

    It& operator++()
    {
        ++pointer_;
        return *this;
    }

    T& operator*() const
    {
        return vec_.at(pointer_);
    }
};

template<typename T>
struct MYSTL_API Vector
{
    std::vector<T> vec_;

    void push_back(T item)
    {
        vec_.push_back(item);
    };

    It<T> begin()
    {
        return It<T>(vec_);
    }

    It<T> end()
    {
        return It<T>(vec_, vec_.size());
    }
};

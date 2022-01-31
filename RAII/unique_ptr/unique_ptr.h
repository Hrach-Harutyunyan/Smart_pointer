#ifndef _IMPLEMENTATION_HPP
#define _IMPLEMENTATION_HPP

#include <iostream>

template <class T>
class unique_ptr
{
public:
    unique_ptr();
    ~unique_ptr();
    explicit unique_ptr(T*);
    unique_ptr(unique_ptr &&) noexcept;

public:
    T& operator *() const;
    T* operator ->() const;
    explicit operator bool() const;
    unique_ptr& operator = (unique_ptr&&) noexcept;

public:
    T* get();
    void reset();
    void release();
    void swap(unique_ptr&) noexcept;

private:
    unique_ptr(const unique_ptr &) = delete;
    unique_ptr & operator =(const unique_ptr &) = delete;

private:
    T* ptr;
};

#include "implementation.hpp"

#endif


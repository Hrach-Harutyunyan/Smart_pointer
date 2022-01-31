#ifndef _UNIQUE_PTR_H_
#define _UNIQUE_PTR_H_

#include "unique_ptr.h"

template <class T>
unique_ptr<T>::unique_ptr() : ptr(nullptr) {};


template <class T>
unique_ptr<T>::unique_ptr(T* pointer) : ptr(pointer) {} ;

template <class T>
unique_ptr<T>::unique_ptr(unique_ptr<T>&& rhs) noexcept : ptr(nullptr){
    rhs.swap(*this);
};

template <class T>
unique_ptr<T>& unique_ptr<T>::operator = (unique_ptr<T>&& rhs) noexcept {
    this->swap(rhs);
    delete rhs.ptr;
    rhs.ptr = nullptr;
    return *this;
};

template <class T>
unique_ptr<T>::~unique_ptr() {
    if(!ptr){
        delete ptr;
    }
};

template <class T>
T& unique_ptr<T>::operator *() const {
    return *ptr;
};

template <class T>
T* unique_ptr<T>::operator ->() const {
    return ptr;
};

template <class T>
unique_ptr<T>::operator bool()  const  {
    return (ptr == nullptr? false:true);
};


template <class T>
void unique_ptr<T>::swap(unique_ptr<T>& other) noexcept {
    std::swap(ptr, other.ptr);
}

template <class T>
T* unique_ptr<T>::get() {
    return ptr;
}

template <class T>
void unique_ptr<T>::reset(){
    delete this->ptr;
    this->ptr = nullptr;
}

template <class T>
void unique_ptr<T>::release(){
    this->ptr = nullptr;
}

#endif
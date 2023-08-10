#ifndef DYNAMICARRAY_HPP

#define DYNAMICARRAY_HPP
#define __DEFAULT_INCREASE__ 2

#include "macros.hpp"

template <typename T> class DynamicArray {
private:
  T *__array;
  size_t __len;
  size_t __used;

public:
  size_t size();
  size_t capacity();
  void reserve(size_t);
  const T &operator[](size_t) const;
  T &operator[](size_t);
  void push_back(T);
  void pop();
  DynamicArray();
  DynamicArray(size_t);
  ~DynamicArray();
};

template <typename T> inline size_t DynamicArray<T>::size() { return __used; }

template <typename T> inline size_t DynamicArray<T>::capacity() {
  return __len;
}

template <typename T> inline void DynamicArray<T>::reserve(size_t capacity) {
  if (capacity < __len)
    return;

  __len = capacity;
  T *__new_array = new T[__len];
  size_t i;
  FROM0TO(i, __used) { __new_array[i] = __array[i]; }
  delete[] __array;
  __array = __new_array;
}

template <typename T> inline T &DynamicArray<T>::operator[](size_t i) {
  return __array[i];
}

template <typename T>
inline const T &DynamicArray<T>::operator[](size_t i) const {
  return __array[i];
}

template <typename T> inline void DynamicArray<T>::push_back(T value) {
  if (__array == nullptr) {
    __len = 1;
    __used = 1;
    __array = new T[__len];
    __array[0] = value;
    return;
  }

  if (__len == __used)
    reserve(__DEFAULT_INCREASE__ * __len);

  __array[__used++] = value;
}

template <typename T> inline void DynamicArray<T>::pop() { --__used; }

template <typename T> inline DynamicArray<T>::DynamicArray() {
  __len = 0;
  __used = 0;
  __array = nullptr;
}

template <typename T> inline DynamicArray<T>::DynamicArray(size_t len) {
  __len = len;
  __used = 0;
  __array = new T[len];
}

template <typename T> inline DynamicArray<T>::~DynamicArray() {
  delete[] __array;
}
#endif

/**
 * 
 * This code is based on the following pages:
 *  - https://www.cs.odu.edu/~zeil/cs361/latest/Public/vectorImpl/index.html
 *  - https://www.geeksforgeeks.org/how-to-implement-our-own-vector-class-in-c/
 * 
 */
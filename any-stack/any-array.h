// any-array.h - generic array class that can grow and shrink
// Copyright 2026 Humberto Ortiz Zuazaga
// Based on array class by Pat Morin
// in https://opendatastructures.org/
// Released under
// https://creativecommons.org/licenses/by/2.5/ca/

#ifndef ARRAY_H
#define ARRAY_H

template<class T>
class array {
protected:
  T *a;
public:
  int length;

  array(int len) {
    length = len;
    a = new T[length];
  }

  ~array() {
    if (a != NULL) delete[] a;
  }
  
  T& operator[](int i) {
    return a[i];
  }

  array<T>& operator=(array<T> &b) {
    if (a != NULL) delete[] a;
    a = b.a;
    b.a = NULL;
    length = b.length;
    return *this;
  }
};

#endif

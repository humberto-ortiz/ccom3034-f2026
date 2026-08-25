// array.h - integer array class that can grow and shrink
// Copyright 2026 Humberto Ortiz Zuazaga
// Based on array class by Pat Morin
// in https://opendatastructures.org/
// Released under
// https://creativecommons.org/licenses/by/2.5/ca/

class array {
protected:
  int *a;
public:
  int length;

  array(int len) {
    length = len;
    a = new int[length];
  }

  ~array() {
    if (a != NULL) delete[] a;
  }

  int& operator[](int i) {
    return a[i];
  }

  array& operator=(array &b) {
    if (a != NULL) delete[] a;
    a = b.a;
    b.a = NULL;
    length = b.length;
    return *this;
  }
};


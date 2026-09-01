// any-stack.h - generic stack class that can grow and shrink
// Copyright 2026 Humberto Ortiz Zuazaga
// Based on array.h and ArrayStack.h by Pat Morin
// https://opendatastructures.org/
// Released under
// https://creativecommons.org/licenses/by/2.5/ca/

#ifndef ANY_STACK_H
#define ANY_STACK_H

#include "any-array.h"

template<class T>
class anystack {
 private:
  array<T> a;
  int n; // index of next available element

 public:

  anystack() : a(1) {
    // Construct an empty stack of size 1
    n = 0;
  }

  ~anystack() {
    // if (a == NULL) return;
  }
  
  void push(T x) {
    // check if full
    if (n + 1 > a.length) resize();
    // put x in next empty slot and advance the index
    a[n++] = x;
  }

  T pop() {
    if (n > 0) { // stack not empty
      // store the last element and set the index
      T x = a[--n];
      // check if too much space is wasted
      if (a.length > 3 * n) resize();
      return x;
    } else {
      // popping an empty stack raises an error
      throw std::runtime_error("El stack esta vacio");
    }
  }

  void resize() {
    array<T> b(std::max(2 * n, 1));
    for (int i = 0; i < n; i++)
      b[i] = a[i];		// copia los elementos al nuevo array
    a = b;
  }
};

#endif

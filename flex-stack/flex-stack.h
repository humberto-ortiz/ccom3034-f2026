// flexstack.h - integer stack class that can grow and shrink
// Copyright 2026 Humberto Ortiz Zuazaga
// Based on array.h and ArrayStack.h by Pat Morin
// https://opendatastructures.org/
// Released under
// https://creativecommons.org/licenses/by/2.5/ca/

#include "array.h"

class flexstack {
 private:
  array a;
  int n; // index of next available element

 public:

  flexstack() : a(1) {
    // Construct an empty stack of size 1
    n = 0;
  }

  void push(int x) {
    // check if full
    if (n == a.length) resize();
    // put x in next empty slot and advance the index
    a[n++] = x;
  }

  int pop() {
    if (n > 0) { // stack not empty
      // return the last element and set the index
      int x = a[--n];
      // check if too much space is wasted
      if (a.length > 3 * n) resize();
      return x;
    } else {
      // popping an empty stack raises an error
      throw std::runtime_error("El stack esta vacio");
    }
  }

  void resize() {
    throw std::runtime_error("No se hacer resize todavia.");
  }
};

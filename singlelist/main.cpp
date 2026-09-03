// main.cpp test singly linked list stacks
// Copyright 2026 Humberto Ortiz Zuazaga
// Released under
// https://creativecommons.org/licenses/by/4.0/deed.en

#include <iostream>
#include "sllist.h"

int main() {
  SLList<int> l;

  l.push(29);
  l.push(37);
  std::cout << l.pop() << std::endl;
  return 0;
}

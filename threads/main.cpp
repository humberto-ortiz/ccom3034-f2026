// main.cpp test singly linked list stacks
// Copyright 2026 Humberto Ortiz Zuazaga
// Released under
// https://creativecommons.org/licenses/by/4.0/deed.en

#include <iostream>
#include "sllist.h"

#define STACK_OPS 10

using namespace std;

SLList<int> l;

void push_task() {
  
  for (int i = 0; i < STACK_OPS; i++) {
    l.push(i);
  }
}

void pop_task() {
  for (int i = 0; i < STACK_OPS; i++) {
    std::cout << l.pop() << std::endl;
  }
}

int main() {

  push_task();
  pop_task();
  
  return 0;
}

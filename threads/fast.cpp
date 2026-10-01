// fast.cpp threaded test singly linked list stacks
// Copyright 2026 Humberto Ortiz Zuazaga
// Released under
// https://creativecommons.org/licenses/by/4.0/deed.en

#include <iostream>
#include <thread>
#include "sllist.h"

#define STACK_OPS 100

SLList<int> l;

void push_task() {
  for (int i = 0; i < STACK_OPS; i++) {
    std::cout << "Push " << i << std::endl;
    l.push(i);
  }
}

void pop_task() {
  for (int i = 0; i < STACK_OPS; i++) {
    std::cout << "Pop " << l.pop() << std::endl;
  }
}

int main() {

  std::thread t1(push_task);
  std::thread t2(pop_task);

  t1.detach();
  t2.join();
  
  return 0;
}

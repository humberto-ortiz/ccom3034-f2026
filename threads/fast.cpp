// fast.cpp threaded test singly linked list stacks
// Copyright 2026 Humberto Ortiz Zuazaga
// Released under
// https://creativecommons.org/licenses/by/4.0/deed.en

#include <iostream>
#include <thread>
#include "sllist.h"

#define STACK_OPS 100		// how many entries to push and pop

SLList<int> l;			// a global list, both threads will use this same list

void push_task() {
  for (int i = 0; i < STACK_OPS; i++) {
    std::cout << "Push " << i << std::endl;
    l.push(i);
  }
}

void pop_task() {
  int value;
  for (int i = 0; i < STACK_OPS; i++) {
    value = l.pop();
    std::cout << "Pop " << value << std::endl;
  }
}

int main() {

  std::thread t1(push_task);	// make a thread to push
  std::thread t2(pop_task);	// make a thread to pop

  t1.detach();			// start the push thread and don't wait
  t2.join();			// start the pop thread, and wait for it to finish
  
  return 0;
}

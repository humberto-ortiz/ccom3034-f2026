# Threading and singly linked lists

## Introduction

In class we developed a singly linked list data structure, and used it
to implement stacks and queues. This lab will work through some tests
of our stacks and how they interact with C++ threads. We will see that
our stacks are not safe to use with threads, and work on fixing them.

## Non-threaded code

Here's an example program that has two functions, one that puts things on a stack, and another that takes them off:

```c++
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
```

This code works, but is *single-threaded*, and cannot take advantage
of multiple CPUs on modern computers. We can compile and run the tests with:

```
$ make main
$ ./main 
9
8
7
6
5
4
3
2
1
0
```

## Splitting into multiple threads.

To speed up the program, we can run in multiple threads:
```c++
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
```

However, when we do this, the program starts to crash:
```
$ make fast
$ ./fast
...
Push 57
  what():  Push 58
El stack esta vacioPush 59

Push 60
Push 61
Push 62
Push 63
Push 64
Push 65
Push 66
Push 67
Push 68
Push 69
Aborted (core dumped)
```

We can wait before popping, by adding a loop in pop_task():
```c++
void pop_task() {
  int value;
  for (int i = 0; i < STACK_OPS; i++) {
	while (l.is_empty()) ; // espera
    value = l.pop();
    std::cout << "Pop " << value << std::endl;
  }
}
```
This seems to have fixed our problem.
```
$ make fast
$ ./fast
...
Pop 98
Pop 97
Pop 96
Pop 95
Pop 94
Pop 93
Pop 92
Pop 91
Pop 90
Pop 89
```
But if you re-run fast a few times, you may start to see errors:
```
Push 18
Push Pop 1677316257
19
Pop Push 19
20
Pop Push 20
21
Pop Push 21
22
Push Pop 22
23
Push Pop 1677316065
24
Segmentation fault
```

Comment out the output statements in `push_task()` and `pop_task()`,
and make the `STACK_OPS` a larger value, like 1000. The program should
reliably crash.

```
$ make fast
$ ./fast 
free(): double free detected in tcache 2
Aborted                    ./fast
```

## Mutex

The real problem with our stack class is that it is performing complex
operations on pointers in both `push()` and `pop()` methods. If we are
performing these complex operations in different threads, there is a
risk of one operation interfering with another, as we discussed in
class.

The ususal solution to this kind of problem is to use `mutex`es. A
mutex (short for mutually exclusive) is a data structure that ensures
only one thread can operate at a time. In C++ mutexes provide `lock()`
and `unlock()` methods, and we can use them to control access to the stack.

In the `sllist.h` file add

```
#include <mutex>
```
near the top, then add a mutex to the `SLList` class:
```
  Node* head;
  Node* tail;
  std::mutex mtx; // add a mutex to the class
```

Then methods can use `mtx.lock()` to lock the mutex, and
`mtx.unlock()` to release the lock, and allow other methods to run.

However, this pattern is fragile, and some programmers forget to
unlock, or the program may exit a method because of an exeption, and
not release the lock.

For this reason, the mutex package provides another tool, the `lock_guard`. Each method that must operate on the stack can call
```
std::lock_guard<std::mutex> guard(mtx);
```
on the mutex, and the compiler will ensure the lock is obtained before running subsequent operations, and the lock is released when the function exits.

## Assignment.

Fix the `sllist.h` so that every method locks the mutex. With this
fix, the `fast` program should no longer crash, even if you run it
multiple times, or make `STACK_OPS` even larger.

// sllist.h - singly linked list class
// Copyright 2026 Humberto Ortiz Zuazaga
// Based on SLList class by Pat Morin
// in https://opendatastructures.org/
// Released under
// https://creativecommons.org/licenses/by/2.5/ca/

#ifndef SLLIST_H
#define SLLIST_H

template<class T>
class SLList {
  class Node {
  public:
    T value;
    Node *next;

    Node(T x) {
      value = x;
      next = nullptr;
    }
  };
  Node* head;

 public:

  // Constructor
  SLList() {
    head = nullptr;
  }

  ~SLList () {
    Node *u = head;
    while (u != nullptr) {
      Node *w = u;
      u = u->next;
      delete w;
    }
    head = nullptr;
  }

  void push(T x) {
    Node *u = new Node(x);
    u->next = head;
    head = u;
  }

  T pop() {
    Node *u = head;
    T x = u->value;
    head = u->next;
    delete u;
    return x;
  }
};

#endif

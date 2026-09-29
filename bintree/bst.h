// bst.h - clase para binary *search* trees
// Copyright 2026 Humberto Ortiz Zuazaga
// Based on BinarySearchTree class by Pat Morin
// in https://opendatastructures.org/
// Released under
// https://creativecommons.org/licenses/by/2.5/ca/

#include "bintree.h"

template<class T>
int compare(T x, T y) {
  if (x > y) return 1;
  if (x < y) return -1;
  return 0;
}

template<class Node, class T>
  class BSTNode : public BTNode<Node> {
 public:
  T value;
};

template<class Node, class T>
  class BinarySearchTree : public BinaryTree<Node> {
 public:
  using BinaryTree<Node>::root;

  BinarySearchTree() {}

  bool add(T x) {
    Node *p = findLast(x);
    Node *u = new Node;
    u->value = x;
    return addChild(p, u);
  }

  Node *findLast(T x) {
    Node *w = root, *prev = nullptr;
    while (nullptr != w) {
      prev = w;
      int comp = compare(x, w->value);
      if (comp > 0) {
	w = w->right;
      } else if (comp < 0) {
	w = w->left;
      } else {
	return w;
      }
    }
    return prev;
  }

  bool addChild(Node *p, Node *u) {
    if (p == nullptr) {
      root = u;
    } else {
      int comp = compare(u->value, p->value);
      if (comp < 0) {
	p->left = u;
      } else if (comp > 0) {
	p->right = u;
      } else {
	return false;
      }
    }
    return true;
  }
};

template<class T>
class BSTNode1 : public BSTNode<BSTNode1<T>, T> {};


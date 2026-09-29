// bintree.h - clases para arboles binarios

// Copyright 2026 Humberto Ortiz Zuazaga
// Based on BinaryTree class by Pat Morin
// in https://opendatastructures.org/
// Released under
// https://creativecommons.org/licenses/by/2.5/ca/

template<class Node>
class BTNode {
 public:
  Node *left;
  Node *right;
  Node *parent;
  
  BTNode() {
    left = right = parent = nullptr;
  }
};

template<class Node>
class BinaryTree {
 public:
  Node *root;

  BinaryTree() {
    root = nullptr;
  }

  ~BinaryTree() {
    clear(root);
  }

  void clear(Node *u) {
    if (nullptr == u) return;
    clear(u->left);
    clear(u->right);
    delete(u);
    return;
  }

  int size() {
    return size(root);
  }

  int size(Node *u) {
    if (nullptr == u) return 0;
    int suma = 1;
    suma += size(u->left);
    suma += size(u->right);
    return suma;
  }

  int size2() {
    // size sin recursion
    Node *prev = nullptr;
    Node *u = root;
    Node *next;
    int tamaño = 0;

    while (nullptr != u) {
      if (prev == u->parent) {
	tamaño++;
	if (u->left != nullptr) 
	  next = u->left;
	else if (u->right != nullptr)
	  next = u->right;
	else next = u->parent;
      } else if (prev == u->left) {
	if (u->right != nullptr) 
	  next = u->right;
	else
	  next = u->parent;
      } else {
	next = u->parent;
      }
      prev = u;
      u = next;
    }
    return tamaño;
  }
    
  // see stubs in height.cpp
  int height();
  int height(Node *);
  
};

class BTNode1 : public BTNode<BTNode1> { };

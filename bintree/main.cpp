// main.cpp - tests empty binary trees (no data)
// Copyright 2026 Humberto Ortiz Zuazaga
// Based on BinaryTree class by Pat Morin
// in https://opendatastructures.org/
// Released under
// https://creativecommons.org/licenses/by/2.5/ca/

#include <iostream>
#include "bintree.h"

int main() {
  BinaryTree<BTNode1> arbol;

  arbol.root = new BTNode1();
  arbol.root->right = new BTNode1();
  arbol.root->right->parent = arbol.root;
  arbol.root->right->right = new BTNode1();
  arbol.root->right->right->parent = arbol.root->right;
  arbol.root->right->right->right = new BTNode1();
  arbol.root->right->right->right->parent = arbol.root->right->right;

  std::cout << arbol.size2() << std::endl;
  return 0;
}

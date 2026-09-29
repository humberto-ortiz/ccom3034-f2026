#include <iostream>

#include "bst.h"

int main() {
  BinarySearchTree<BSTNode1<int>, int> bstree;

  bstree.add(3);
  bstree.add(2);
  bstree.add(6);

  std::cout << bstree.root->value << std::endl;
  return 0;
}

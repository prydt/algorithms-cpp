
#include <iostream>
#include <random>
#include <cstdlib>

#include "BST.h"


int main()
{
  BinarySearchTree<int> bst;

  std::mt19937 rng;
  rng.seed(time(NULL));

  for(int i = 0; i < 10; i++)
    bst.insert(rng() % 1000);

  std::cout << "Smallest: " << bst.findMin() << '\n';
  bst.printTree();

  std::cout << "-----------------\n";

  intBST rbst;

  int keys[10] = {1, 3, 5, 0, 7, 2, 6, 4, 9, 8};

  for(int i = 0; i < 10; i++)
    rbst.insert(keys[i]);

  std::cout << "Before:\t";
  rbst.printTree();


  rbst.remove(0);
  rbst.remove(1);

  std::cout << "After:\t";
  rbst.printTree();

  return 0;
}

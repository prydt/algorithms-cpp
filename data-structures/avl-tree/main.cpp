
#include "AVL.h"
#include <iostream>
#include <random>
#include <ctime>

int main()
{
  /*
  AVLTree<int> avl;

  int test[10] = {4, 1, 2, 7, 9, 3, 0, 5, 8, 6};

  for(int i = 0;i<10;i++)
    avl.insert(test[i]);

  avl.printTree();
  */

  AVLTree<int> avl;

  std::mt19937 rng;
  rng.seed(time(0));

  for(int i = 0; i < 10; i++)
  {
    int a = rng() % 300;

    avl.insert(a);
  }

  avl.printTree();
  return 0;
}

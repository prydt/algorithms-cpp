#include <iostream>
#include "Heap.h"

int main() {
  Heap heap;

  for (int i = 10; i >= 0; i--) heap.insert(i);

  heap.print();

  // testing the extractMin function
  for (int i = 0; i < 10; i++)
    std::cout << "index: " << i << " Value: " << heap.extractMin() << '\n';

  return 0;
}

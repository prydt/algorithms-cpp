#include "Heap.h"
#include <iostream>

Heap::Heap() {}

int Heap::peek() { return items.at(0); }

int Heap::extractMin() {
  int out = items.at(0);
  items[0] = items.at(items.size() - 1);

  items.pop_back();

  heapifyDown();
  return out;
}

void Heap::insert(int item) {
  items.push_back(item);
  heapifyUp();
}

void Heap::heapifyUp() {
  // sets index to last node
  int index = items.size() - 1;

  // repeats while the node has a parent
  // and is out of order
  while (hasParent(index) && parent(index) > items.at(index)) {
    swap(getParentIndex(index), index);
    index = getParentIndex(index);
  }
}

void Heap::heapifyDown() {
  // start at root
  int index = 0;

  while (hasLeftChild(index)) {
    int smallIndex = getLeftChildIndex(index);
    if (hasRightChild(index) && rightChild(index) < leftChild(index)) {
      smallIndex = getRightChildIndex(index);
    }

    if (items.at(index) < items[smallIndex]) {
      break;
    } else {
      swap(index, smallIndex);
    }

    index = smallIndex;
  }
}

void Heap::print() {
  std::cout << "[ ";
  for (int i = 0; i < (int)items.size(); i++) std::cout << ' ' << items.at(i);
  std::cout << " ]\n";
}


#ifndef HEAP_H
#define HEAP_H

#include <vector>

// a min-heap immplementation
class Heap {
 public:
  // constructor
  Heap();

  // finding the min in the heap
  int peek();

  // inserting an item into the heap
  void insert(int);

  // removes min and returns it
  int extractMin();

  // prints out internal vector in heap
  void print();

 private:
  // the actual container for the heap
  std::vector<int> items;

  // helper functions
  inline int getLeftChildIndex(int parentIndex) { return 2 * parentIndex + 1; }
  inline int getRightChildIndex(int parentIndex) { return 2 * parentIndex + 2; }
  inline int getParentIndex(int childIndex) { return (childIndex - 1) / 2; }

  inline bool hasLeftChild(int index) {
    return getLeftChildIndex(index) < (int)items.size();
  }
  inline bool hasRightChild(int index) {
    return getRightChildIndex(index) < (int)items.size();
  }
  inline bool hasParent(int index) { return getParentIndex(index) >= 0; }

  inline int leftChild(int index) { return items.at(getLeftChildIndex(index)); }
  inline int rightChild(int index) {
    return items.at(getRightChildIndex(index));
  }
  inline int parent(int index) { return items.at(getParentIndex(index)); }

  void swap(int indexOne, int indexTwo) {
    int temp = items.at(indexOne);
    items[indexOne] = items[indexTwo];
    items[indexTwo] = temp;
  }

  // internals of the Heap structure
  void heapifyUp();
  void heapifyDown();
};

#endif

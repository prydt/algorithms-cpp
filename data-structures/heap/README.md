# Heap
An array visualized as a nearly complete binary tree

## Heap as a tree
Root of tree = 1
Parent of N = N / 2
Left child of N = 2N

## What is the Min-Heap Property?
The key of a node is less than or equal to the keys of its children.

## What is the Max-Heap Property?
The opposite of the Min-Heap Property.

## Heap Operations
 - insert - insert item into heap
 - remove - remove item from heap
 - buildMinHeap: make a Min-Heap from an array (Constructor)
 - minHeapify: correct a single violation of the Heap property in a subtree's root

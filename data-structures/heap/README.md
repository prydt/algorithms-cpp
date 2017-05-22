# Heap
An array visualized as a nearly complete binary tree

## Heap as a tree
Root of tree = 1
Parent of N = N / 2
Left child of N = 2N

## What is the Max-Heap Property?
The key of a node is greater than or equal to the keys of its children.

## What is the Min-Heap Property?
The opposite of the Max-Heap Property.

## Heap Operations
 - buildMaxHeap: make a Max-Heap from an array (Constructor)
 - maxHeapify: correct a single violation of the Heap property in a subtree's root


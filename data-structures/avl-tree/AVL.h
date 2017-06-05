
#ifndef AVL_H
#define AVL_H

#include <iostream>

template <class T>  // T = key
class AVLTree {
 public:
  // constructor / destructor
  AVLTree() : root(nullptr) {}
  ~AVLTree() { destroy(root); }

  // insert node w/ key
  void insert(T key) { insert(key, root); }

  // remove node w/ key
  void remove(T key);

  // min / max
  T findMin() { return findMin(root); }
  T findMax() { return findMax(root); }

  // successor / pred.
  T successor(T key);
  T pred(T key);

  // print out AVL in order
  void printTree()
  {
    std::cout << "[ ";
    print(root);
    std::cout << "]\n";
  }

 private:
  // tree node
  struct Node {
    // data being stored
    T key;

    // association pointers
    Node *left;
    Node *right;
    Node *parent;

    Node(T data, Node *par)
    {
      key = data;

      left = nullptr;
      right = nullptr;
      parent = par;
    }
  };

  void destroy(Node *node)
  {
    if (node == nullptr) return;

    destroy(node->left);
    destroy(node->right);

    delete node;
  }

  T findMin(Node *node)
  {
    if (node->left != nullptr)
      return findMin(node->left);
    else
      return node->key;
  }

  T findMax(Node *node)
  {
    if (node->right != nullptr)
      return findMin(node->right);
    else
      return node->key;
  }

  void print(Node *node)
  {
    if (node == nullptr) return;

    if (node->left != nullptr) print(node->left);

    std::cout << node->key << ' ';

    if (node->right != nullptr) print(node->right);
  }

  // returns height of node n
  int height(Node *n)
  {
    if (n == nullptr) return -1;
    return 1 + ((height(n->left) > height(n->right)) ? height(n->left)
                                                     : height(n->right));
  }

  // returns the balance factor of node n
  int diff(Node *n) { return (height(n->right) - height(n->left)); }

  // rotations
  Node *RRRotation(Node *node)
  {
    Node *n = node->right;
    node->right = n->left;
    n->left = node;

    return n;
  }

  Node *LLRotation(Node *node)
  {
    Node *n = node->left;
    node->left = n->right;
    n->right = node;

    return n;
  }

  Node *LRRotation(Node *node)
  {
    Node *n = node->left;
    node->left = RRRotation(n);
    return LLRotation(node);
  }

  Node *RLRotation(Node *node)
  {
    Node *temp = node->right;
    node->right = LLRotation(temp);
    return RRRotation(node);
  }

  void balanceTree(Node *ptr)
  {
    if(ptr == nullptr) return;

    if (diff(ptr) > 1) {
      if (diff(ptr->left) > 0) {
        ptr = LLRotation(ptr);
      }
      else {
        ptr = LRRotation(ptr);
      }
    }
    else if (diff(ptr) < -1) {
      if (diff(ptr->right) > 0) {
        ptr = RLRotation(ptr);
      }
      else {
        ptr = RRRotation(ptr);
      }
    }
  }

  void insert(T key, Node *node)
  {
    if (root == nullptr) {
      root = new Node(key, nullptr);
    }
    else {
      if (key > node->key) {
        if (node->right != nullptr)
          insert(key, node->right);
        else {
          node->right = new Node(key, node);
          balanceTree(node->right);
        }
      }
      else if (key < node->key) {
        if (node->left != nullptr)
          insert(key, node->left);
        else {
          node->left = new Node(key, node);
          balanceTree(node->left);
        }
      }
      else
        std::cout
            << "AVL.h: insert() failed, attempted to insert duplicate key\n";
    }
  }

  // root of tree
  Node *root;
};

#endif

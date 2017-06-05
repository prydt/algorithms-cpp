
#ifndef BST_H
#define BST_H

#include <cstdlib>
#include <iostream>

template <class T>
class BinarySearchTree {
 public:
  // constructor
  BinarySearchTree() { root = NULL; }
  ~BinarySearchTree()
  {
    destroy(root);
  }

  // insert
  void insert(T data) { insert(data, root); }

  // find min
  int findMin() { return findMin(root); }

  // remove node
  void remove(T data) { remove(data, root); }


  // check if a number is in tree
  bool find(T data)
  {
    return find(data, root);
  }

  // print tree in order out to stdout
  void printTree()
  {
    std::cout << "[ ";
    print(root);
    std::cout << " ]\n";
  }

  // prints tree in ascii "graphics"
  void displayTree()
  {
    displayTree(root, 0);
  }

 private:
  // basic building block of tree
  struct Node {
    T key;  // value of node

    Node *left;   // smaller
    Node *right;  // greater
  };

  void destroy(Node *n)
  {
    if(n == NULL)
      return;

    destroy(n->left);
    destroy(n->right);

    delete n;
  }

  // helper function print
  void print(Node *ptr)
  {
    if (root != NULL) {
      if (ptr->left != NULL) {
        print(ptr->left);
      }
      std::cout << ptr->key << " ";

      if (ptr->right != NULL) {
        print(ptr->right);
      }
    }
    else {
      std::cout << "Binary Search Tree is empty\n";
    }
  }

  // internals for find function
  bool find(T data, Node *n)
  {
    if(data == n->key)
      return true;

    if(data > n->key && n->right != NULL)
      return find(data, n->right);

    if(data < n->key && n->left != NULL)
      return find(data, n->left);

    return false;
  }

  // internals for display tree function
  void displayTree(Node *node, int ind)
  {
    if(node == NULL) return;

    std::cout << '\n';

    displayTree(node->right, ind + 1);

    for(int i = 0; i < ind; i++)
    {
      std::cout << " ";
    }

    std::cout << '[' << node->key << "]\n";

    displayTree(node->left, ind + 1);
  }

  // find min
  int findMin(Node *ptr)
  {
    if (root == NULL) {
      std::cout << "findMin(): BST is empty\n";
      return -324243;
    }
    else {
      if (ptr->left != NULL) {
        return findMin(ptr->left);
      }
      else {
        return ptr->key;
      }
    }
  }

  // make a new node
  Node *createLeaf(T data)
  {
    Node *n = new Node();
    n->key = data;

    n->left = NULL;
    n->right = NULL;

    return n;
  }

  void insert(T data, Node *ptr)
  {
    if (root == NULL) {
      root = createLeaf(data);
      return;
    }
    else if (data < ptr->key) {
      if (ptr->left != NULL)
        insert(data, ptr->left);
      else {
        ptr->left = createLeaf(data);
        return;
      }
    }
    else if (data > ptr->key) {
      if (ptr->right != NULL)
        insert(data, ptr->right);
      else {
        ptr->right = createLeaf(data);
        return;
      }
    }
    else {
      std::cout << "Attempted to add duplicate key in BST\n";
    }
  }

  // remove match
  void removeMatch(Node *parent, Node *match, bool left)
  {
    if (root != NULL) {
      Node *delptr;
      int small;

      // case A: 0 children
      if (match->left == NULL && match->right == NULL) {
        delptr = match;

        left ? parent->left = NULL : parent->right = NULL;

        delete delptr;
      }

      // case B: 1 child
      else if ((match->left == NULL) != (match->right == NULL)) {
        (left) ? ((match->right != NULL) ? parent->left = parent->right : parent->left = parent->left)
          : (match->right != NULL ? parent->right = match->right : parent->right = match->left);

        (match->right != NULL) ? match->right = NULL : match->left = NULL;

        delptr = match;

        delete delptr;
      }

      // case C: 2 children
      else
      {
        small = findMin(match->right);
        remove(small, match);
        match->key = small;
      }

    }
    else {
      std::cout << "removeMatch(): cannot remove match, BST empty\n";
    }
  }

  // removes root of tree (used in special cases)
  void removeRootMatch()
  {
    if (root == NULL) {
      std::cout << "removeRootMatch(): BST is empty\n";
      return;
    }

    Node *delptr = root;
    int small;

    // case A: 0 children
    if (root->left == NULL && root->right == NULL) {
      root = NULL;
      delete delptr;
    }

    // case B: 1 child
    else if ((root->left == NULL) != (root->right == NULL)) {
      root = (root->left != NULL) ? root->left : root->right;

      (root->right != NULL) ? delptr->right = NULL : delptr->left = NULL;
      delete delptr;
    }

    // case C: 2 children

    else {
      small = findMin(root->right);
      remove(small, root);

      root->key = small;
    }
  }

  void remove(T data, Node *parent)
  {
    if (root == NULL) {
      std::cout << "remove(): FAILED, BST is empty\n";
    }
    else {
      if (root->key == data) {
        removeRootMatch();
      }
      else {
        if (data < parent->key && parent->left != NULL) {
          parent->left->key == data ? removeMatch(parent, parent->left, true)
                                    : remove(data, parent->left);
        }
        else if (data > parent->key && parent->right != NULL) {
          parent->right->key == data ? removeMatch(parent, parent->right, false)
                                     : remove(data, parent->right);
        }
        else {
          std::cout << "remove(): The key(" << data
                    << ") was not found in BST\n";
        }
      }
    }
  }

  // root of the tree
  Node *root;
};

// typedef for convenience
typedef BinarySearchTree<int> intBST;

#endif

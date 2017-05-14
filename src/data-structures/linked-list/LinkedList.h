
#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>

/*
 * A Linked List Class (Without templates for sake of simplicity)
 *
 */
class LinkedList
{
  public:
    // constructor
    LinkedList();

    // returns length of list
    int length();

    // adds node to head
    void push(int);

    // adds nodes to tail
    void append(int);

    // removes from head
    int remove();

    // removes Nth item
    int remove(int);

    // prints out list
    void print();

  private:
    // building block of the list...
    // the list is just a bunch of nodes
    struct Node
    {
      int data;
      Node* next;
    };
    
    // head pointer of the list
    Node* head;
};
#endif

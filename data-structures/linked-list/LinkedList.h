
#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>

/*
 * A Linked List Class (Now w/ Templates!)
 *
 */
template <class T>
class LinkedList
{
  public:
    // constructor
    LinkedList()
    {
      Node* ptr = new Node();
      ptr->next = nullptr;
      head = ptr;
    }

    // returns length of list
    int length()
    {
      Node* tmp = head;
      int count = 0;

      while(tmp->next != nullptr)
      {
        tmp = tmp->next;
        count++;
      }

      return count;
    }

    // adds node to head
    void push(T val)
    {
      Node* newNode = new Node();
      newNode->data = val;
      newNode->next = head;
      head = newNode;
    }

    // adds nodes to tail
    void append(T val)
    {
      Node* current = head;
      Node* newNode = new Node();

      newNode->data = val;
      newNode->next = nullptr;

      if(current == nullptr)
        head = newNode;
      else
      {
        while(current->next != nullptr)
          current = current->next;

        current->next = newNode;
      }
    }

    // removes from head
    T removeHead()
    {
      int out = head->data;
      head = head->next; // simply sets head to the next node in the list

      return out;
    }

    // removes last item
    T removeTail()
    {
      Node* tmp = head;
      int out;

      while(tmp->next->next != nullptr)
        tmp = tmp->next;

      out = tmp->next->data;
      tmp->next = nullptr;

      return out;
    }

    // prints out list
    void print()
    {
      Node* tmp = head;
      std::cout << "[ ";
      while(tmp->next != nullptr)
      {
        std::cout << tmp->data << ' ';
        tmp = tmp->next;
      }
      std::cout << "]\n";
    }

    // gets items in at the specified index
    T& operator[](std::size_t index)
    {
      Node* tmp = head;   // temp variable to store the head pointer
      int i = 0;          // iterator

      while( tmp->next != nullptr && i < (int) index )
      {
        tmp = tmp->next;
        i++;
      }

      return tmp->data;

    }


  private:
    // building block of the list...
    // the list is just a bunch of nodes
    struct Node
    {
      T data;
      Node* next;
    };

    // head pointer of the list
    Node* head;
};
#endif

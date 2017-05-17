
#include "LinkedList.h"

LinkedList::LinkedList()
{
  Node* ptr = new Node();
  ptr->next = nullptr;
  head = ptr;
}

int LinkedList::length()
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

void LinkedList::push( int val )
{
  Node* newNode = new Node();
  newNode->data = val;
  newNode->next = head;
  head = newNode;
}

void LinkedList::append( int val )
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

int LinkedList::removeHead()
{
  int out = head->data;
  head = head->next; // simply sets head to the next node in the list

  return out;
}

int LinkedList::removeTail()
{
  Node* tmp = head;
  int out;

  while(tmp->next->next != nullptr)
    tmp = tmp->next;
  
  out = tmp->next->data;
  tmp->next = nullptr;

  return out;
}

void LinkedList::print()
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

int& LinkedList::operator[]( std::size_t index )
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

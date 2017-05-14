
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

void LinkedList::push(int val)
{
  Node* newNode = new Node();
  newNode->data = val;
  newNode->next = head;
  head = newNode;
}

void LinkedList::append(int val)
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

int LinkedList::remove()
{
  head = head->next;
}

int LinkedList::remove(int index)
{
  Node* tmp = head;
  while(tmp->next->next != nullptr)
    tmp = tmp->next;
  tmp->next = nullptr;
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

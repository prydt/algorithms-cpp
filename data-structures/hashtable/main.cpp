
#include "HashTable.h"
#include <string>
#include <iostream>

int main()
{
  HashTable<std::string, int> tab;

  tab.insert("apple", 1);
  tab.insert("mango", 2);
  tab.insert("banana", 3);
  tab.insert("peach", 4);

  std::cout << "Before:\n";
  tab.printTable();

  tab.remove("apple");
  tab.remove("mango");

  std::cout << "\nAfter:\n";
  tab.printTable();
  return 0;
}

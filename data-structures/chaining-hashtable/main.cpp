
#include "HashTable.h"
#include <string>

int main()
{
  HashTable<std::string, int> tab(0);


  tab.insert("apple", 1);
  tab.insert("mango", 2);
  tab.insert("grape", 3);
  tab.insert("pear", 4);
  tab.insert("peach", 5);

  tab.printTable();
}

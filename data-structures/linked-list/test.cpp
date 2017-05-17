
#include "LinkedList.h"
#include <iostream>

/*
 * Output of this program:
 *
 * Length: 20 List: [ 0 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 ]
 * Length: 17 List: [ 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 ]
 * Get[2]: 4
 *
 */


int main()
{
  LinkedList list;
  
  for(int i = 0; i < 20; i++)
    list.append(i);

  std::cout << "Length: " << list.length() << " List: ";
  list.print();

  list.removeHead();
  list.removeHead();
  list.removeHead();

  std::cout << "Length: " << list.length() << " List: ";
  list.print();

  std::cout << "Get[2]: " << list[2] << '\n';

  return 0;
}

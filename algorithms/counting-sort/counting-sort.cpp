
#include <ctime> /* for seeding the rng */
#include <iostream>
#include <random> /* for the rng */

// counting sort only works for integers larger than or
// equal to zero
void countingSort(int[], int, int);

// helper function
void printArray(int[], int);

int main()
{
  std::mt19937 rng(time(0));
  int test[20];

  for(int i = 0; i < 20; i++)
    test[i] = rng() % 300;

  std::cout << "Before Sorting: ";
  printArray(test, 20);

  // sort
  countingSort(test, 20, 300);

  std::cout << "After Sorting: ";
  printArray(test, 20);

  return 0;
}

// A is the input array
// n is the size of the array
// k is the maximum size of any int
//   in the array
void countingSort(int A[], int n, int k)
{
  int* keys = new int[k]{0};

  for (int i = 0; i < n; i++) keys[A[i]]++;

  int next = 0;
  for (int i = 0; i < k; i++) {
    if (keys[i] > 0) {
      A[next] = i;
      keys[i]--;
      i--;
      next++;
    }
  }

  delete[] keys;
}

void printArray(int A[], int n)
{
  std::cout << "[ ";

  for(int i = 0; i < n; i++)
    std::cout << A[i] << ' ';

  std::cout << "]\n";
}


// IO functions
#include <iostream>

// time functions
#include <ctime>

// random function
#include <stdlib.h>

#define SIZE 1000

// star of the show...
// The Insertion Sort!
void insertionSort( int[], size_t ); 

// helper function
void printArray( int[], size_t );

int main()
{
  srand(time(0));

  int k[SIZE];

  for(int i = 0; i < SIZE; i++)
  {
    k[i] = rand() % 100;
  }

  std::cout << "Before: ";
  printArray(k, sizeof(k) / sizeof(int));

  insertionSort(k, sizeof(k) / sizeof(int));
  std::cout << "After: ";
  printArray(k, sizeof(k) / sizeof(int));

  return 0;
}

void insertionSort( int A[], size_t size )
{
  std::clock_t start = std::clock();
  for(int i = 0; i < (int) size; i++)
  {
    int j = i;
    while(j > 0 && A[j - 1] > A[j])
    {
      int tmp = A[j];
      A[j] = A[j - 1];
      A[j - 1] = tmp;

      j--;
    }
  }
  std::cout << "Insertion Sort finished in " << (std::clock() - start) / (double) (CLOCKS_PER_SEC / 1000) << " ms\n";
}

// helper function to print arrays
void printArray( int A[], size_t size )
{
  std::cout << "[";
  for(int i = 0; i < (int) size; i++)
  {
    std::cout << ' ' << A[i];
  }
  std::cout << " ]\n";
}

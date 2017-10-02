// IO functions
#include <iostream>
// Time functions
#include <ctime>
// Random function
#include <stdlib.h>

#define SIZE 1000

// The main sorting function
void heapSort( int[], size_t );
// Function to create and maintain heap
void heapify(int [], int, size_t);
// Output function
void printArray( int[], size_t);
// Helper function
void swap(int &, int &);

int main()
{
  // Randomize the clock
  srand(time(0));
  // Declare array to be sorted
  int k[SIZE];
  // Give random values to array elements
  for(int i = 0; i < SIZE; i++)
  {
    k[i] = rand() % 100;
  }
  // Output unsorted array
  std::cout << "Before: ";
  printArray(k, sizeof(k) / sizeof(int));

  // Start clock and sort array
  std::clock_t start = std::clock();
  heapSort(k, sizeof(k) / sizeof(int));
  std::cout << "Heap Sort finished in " << (std::clock() - start) / (double) (CLOCKS_PER_SEC / 1000) << " ms\n";

  // Output sorted array
  std::cout << "After: ";
  printArray(k, sizeof(k) / sizeof(int));

  return 0;
}

void heapSort( int A[], size_t size )
{
  // Turn array into a heap
  for(int i = size / 2 - 1; i >= 0; --i)
  {
    heapify(A, i, size);
  }
  // Remove elements then heapify
  for(int i = size - 1; i > 0; --i)
  {
    swap(A[i], A[0]);
    heapify(A, 0, i);
  }
}

void heapify(int A[], int ind, size_t size)
{
  // Child 1 and 2 of heap
  int c1 = 2 * ind + 1;
  int c2 = 2 * ind + 2;
  int large = ind;
  // Swap larger elements to top of heap
  if(c1 < size && A[c1] > A[large])
    large = c1;
  if(c2 < size && A[c2] > A[large])
    large = c2;
  if(large != ind)
  {
    swap(A[large], A[ind]);
    heapify(A, large, size);
  }
}

void swap(int &a, int &b)
{
  int t = a;
  a = b;
  b = t;
}

// helper function to print arrays
void printArray( int A[], size_t size)
{
  std::cout << "[";
  for(int i = 0; i < (int) size; i++)
  {
    std::cout << ' ' << A[i];
  }
  std::cout << " ]\n";
}

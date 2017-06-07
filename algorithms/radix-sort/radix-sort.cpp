
#include <cmath>     // for power function
#include <ctime>     // for time function
#include <iostream>  // for IO
#include <queue>     // for counting sort subroutine
#include <random>    // for testing

// sorts integers in linear time
void radixSort(int[], int, int);

// helper function to print arrays
void printArray(int[], int);

// just testing the radix sort
int main()
{
  std::mt19937 rng(time(0));
  std::uniform_int_distribution<int> dist(100, 999);

  int test[20];
  for (int i = 0; i < 20; i++) test[i] = dist(rng);

  std::cout << "Before Sort:\t";
  printArray(test, 20);

  radixSort(test, 20, 3);

  std::cout << "After Sort:\t";
  printArray(test, 20);

  return 0;
}

// a subroutine of radix sort...
//
// it is just a variation of counting sort for
// the specific digit of f
void sortByDigit(int A[], int d, int n, int f)
{
  std::queue<int> q[10];

  for (int i = 0; i < n; i++) {
    int num = (int)(A[i] / pow(10, f)) % 10;

    q[num].push(A[i]);
  }

  int next = 0;
  for (int i = 0; i < 10; i++) {
    if (!q[i].empty()) {
      A[next] = q[i].front();
      q[i].pop();

      next++;

      if (!q[i].empty()) i--;
    }
  }
}

void radixSort(int A[], int n, int d)
{
  for (int i = 0; i < d; i++) {
    sortByDigit(A, d, n, i);
  }
}

void printArray(int A[], int n)
{
  std::cout << "[ ";

  for (int i = 0; i < n; i++) std::cout << A[i] << ' ';

  std::cout << "]\n";
}

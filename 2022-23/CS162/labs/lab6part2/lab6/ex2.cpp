/*
 * This program should sort an array in a decreasing order using insertion sort,
 * but it's currently broken.  Use GDB and Valgrind to help debug it.
 */

#include <iostream>
#include <cstdlib>

using namespace std;

/*
 * This function swaps the values of two integers, using their memory addresses
 * (i.e. using pointers to those integers).
 */
void swap(int* a, int* b) {
  int tmp = *a;
  *a = *b;
  *b = tmp;
}

/*
 * This function implements insertion sort:
 *
 *   https://en.wikipedia.org/wiki/Insertion_sort
 *
 * Here, we specifically sort an array of integers by decreasing value (i.e.
 * the largest value should be at the front of the array after it's sorted).
 */
void insertion_sort(int* array, int n) {
  for (int i = 1; i < n; i++) {
    for (int j = i; j > 0; j--) { //removed = sign on j
      if (array[j-1] >= array[j]) {
        break;
      }
      swap(&array[j-1], &array[j]);
    }
  }
}

int main() {
  /*
   * Generate an array containing 16 random values between 0 and 100.
   */
  int n = 16;
  int* array = new int[n];
  for (int i = 0; i < n; i++) {
    array[i] = rand() % 100;
  }

  /*
   * Print the unsorted array.
   */
  cout << "The unsorted array values are: " << endl;;
  for (int i = 0; i < n; i++) {
    cout << array[i] << " ";
  }
  cout << endl << endl;

  /*
   * Sort the array and print it again.
   */
  insertion_sort(array, n);
  cout << "The sorted array values are: " << endl;;
  for (int i = 0; i < n; i++) {
    cout << array[i] << " ";
  }
  cout << endl << endl;

  return 0;
}

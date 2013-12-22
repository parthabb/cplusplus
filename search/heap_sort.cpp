// Heap Sort

#include <iostream>
#include <exception>

using namespace std;


// Print the array where the arr and size
// are passed.
void print_arr(int *arr, int size) {
  for (int i = 0; i < size; i++) {
    cout << arr[i] << '\t';
  }
  cout << endl;
}

// returns the index of the max value amongst
// the indexes passed along with the array in
// the array.
int max(int *arr, int p, int l, int r) {
  int max = p;
  try {
    if (arr[l] > arr[max]) {
      max = l;
    }
    if (arr[r] > arr[max]) {
      max = r;
    }
  } catch (exception& e) {
    cout << e.what() << endl;
  }
  return max;
}

// Swaps the parent with the max in the
// array.
void swap(int *arr, int p, int max) {
  if (p == max) {
    return;
  }
  int temp = arr[p];
  arr[p] = arr[max];
  arr[max] = temp;
}

// max heapifies the array where the index
// of the last element is passed.
void max_heapify(int *arr, int index) {
  if (index <= 0) {
    return;
  }
  int p = (index + 1) / 2; 
  int l = 2 * p - 1;
  int r = l + 1 > index ? -1 : l + 1;
  int m = max(arr, p - 1, l, r);
  swap(arr, p - 1, m);
  max_heapify(arr, 2 * p  == index ? index - 2 : index - 1);
}

// An implementation of heap sort with array
// and sized passed to it.
void heap_sort(int *arr, int size) {
  for (int i = size - 1; i > 0; i--) {
    max_heapify(arr, i);
    swap(arr, 0, i);
  }
  
}

int main() {
  int arr[] = {12, 2, 41, 45, 21, 14, 6, 91, 84, 2, 6};
  int size = sizeof(arr) / sizeof(int);
  print_arr(arr, size);
  heap_sort(arr, size);
  print_arr(arr, size);
  cout << arr[100] << endl;
}


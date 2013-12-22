// Code to build a heap both max and min.

#include <iostream>
#include <cstdlib>

#include "heap.h"

using namespace std;

Heap::Heap (int *a, int s) {
  heap = a;
  size = s;
}

void Heap::PrintHeap() {
  for (int i = 0; i < size; i++) {
    cout << heap[i] << '\t';
  }
  cout << endl;
}

void swap(int *arr, int x, int y) {
  int temp = arr[x];
  arr[x] = arr[y];
  arr[y] = temp;
}

void Heap::MaxHeapify(int s) {
  int left = s * 2;
  int right = s * 2 + 1;
  int max = s;
  if (left <= size && heap[left - 1] > heap[s - 1]) {
    max = left;
  }
  if (right <= size && heap[right - 1] > heap[max - 1]) {
    max = right;
  }
  if (max != s) {
    swap(heap, max - 1, s - 1);
    MaxHeapify(max);
  }
}

void Heap::MinHeapify(int s) {
  int left = s * 2;
  int right = s * 2 + 1;
  int min = s;
  if (left <= size && heap[left - 1] < heap[s - 1]) {
    min = left;
  }
  if (right <= size && heap[right - 1] < heap[min - 1]) {
    min = right;
  }
  if (min != s) {
    swap(heap, min - 1, s - 1);
    MinHeapify(min);
  }
}

void Heap::BuildMaxHeap() {
  for (int i = size / 2; i >= 1; i--) {
    MaxHeapify(i);
  }
}

void Heap::BuildMinHeap() {
  for (int i = size / 2; i >= 1; i--) {
    MinHeapify(i);
  }
}

void Heap::HeapSort() {
  BuildMaxHeap();
  int temp = size;
  for (int i = size; i > 1; i--) {
    swap(heap, 0, i - 1);
    size = size - 1;
    MaxHeapify(1);
  }
  size = temp;
}

void Heap::RevHeapSort() {
  BuildMinHeap();
  int temp = size;
  for (int i = size; i > 1; i--) {
    swap(heap, 0, i - 1);
    size = size - 1;
    MinHeapify(1);
  }
  size = temp;
}

/*
int main() {
  int size = 10;
  int *arr = new int[size];
  for (int i = 0; i < size; i++) {
    arr[i] = rand() % 100;
  }
  for (int i = 0; i < size; i++) {
    cout << arr[i] << '\t';
  }
  cout << endl;
  Heap *heap = new Heap(arr, size);
  heap->PrintHeap();
  heap->BuildMinHeap();
  heap->PrintHeap();
  heap->RevHeapSort();
  heap->PrintHeap();
}
*/

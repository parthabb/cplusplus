#include <iostream>
//#include "priority_queue.h"
#include "heap.h"

using namespace std;

class PriorityQueue : public Heap {
  private:
    bool isMaxPriorityQueue;
  public:
    PriorityQueue(int *, int, bool);
    int ReturnMaxOrMin();
    int ExtractMinOrMax();
    virtual void Insert(int) = 0;
    //void IncreaseKey(int, int);   
};

PriorityQueue :: PriorityQueue (int *arr, int size, bool impq=true) : Heap (arr, size)  {
  isMaxPriorityQueue = impq;
}

int PriorityQueue :: ReturnMaxOrMin() {
  return heap[0];
}

int PriorityQueue :: ExtractMinOrMax() {
  if (size < 1) {
    cout << "No elements to extract." << endl;
    return;
  }
  int value = heap[0];
  swap(heap, 0, size - 1);
  size = size - 1;
  isMaxPriorityQueue ? MaxHeapify(1) : MinHeapify(1);
  return value;
}

class MaxPriorityQueue : public PriorityQueue {
  public:
    MaxPriorityQueue (int *, int);
    void IncreaseKey (int, int);
    int GetMax() { return ReturnMaxOrMin(); }
    int ExtractMax() { return ExtractMinOrMax(); }
}

class MinPriorityQueue : public PriorityQueue {
  public:
    MinPriorityQueue (int *, int);
    void DecreaseKey (int, int);
    int GetMin() { return ReturnMaxOrMin(); }
    int ExtraxtMin() { return ExtractMinOrMax(); }
}

MaxPrioirityQueue :: MaxPriorityQueue (int *arr, int size) : PriorityQueue(arr, size) {
}

void MaxPriorityQueue :: IncreaseKey(int index, int key) {
  if (heap[index] > key) {
    cout << "Value of key violates new key rule." << endl;
    return;
  }
  while (index > 0 && A[(index + 1) * 2] < A[index]) {
    parent = ((index + 1) * 2);
    swap(heap, index, parent);
    index = parent;
  }
}

void MaxPriorityQueue :: Insert (int key) {
  size = size + 1;
  A[size - 1] = key - 1;
  IncreaseKey(size - 1, key);
}

MinPrioirityQueue :: MinPriorityQueue (int *arr, int size) : PriorityQueue(arr, size, false) {
}

void MinPriorityQueue :: DecreaseKey(int index, int key) {
  if (heap[index] < key) {
    cout << "Value of key violates new key rule." << endl;
    return;
  }
  while (index > 0 && A[(index + 1) / 2] > A[index]) {
    parent = ((index + 1) / 2);
    swap(heap, index, parent);
    index = parent;
  }
}

void MinPriorityQueue :: Insert (int key) {
  size = size + 1;
  A[size - 1] = key + 1;
  DecreaseKey(size - 1, key);
}


int main () {
  int size = 10;
  int *arr = new int[size];
  int *brr = new int[size]
  for (int i = 0; i < size; i++) {
    arr[i] = rand() % 100;
    brr[i] = rand() % 100;
  }
  for (int i = 0; i < size; i++) {
    cout << arr[i] << '\t';
  }
  cout << endl;
  for (int i = 0; i < size; i++) {
    cout << brr[i] << '\t';
  }
  cout << endl;
  MaxPriorityQueue *mxpq = new MaxPriorityQueue(arr, size);
  MinPriorityQueue *mnpq = new MinPriorityQueue(brr, size);

  mxpq->PrintHeap();
  mnpq->PrintHeap();

  cout << mxpq->GetMax() << endl;
  cout << mxpq->GetMin() << endl;

  cout << mxpq->ExtractMax(); << endl;
  cout << mnpq->ExtractMin(); << endl;
  
  mxpq->PrintHeap();
  mnpq->PrintHeap();
}

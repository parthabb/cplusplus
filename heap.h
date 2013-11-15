// Header file for heap.

class Heap {
  protected:
    int size, *heap;
  public:
    Heap(int *, int);
    void MaxHeapify(int);
    void BuildMaxHeap();
    void MinHeapify(int);
    void BuildMinHeap();
    void HeapSort();
    void RevHeapSort();
    void PrintHeap();
};


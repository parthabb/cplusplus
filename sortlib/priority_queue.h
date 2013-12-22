// Header file for priority queue.

#include "heap.h"

class PriorityQueue : public Heap {
  public:
    PriorityQueue();
    int ReturnMaxOrMin();
    int ExtractMinOrMax();
    void Insert();
    void IncreaseKey();   
};



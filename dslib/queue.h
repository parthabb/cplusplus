// Header file for queue.cpp

#ifndef QUEUE_H_
#define QUEUE_H_

template <class T>
class Queue {
  private:
    LinkedList <T> * ll;
  public: 
    Queue (); 
    void enqueue (T);
    T dequeue ();
};
#endif

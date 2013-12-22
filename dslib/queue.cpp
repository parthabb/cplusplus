// File implementing Queue ADT using linked list.

#include <iostream>

#include "node.h"
#include "node_impl.h"
#include "linkedlist.h"
#include "linkedlist_impl.h"
#include "queue.h"

using namespace std;


template <class T>
Queue <T> :: Queue () {
  ll = new LinkedList <T> ();
}

template <class T>
void Queue <T> :: enqueue (T t) {
  ll->insertAtEnd (t);
}

template <class T>
T Queue <T> :: dequeue () {
  T val = ll->getValueByIndex (0);
  if (val == (T) -1) {
    cout << "Queue empty." << endl;
  } else {
    cout << "Dequeuing: " << val << endl;
    ll->del (val);
  }
  return val;
}

int main () {
  Queue <int>  * s = new Queue <int> ();
  s->enqueue (1);
  s->enqueue (2);
  s->enqueue (3);
  s->dequeue ();
  s->dequeue ();
  s->dequeue ();
  s->dequeue ();
}

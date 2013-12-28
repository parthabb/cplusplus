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
    ll->deleteByValue (val);
  }
  return val;
}

template <class T>
bool Queue <T> :: isEmpty () const {
  return ll->getLength () == 0;
}


// Header file for implementing Queue ADT using linked list.

#ifndef QUEUE_IMPL_H_
#define QUEUE_IMPL_H_

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
    ll->del (val);
  }
  return val;
}

template <class T>
bool Queue <T> :: isEmpty () const {
  return ll->getLength () == 0;
}
#endif

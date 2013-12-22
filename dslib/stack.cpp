// File implementing Stack ADT using linked list.

#include <iostream>

#include "node.h"
#include "node_impl.h"
#include "linkedlist.h"
#include "linkedlist_impl.h"
#include "stack.h"

using namespace std;


template <class T>
Stack <T> :: Stack () {
  ll = new LinkedList <T> ();
}

template <class T>
void Stack <T> :: push (T t) {
  ll->insertAtStart (t);
}

template <class T>
T Stack <T> :: pop () {
  T val = ll->getValueByIndex (0);
  if (val == (T) -1) {
    cout << "Stack empty." << endl;
  } else {
    cout << "Popping: " << val << endl;
    ll->del (val);
  }
  return val;
}

int main () {
  Stack <int>  * s = new Stack <int> ();
  s->push (1);
  s->push (2);
  s->push (3);
  s->pop ();
  s->pop ();
  s->pop ();
  s->pop ();
}

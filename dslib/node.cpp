// File implementing node data structure.

#include <iostream>
#include "node.h"

using namespace std;


template <class T>
Node <T> :: Node () : data (T()), f_ptr (NULL), b_ptr (NULL) {
}

template <class T>
T Node <T> :: getData () const {
  return data;
}

template <class T>
void Node <T> :: setData (T a) {
  data = a;
}

template <class T>
Node <T> * Node <T> :: getF_ptr () const {
  return f_ptr;
}

template <class T>
void Node <T> :: setF_ptr (Node <T> * a) {
  f_ptr = a;
}

template <class T>
Node <T> * Node <T> :: getB_ptr () const {
  return b_ptr;
}

template <class T>
void Node <T> :: setB_ptr (Node <T> * a) {
  b_ptr = a;
}

/*
int main () {
  Node <int> * node = new Node <int> ();
  node->setData (12);
  cout << node->getData () << endl;
  node->setF_ptr (NULL);
  node->setB_ptr (NULL);
}
*/

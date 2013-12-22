//  File implementing linked list data structure.

#include <iostream>

#include "node.h"
#include "node_impl.h"
#include "dll.h"

using namespace std;


template <class T>
DoubleLinkedList <T> :: DoubleLinkedList () : length (0), head (NULL), tail (NULL) {
}

template <class T>
void DoubleLinkedList <T> :: printFront () {
  Node <T> * itr = head;
  while (itr != NULL) {
    cout << itr->getData () << '\t';
    itr = itr->getF_ptr ();
  }
  cout << endl;
}

template <class T>
void DoubleLinkedList <T> :: printBack () {
  Node <T> * itr = tail;
  while (itr != NULL) {
    cout << itr->getData () << '\t';
    itr = itr->getB_ptr ();
  }
  cout << endl;
}

template <class T>
void DoubleLinkedList <T> :: insert (T t, int index) {
  if (index < 0 || index > this->length) {
    // Raise an exception later.
    cout << "Index " << index << " out of bounds." << endl;
    return;
  }
  Node <T> * itr = head;
  Node <T> * node = new Node <T> ();
  node->setData (t);

  for (int i = 0; i < index - 1; i++) {
    itr = itr->getF_ptr ();
  }
  switch (index) {
    case 0: node->setF_ptr (itr);
            if (itr != NULL) {
              itr->setB_ptr (node);
            }
            head = node;
            break;
    default: node->setF_ptr (itr->getF_ptr ());
             node->setB_ptr (itr);
             if (itr->getF_ptr () != NULL) {
               (itr->getF_ptr ())->setB_ptr (node);
             }
             itr->setF_ptr (node);
             break;
  }
  if (index == length) {
    tail = node;
  }

  length ++;
}

template <class T>
void DoubleLinkedList <T> :: insertAtStart (T t) {
  this->insert (t, 0);
}

template <class T>
void DoubleLinkedList <T> :: insertAtEnd (T t) {
  this->insert (t, this->length);
}

template <class T>
void DoubleLinkedList <T> :: del (T t) {
  Node <T> * itr = head;
  Node <T> * prev = head;
  while (itr != NULL && itr->getData () != t) {
    prev = itr;
    itr = itr->getF_ptr ();
  }
  if (itr == NULL) {
    cout << "Item not found." << endl;
    return;
  }
  if (prev == itr) {
    head = itr->getF_ptr ();
    if (itr->getF_ptr () != NULL) {
      (itr->getF_ptr ())->setB_ptr (NULL);
    }
  } else {
    prev->setF_ptr (itr->getF_ptr ());
    if (itr->getF_ptr () != NULL) {
      (itr->getF_ptr ())->setB_ptr (prev);
    }
  }
  if (itr->getF_ptr() == NULL) {
    tail = prev;
  }

  length --;
  if (length != 0) {
    delete itr;
  }
}

template <class T>
void DoubleLinkedList <T> :: getIndexByValue (T t) {
  Node <T> * itr = head;
  int index = 0;
  while (itr != NULL && itr->getData () != t) {
    index ++;
    itr = itr->getF_ptr ();
  }
  if (itr == NULL) {
    cout << "Item not found." << endl;
    return;
  }
  cout << "Object found at index: " << index << endl;
}

template <class T>
void DoubleLinkedList <T> :: getValueByIndex (int index) {
  if (index < 0 || index > this->length - 1) {
    cout << "Index " << index << " out of bounds." << endl;
    return;
  }
  Node <T> * itr = head;
  for (int i = 0; i < index; i++ ) {
    itr = itr->getF_ptr ();
  }
  cout << "Object at index " << index << " is: " <<  itr->getData () << endl;
}


int main () {
  DoubleLinkedList <int> * dll = new DoubleLinkedList <int> ();
  dll->printFront ();
  dll->printBack ();
  dll->insertAtStart (12);
  dll->insertAtEnd (16);
  dll->insertAtEnd (2);
  dll->insertAtStart (100);
  dll->insert (200, 1);
  dll->insert (300, 2);
  dll->insertAtEnd (400);
  dll->printFront ();
  dll->printBack ();
  dll->del (16);
  dll->printFront ();
  dll->printBack ();
  dll->del (2);
  dll->printFront ();
  dll->printBack ();
  dll->del (12);
  dll->printFront ();
  dll->printBack ();
  dll->insert (100, 1);
  dll->insertAtStart (200);
  dll->insert (300, 2);
  dll->printFront ();
  dll->printBack ();
  dll->getValueByIndex (0);
  dll->getValueByIndex (100000);
  dll->getIndexByValue (10000);
  dll->getIndexByValue (200);
}
